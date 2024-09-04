# Multistage docker build, requires docker 17.05

# builder stage
FROM ubuntu:20.04 as builder

RUN set -ex && \
    apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get --no-install-recommends --yes install \
        automake \
        autotools-dev \
        bsdmainutils \
        build-essential \
        ca-certificates \
        ccache \
        cmake \
        curl \
        git \
        libtool \
        pkg-config \
        gperf

WORKDIR /src
COPY . .

ARG NPROC
RUN set -ex && \
    git submodule init && git submodule update && \
    rm -rf build && \
    if [ -z "$NPROC" ] ; \
    then make -j$(nproc) depends target=x86_64-linux-gnu ; \
    else make -j$NPROC depends target=x86_64-linux-gnu ; \
    fi

# runtime stage
FROM ubuntu:20.04

RUN set -ex && \
    apt-get update && \
    apt-get --no-install-recommends --yes install ca-certificates && \
    apt-get clean && \
    rm -rf /var/lib/apt
COPY --from=builder /src/build/x86_64-linux-gnu/release/bin /usr/local/bin/

# Create lunexa user
RUN adduser --system --group --disabled-password lunexa && \
	mkdir -p /wallet /home/lunexa/.lunexa && \
	chown -R lunexa:lunexa /home/lunexa/.lunexa && \
	chown -R lunexa:lunexa /wallet

# Contains the blockchain
VOLUME /home/lunexa/.lunexa

# Generate your wallet via accessing the container and run:
# cd /wallet
# lunexa-wallet-cli
VOLUME /wallet

EXPOSE 18080
EXPOSE 18081

# switch to user lunexa
USER lunexa

ENTRYPOINT ["lunexad"]
CMD ["--p2p-bind-ip=0.0.0.0", "--p2p-bind-port=9028", "--rpc-bind-ip=0.0.0.0", "--rpc-bind-port=9029", "--non-interactive", "--confirm-external-bind"]

