#!/usr/bin/env bash
# Copyright (c) 2024 Lunexa Developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
export LC_ALL=C
set -e -o pipefail
export TZ=UTC

# Set umask for file creation permissions
umask 0022

if [ -n "$V" ]; then
    set -vx
    export VERBOSE="$V"
fi

# Check that required environment variables are set
cat << EOF
Required environment variables as seen inside the container:
    UNSIGNED_TARBALL: ${UNSIGNED_TARBALL:?not set}
    DETACHED_SIGS_REPO: ${DETACHED_SIGS_REPO:?not set}
    DIST_ARCHIVE_BASE: ${DIST_ARCHIVE_BASE:?not set}
    DISTNAME: ${DISTNAME:?not set}
    HOST: ${HOST:?not set}
    SOURCE_DATE_EPOCH: ${SOURCE_DATE_EPOCH:?not set}
    DISTSRC: ${DISTSRC:?not set}
    OUTDIR: ${OUTDIR:?not set}
EOF

ACTUAL_OUTDIR="${OUTDIR}"
OUTDIR="${DISTSRC}/output"

git_head_version() {
    local recent_tag
    if recent_tag="$(git -C "$1" describe --exact-match HEAD 2> /dev/null)"; then
        echo "${recent_tag#v}"
    else
        git -C "$1" rev-parse --short=12 HEAD
    fi
}

CODESIGNATURE_GIT_ARCHIVE="${DIST_ARCHIVE_BASE}/${DISTNAME}-codesignatures-$(git_head_version "$DETACHED_SIGS_REPO").tar.gz"

# Create the codesignature tarball if not already there
if [ ! -e "$CODESIGNATURE_GIT_ARCHIVE" ]; then
    mkdir -p "$(dirname "$CODESIGNATURE_GIT_ARCHIVE")"
    git -C "$DETACHED_SIGS_REPO" archive --output="$CODESIGNATURE_GIT_ARCHIVE" HEAD
fi

mkdir -p "$OUTDIR"

mkdir -p "$DISTSRC"
(
    cd "$DISTSRC"

    tar -xf "$UNSIGNED_TARBALL"

    mkdir -p codesignatures
    tar -C codesignatures -xf "$CODESIGNATURE_GIT_ARCHIVE"

    case "$HOST" in
        *mingw*)
            find "$PWD" -name "*-unsigned.exe" | while read -r infile; do
                infile_base="$(basename "$infile")"

                # Codesigned *-unsigned.exe and output to OUTDIR
                osslsigncode attach-signature \
                                 -in "$infile" \
                                 -out "${OUTDIR}/${infile_base/-unsigned}" \
                                 -CAfile "$GUIX_ENVIRONMENT/etc/ssl/certs/ca-certificates.crt" \
                                 -sigin codesignatures/win/"$infile_base".pem
            done
            ;;
        *darwin*)
            # Apply detached codesignatures to dist/ (in-place)
            signapple apply dist/Lunexa-Qt.app codesignatures/osx/dist

            # Make a .zip from dist/
            cd dist/
            find . -print0 \
                | xargs -0r touch --no-dereference --date="@${SOURCE_DATE_EPOCH}"
            find . | sort \
                | zip -X@ "${OUTDIR}/${DISTNAME}-${HOST}.zip"
            ;;
        *)
            exit 1
            ;;
    esac
)  # $DISTSRC

rm -rf "$ACTUAL_OUTDIR"
mv --no-target-directory "$OUTDIR" "$ACTUAL_OUTDIR" \
    || ( rm -rf "$ACTUAL_OUTDIR" && exit 1 )

(
    cd /outdir-base
    {
        echo "$UNSIGNED_TARBALL"
        echo "$CODESIGNATURE_GIT_ARCHIVE"
        find "$ACTUAL_OUTDIR" -type f
    } | xargs realpath --relative-base="$PWD" \
        | xargs sha256sum \
        | sort -k2 \
        | sponge "$ACTUAL_OUTDIR"/SHA256SUMS.part
)
