# Lunexa

Copyright (c) 2014-2023, The Monero Project
Portions Copyright (c) 2012-2013 The Cryptonote developers.

## Table of Contents

  - [Development resources](#development-resources)
  - [Vulnerability response](#vulnerability-response)
  - [Research](#research)
  - [Announcements](#announcements)
  - [Introduction](#introduction)
  - [About this project](#about-this-project)
  - [Supporting the project](#supporting-the-project)
  - [License](#license)
  - [Contributing](#contributing)
  - [Scheduled software upgrades](#scheduled-software-upgrades)
  - [Release staging schedule and protocol](#release-staging-schedule-and-protocol)
  - [Compiling lunexa from source](#compiling-lunexa-from-source)
    - [Dependencies](#dependencies)
    - [GUIX builds](#GUIX-builds)
  - [Internationalization](#Internationalization)
  - [Using Tor](#using-tor)
  - [Pruning](#Pruning)
  - [Debugging](#Debugging)
  - [Known issues](#known-issues)

## IMPORTANT!!!

I wanted to update anyone who reads this on the development of Lunexa. We are currently working on improvements to make the platform more stable after the issues encountered during the previous launch. I acknowledge that it wasn't a great launch, and I'm dedicated to addressing the problems, including syncing and transaction issues.

I'm working on Lunexa in my spare time as I manage other responsibilities in life. My goal is to ensure that version Alpha-v0.2.0 is stable and ready for the next relaunch and testing. I appreciate the ongoing support from everyone and hope you'll continue to back this project.

Thank you!


## Development resources

- Web: [Lunexa.co](https://Lunexa.co)
- GitHub: [https://github.com/lunexa-project/lunexa](https://github.com/lunexa-project/lunexa)
- Discord: (i currently have taken down the discord for now)


## Vulnerability response

Please report any vulnerabilitiy to the Discord

## Research

Lunexa is an independent project, establishing its own unique ecosystem while drawing inspiration from Monero's cryptography, protocols, fungibility, analysis, and more. Our community is dedicated to coordinating research, fostering collaboration, and inviting contributions from researchers and enthusiasts worldwide. While our roots lie in Monero, Lunexa stands as a separate entity, developing its innovative solutions and advancing the field.

As the Lunexa community explores various aspects of cryptography, protocols, and analysis, we encourage engagement and interaction with researchers outside our ecosystem. Collaboration is key to our progress. We invite those interested to connect with us, whether for inquiries, collaborative opportunities, or seeking guidance to avoid redundant efforts.

While the Monero research community remains a valuable resource, Lunexa's ecosystem thrives on separate platforms. You can find us on Discord (i currently have taken down the discord for now) and on other accessible channels.

Join us in shaping the future of Lunexa's ecosystem, where innovation and collaboration pave the way for new advancements in the realm of cryptocurrencies.

## Announcements

- You can head to our discord [Lunexa's Discord]() to get critical announcements from the core team and also talk to the people in our community. The announcement list can be very helpful for knowing when software updates are needed.

## Introduction

Lunexa is a decentralized digital currency based on monero designed for privacy, security, and untraceability. With Lunexa, you are your bank—having full control over your funds, ensuring that your transfers remain untraceable unless you choose otherwise

**Privacy**: Lunexa ensures privacy by employing robust cryptographic techniques that shield your transactions from easy identification on the blockchain. By default, all transfers, purchases, and receipts are kept private, safeguarding your financial activities.

**Security**: Leveraging a distributed peer-to-peer consensus network, Lunexa guarantees cryptographic security for every transaction. Each wallet is associated with a 25-word mnemonic seed, presented only once and crucial for wallet backup. Encrypting wallet files with a strong passphrase enhances security, rendering them useless if stolen.

**Untraceability**: Lunexa employs ring signatures, a unique cryptographic feature, to ensure transactions remain untraceable. Additionally, it incorporates optional measures of ambiguity, preventing easy linkage of transactions to individual users or devices.

**Decentralization**: Lunexa's functionality relies on its decentralized peer-to-peer consensus network. The aim is for anyone to run Lunexa software, validate the blockchain's integrity, and engage fully using standard consumer-grade hardware. Sustaining Lunexa's network decentralization involves software development that reduces the costs of running the software and discourages the use of specialized, non-standard hardware.

## About this project
Lunexa constitutes the fundamental implementation of our digital currency system. It's an open-source platform, entirely free to utilize without constraints, except as specified in the accompanying license agreement. The ecosystem welcomes alternative implementations that align with the protocol and network in a compatible manner.

Similar to various development endeavors, our GitHub repository serves as the staging ground for the latest developments. Changes undergo rigorous testing by individual developers in their respective branches before being submitted as pull requests. These submissions then undergo further testing and code reviews by dedicated contributors. While our repository is constantly evolving, caution is advised when considering its use in a production environment. Opt for a tagged release for enhanced stability, unless a specific patch addresses a critical issue.

**We invite contributions from everyone to enhance Lunexa's codebase!** If you've developed a fix or code modification, don't hesitate to submit it as a pull request directly to the "master" branch. Small changes or those isolated to specific sections may be promptly merged by any collaborator. However, larger or intricate alterations are typically subject to extensive discussion, either well in advance of the pull request or directly within it. Collaboration and collective input drive the evolution of Lunexa's codebase.

## Supporting the project

Lunexa thrives through the support of our community. If you wish to contribute, one of the simplest ways is by providing financial support. You can donate using Monero or Bitcoin by visiting donate.lunexa.org through a client that supports the OpenAlias standard. Alternatively, use the donate command within the command-line wallet and follow the instructions (type help in the wallet for guidance)

Donations

Ethereum Donations: 


## License

See [LICENSE](LICENSE).

## Contributing

If you want to help out, see [CONTRIBUTING](docs/CONTRIBUTING.md) for a set of guidelines.

## Scheduled software/network upgrades

Lunexa's development roadmap includes scheduled software and network upgrades (hard forks) to introduce new features and enhancements to the Lunexa software and network. To ensure optimal performance and compatibility, it's recommended that users, including end-users and service providers, update to the latest software versions as they become available.

These software upgrades will encompass the development and implementation of new features within the codebase. Simultaneously, network upgrades, modifying the consensus rules of the Lunexa network, will accompany these software updates. Prior to the scheduled network upgrade date, the necessary software will be provided in the repository, allowing users to prepare accordingly.

As of now, specific dates and versions for these upgrades are not finalized. Please stay updated by monitoring the repository for the upcoming Lunexa software versions and associated upgrade details.

## Compiling Lunexa from source

### Dependencies

The following table summarizes the tools and libraries required to build. A
few of the libraries are also included in this repository (marked as
"Vendored"). By default, the build uses the library installed on the system
and ignores the vendored sources. However, if no library is found installed on
the system, then the vendored source will be built and used. The vendored
sources are also used for statically-linked builds because distribution
packages often include only shared library binaries (`.so`) but not static
library archives (`.a`).

| Dep          | Min. version  | Vendored | Debian/Ubuntu pkg    | Arch pkg     | Void pkg           | Fedora pkg          | Optional | Purpose         |
| ------------ | ------------- | -------- | -------------------- | ------------ | ------------------ | ------------------- | -------- | --------------- |
| GCC          | 7             | NO       | `build-essential`    | `base-devel` | `base-devel`       | `gcc`               | NO       |                 |
| CMake        | 3.5           | NO       | `cmake`              | `cmake`      | `cmake`            | `cmake`             | NO       |                 |
| pkg-config   | any           | NO       | `pkg-config`         | `base-devel` | `base-devel`       | `pkgconf`           | NO       |                 |
| Boost        | 1.58          | NO       | `libboost-all-dev`   | `boost`      | `boost-devel`      | `boost-devel`       | NO       | C++ libraries   |
| OpenSSL      | basically any | NO       | `libssl-dev`         | `openssl`    | `openssl-devel`    | `openssl-devel`     | NO       | sha256 sum      |
| libzmq       | 4.2.0         | NO       | `libzmq3-dev`        | `zeromq`     | `zeromq-devel`     | `zeromq-devel`      | NO       | ZeroMQ library  |
| OpenPGM      | ?             | NO       | `libpgm-dev`         | `libpgm`     |                    | `openpgm-devel`     | NO       | For ZeroMQ      |
| libnorm[2]   | ?             | NO       | `libnorm-dev`        |              |                    |                     | YES      | For ZeroMQ      |
| libunbound   | 1.4.16        | NO       | `libunbound-dev`     | `unbound`    | `unbound-devel`    | `unbound-devel`     | NO       | DNS resolver    |
| libsodium    | ?             | NO       | `libsodium-dev`      | `libsodium`  | `libsodium-devel`  | `libsodium-devel`   | NO       | cryptography    |
| libunwind    | any           | NO       | `libunwind8-dev`     | `libunwind`  | `libunwind-devel`  | `libunwind-devel`   | YES      | Stack traces    |
| liblzma      | any           | NO       | `liblzma-dev`        | `xz`         | `liblzma-devel`    | `xz-devel`          | YES      | For libunwind   |
| libreadline  | 6.3.0         | NO       | `libreadline6-dev`   | `readline`   | `readline-devel`   | `readline-devel`    | YES      | Input editing   |
| expat        | 1.1           | NO       | `libexpat1-dev`      | `expat`      | `expat-devel`      | `expat-devel`       | YES      | XML parsing     |
| GTest        | 1.5           | YES      | `libgtest-dev`[1]    | `gtest`      | `gtest-devel`      | `gtest-devel`       | YES      | Test suite      |
| ccache       | any           | NO       | `ccache`             | `ccache`     | `ccache`           | `ccache`            | YES      | Compil. cache   |
| Doxygen      | any           | NO       | `doxygen`            | `doxygen`    | `doxygen`          | `doxygen`           | YES      | Documentation   |
| Graphviz     | any           | NO       | `graphviz`           | `graphviz`   | `graphviz`         | `graphviz`          | YES      | Documentation   |
| lrelease     | ?             | NO       | `qttools5-dev-tools` | `qt5-tools`  | `qt5-tools`        | `qt5-linguist`      | YES      | Translations    |
| libhidapi    | ?             | NO       | `libhidapi-dev`      | `hidapi`     | `hidapi-devel`     | `hidapi-devel`      | YES      | Hardware wallet |
| libusb       | ?             | NO       | `libusb-1.0-0-dev`   | `libusb`     | `libusb-devel`     | `libusbx-devel`     | YES      | Hardware wallet |
| libprotobuf  | ?             | NO       | `libprotobuf-dev`    | `protobuf`   | `protobuf-devel`   | `protobuf-devel`    | YES      | Hardware wallet |
| protoc       | ?             | NO       | `protobuf-compiler`  | `protobuf`   | `protobuf`         | `protobuf-compiler` | YES      | Hardware wallet |
| libudev      | ?             | NO       | `libudev-dev`        | `systemd`    | `eudev-libudev-devel` | `systemd-devel`  | YES      | Hardware wallet |

[1] On Debian/Ubuntu `libgtest-dev` only includes sources and headers. You must
build the library binary manually. This can be done with the following command `sudo apt-get install libgtest-dev && cd /usr/src/gtest && sudo cmake . && sudo make`
then:

* on Debian:
  `sudo mv libg* /usr/lib/`
* on Ubuntu:
  `sudo mv lib/libg* /usr/lib/`

[2] libnorm-dev is needed if your zmq library was built with libnorm, and not needed otherwise

Install all dependencies at once on Debian/Ubuntu:

```
sudo apt update && sudo apt install build-essential cmake pkg-config libssl-dev libzmq3-dev libunbound-dev libsodium-dev libunwind8-dev liblzma-dev libreadline6-dev libexpat1-dev libpgm-dev qttools5-dev-tools libhidapi-dev libusb-1.0-0-dev libprotobuf-dev protobuf-compiler libudev-dev libboost-chrono-dev libboost-date-time-dev libboost-filesystem-dev libboost-locale-dev libboost-program-options-dev libboost-regex-dev libboost-serialization-dev libboost-system-dev libboost-thread-dev python3 ccache doxygen graphviz
```

Install all dependencies at once on Arch:
```
sudo pacman -Syu --needed base-devel cmake boost openssl zeromq libpgm unbound libsodium libunwind xz readline expat gtest python3 ccache doxygen graphviz qt5-tools hidapi libusb protobuf systemd
```

Install all dependencies at once on Fedora:
```
sudo dnf install gcc gcc-c++ cmake pkgconf boost-devel openssl-devel zeromq-devel openpgm-devel unbound-devel libsodium-devel libunwind-devel xz-devel readline-devel expat-devel gtest-devel ccache doxygen graphviz qt5-linguist hidapi-devel libusbx-devel protobuf-devel protobuf-compiler systemd-devel
```

Install all dependencies at once on openSUSE:

```
sudo zypper ref && sudo zypper in cppzmq-devel libboost_chrono-devel libboost_date_time-devel libboost_filesystem-devel libboost_locale-devel libboost_program_options-devel libboost_regex-devel libboost_serialization-devel libboost_system-devel libboost_thread-devel libexpat-devel libminiupnpc-devel libsodium-devel libunwind-devel unbound-devel cmake doxygen ccache fdupes gcc-c++ libevent-devel libopenssl-devel pkgconf-pkg-config readline-devel xz-devel libqt5-qttools-devel patterns-devel-C-C++-devel_C_C++
```

Install all dependencies at once on macOS with the provided Brewfile:

```
brew update && brew bundle --file=contrib/brew/Brewfile
```

FreeBSD 12.1 one-liner required to build dependencies:

```
pkg install git gmake cmake pkgconf boost-libs libzmq4 libsodium unbound
```

### Cloning the repository

Clone recursively to pull-in needed submodule(s):

```
git clone --recursive https://github.com/lunexa-project/lunexa
```

If you already have a repo cloned, initialize and update:

```
cd lunexa && git submodule init && git submodule update
```

*Note*: If there are submodule differences between branches, you may need 
to use `git submodule sync && git submodule update` after changing branches
to build successfully.

### Build instructions

Lunexa uses the CMake build system and a top-level [Makefile](Makefile) that
invokes cmake commands as needed.

#### On Linux and macOS

* Install the dependencies
* Change to the root of the source code directory, change to the most recent release branch, and build:

    ```bash
    cd lunexa
    git checkout master
    make
    ```

    *Optional*: If your machine has several cores and enough memory, enable
    parallel build by running `make -j<number of threads>` instead of `make`. For
    this to be worthwhile, the machine should have one core and about 2GB of RAM
    available per thread.

* The resulting executables can be found in `build/release/bin`

* Add `PATH="$PATH:$HOME/lunexa/build/release/bin"` to `.profile`

* Run Lunexa with `lunexad --detach`

* **Optional**: build and run the test suite to verify the binaries:

    ```bash
    make release-test
    ```

    *NOTE*: `core_tests` test may take a few hours to complete.

* **Optional**: to build binaries suitable for debugging:

    ```bash
    make debug
    ```

* **Optional**: to build statically-linked binaries:

    ```bash
    make release-static
    ```

Dependencies need to be built with -fPIC. Static libraries usually aren't, so you may have to build them yourself with -fPIC. Refer to their documentation for how to build them.

* **Optional**: build documentation in `doc/html` (omit `HAVE_DOT=YES` if `graphviz` is not installed):

    ```bash
    HAVE_DOT=YES doxygen Doxyfile
    ```

* **Optional**: use ccache not to rebuild translation units, that haven't really changed. Lunexa's CMakeLists.txt file automatically handles it

    ```bash
    sudo apt install ccache
    ```

#### On the Raspberry Pi

Tested on a Raspberry Pi Zero with a clean install of minimal Raspbian Stretch (2017-09-07 or later) from https://www.raspberrypi.org/downloads/raspbian/. If you are using Raspian Jessie, [please see note in the following section](#note-for-raspbian-jessie-users).

* `apt-get update && apt-get upgrade` to install all of the latest software

* Install the dependencies for Lunexa from the 'Debian' column in the table above.

* Increase the system swap size:

    ```bash
    sudo /etc/init.d/dphys-swapfile stop  
    sudo nano /etc/dphys-swapfile  
    CONF_SWAPSIZE=2048
    sudo /etc/init.d/dphys-swapfile start
    ```

* If using an external hard disk without an external power supply, ensure it gets enough power to avoid hardware issues when syncing, by adding the line "max_usb_current=1" to /boot/config.txt

* Clone Lunexa and checkout the most recent release version:

    ```bash
    git clone https://github.com/lunexa-project/lunexa.git
    cd lunexa
    git checkout master
    ```

* Build:

    ```bash
    USE_SINGLE_BUILDDIR=1 make release
    ```

* Wait 4-6 hours

* The resulting executables can be found in `build/release/bin`

* Add `export PATH="$PATH:$HOME/lunexa/build/release/bin"` to `$HOME/.profile`

* Run `source $HOME/.profile`

* Run Lunexa with `lunexad --detach`

* You may wish to reduce the size of the swap file after the build has finished, and delete the boost directory from your home directory

#### *Note for Raspbian Jessie users:*

If you are using the older Raspbian Jessie image, compiling Lunexa is a bit more complicated. The version of Boost available in the Debian Jessie repositories is too old to use with Lunexa, and thus you must compile a newer version yourself. The following explains the extra steps and has been tested on a Raspberry Pi 2 with a clean install of minimal Raspbian Jessie.

* As before, `apt-get update && apt-get upgrade` to install all of the latest software, and increase the system swap size

    ```bash
    sudo /etc/init.d/dphys-swapfile stop
    sudo nano /etc/dphys-swapfile
    CONF_SWAPSIZE=2048
    sudo /etc/init.d/dphys-swapfile start
    ```


* Then, install the dependencies for Lunexa except for `libunwind` and `libboost-all-dev`

* Install the latest version of boost (this may first require invoking `apt-get remove --purge libboost*-dev` to remove a previous version if you're not using a clean install):

    ```bash
    cd
    wget https://sourceforge.net/projects/boost/files/boost/1.72.0/boost_1_72_0.tar.bz2
    tar xvfo boost_1_72_0.tar.bz2
    cd boost_1_72_0
    ./bootstrap.sh
    sudo ./b2
    ```

* Wait ~8 hours

    ```bash    
    sudo ./bjam cxxflags=-fPIC cflags=-fPIC -a install
    ```

* Wait ~4 hours

* From here, follow the [general Raspberry Pi instructions](#on-the-raspberry-pi) from the "Clone Lunexa and checkout the latest" step.

#### On Windows:

Binaries for Windows are built on Windows using the MinGW toolchain within
[MSYS2 environment](https://www.msys2.org). The MSYS2 environment emulates a
POSIX system. The toolchain runs within the environment and *cross-compiles*
binaries that can run outside of the environment as a regular Windows
application.

**Preparing the build environment**

* Download and install the [MSYS2 installer](https://www.msys2.org), either the 64-bit or the 32-bit package, depending on your system.
* Open the MSYS shell via the `MSYS2 Shell` shortcut
* Update packages using pacman:

    ```bash
    pacman -Syu
    ```

* Exit the MSYS shell using Alt+F4
* Edit the properties for the `MSYS2 Shell` shortcut changing "msys2_shell.bat" to "msys2_shell.cmd -mingw64" for 64-bit builds or "msys2_shell.cmd -mingw32" for 32-bit builds
* Restart MSYS shell via modified shortcut and update packages again using pacman:

    ```bash
    pacman -Syu
    ```


* Install dependencies:

    To build for 64-bit Windows:

    ```bash
    pacman -S mingw-w64-x86_64-toolchain make mingw-w64-x86_64-cmake mingw-w64-x86_64-boost mingw-w64-x86_64-openssl mingw-w64-x86_64-zeromq mingw-w64-x86_64-libsodium mingw-w64-x86_64-hidapi mingw-w64-x86_64-unbound
    ```

    To build for 32-bit Windows:

    ```bash
    pacman -S mingw-w64-i686-toolchain make mingw-w64-i686-cmake mingw-w64-i686-boost mingw-w64-i686-openssl mingw-w64-i686-zeromq mingw-w64-i686-libsodium mingw-w64-i686-hidapi mingw-w64-i686-unbound
    ```

* Open the MingW shell via `MinGW-w64-Win64 Shell` shortcut on 64-bit Windows
  or `MinGW-w64-Win64 Shell` shortcut on 32-bit Windows. Note that if you are
  running 64-bit Windows, you will have both 64-bit and 32-bit MinGW shells.

**Cloning**

* To git clone, run:

    ```bash
    git clone --recursive https://github.com/lunexa-project/lunexa.git
    ```

**Building**

* Change to the cloned directory, run:

    ```bash
    cd lunexa
    ```

* If you would like a specific [version/tag](https://github.com/lunexa-project//tags), do a git checkout for that version. eg. 'v0.18.1.2'. If you don't care about the version and just want binaries from master, skip this step:

    ```bash
    git checkout ##version##
    ```

* If you are on a 64-bit system, run:

    ```bash
    make release-static-win64
    ```

* If you are on a 32-bit system, run:

    ```bash
    make release-static-win32
    ```

* The resulting executables can be found in `build/release/bin`

* **Optional**: to build Windows binaries suitable for debugging on a 64-bit system, run:

    ```bash
    make debug-static-win64
    ```

* **Optional**: to build Windows binaries suitable for debugging on a 32-bit system, run:

    ```bash
    make debug-static-win32
    ```

* The resulting executables can be found in `build/debug/bin`

### On FreeBSD:

The project can be built from scratch by following instructions for Linux above(but use `gmake` instead of `make`). 
If you are running Lunexa in a jail, you need to add `sysvsem="new"` to your jail configuration, otherwise lmdb will throw the error message: `Failed to open lmdb environment: Function not implemented`.

Lunexa is also available as a port or package as `lunexa-cli`.

### On OpenBSD:

You will need to add a few packages to your system. `pkg_add cmake gmake zeromq libiconv boost libunbound`.

The `doxygen` and `graphviz` packages are optional and require the xbase set.
Running the test suite also requires `py3-requests` package.

Build Lunexa: `gmake`

Note: you may encounter the following error when compiling the latest version of Lunexa as a normal user:

```
LLVM ERROR: out of memory
c++: error: unable to execute command: Abort trap (core dumped)
```

Then you need to increase the data ulimit size to 2GB and try again: `ulimit -d 2000000`

### On NetBSD:

Check that the dependencies are present: `pkg_info -c libexecinfo boost-headers boost-libs protobuf readline libusb1 zeromq git-base pkgconf gmake cmake | more`, and install any that are reported missing, using `pkg_add` or from your pkgsrc tree.  Readline is optional but worth having.

Third-party dependencies are usually under `/usr/pkg/`, but if you have a custom setup, adjust the "/usr/pkg" (below) accordingly.

Clone the lunexa repository recursively and checkout the most recent release as described above. Then build lunexa: `gmake BOOST_ROOT=/usr/pkg LDFLAGS="-Wl,-R/usr/pkg/lib" release`.  The resulting executables can be found in `build/NetBSD/[Release version]/Release/bin/`.

### On Solaris:

The default Solaris linker can't be used, you have to install GNU ld, then run cmake manually with the path to your copy of GNU ld:

```bash
mkdir -p build/release
cd build/release
cmake -DCMAKE_LINKER=/path/to/ld -D CMAKE_BUILD_TYPE=Release ../..
cd ../..
```

Then you can run make as usual.

### Building portable statically linked binaries

By default, in either dynamically or statically linked builds, binaries target the specific host processor on which the build happens and are not portable to other processors. Portable binaries can be built using the following targets:

* ```make release-static-linux-x86_64``` builds binaries on Linux on x86_64 portable across POSIX systems on x86_64 processors
* ```make release-static-linux-i686``` builds binaries on Linux on x86_64 or i686 portable across POSIX systems on i686 processors
* ```make release-static-linux-armv8``` builds binaries on Linux portable across POSIX systems on armv8 processors
* ```make release-static-linux-armv7``` builds binaries on Linux portable across POSIX systems on armv7 processors
* ```make release-static-linux-armv6``` builds binaries on Linux portable across POSIX systems on armv6 processors
* ```make release-static-win64``` builds binaries on 64-bit Windows portable across 64-bit Windows systems
* ```make release-static-win32``` builds binaries on 64-bit or 32-bit Windows portable across 32-bit Windows systems

### Cross Compiling

You can also cross-compile static binaries on Linux for Windows and macOS with the `depends` system.

* ```make depends target=x86_64-linux-gnu``` for 64-bit linux binaries.
* ```make depends target=x86_64-w64-mingw32``` for 64-bit windows binaries.
  * Requires: `python3 g++-mingw-w64-x86-64 wine1.6 bc`
  * You also need to run:  
```update-alternatives --set x86_64-w64-mingw32-g++ x86_64-w64-mingw32-g++-posix && update-alternatives --set x86_64-w64-mingw32-gcc x86_64-w64-mingw32-gcc-posix```
* ```make depends target=x86_64-apple-darwin``` for macOS binaries.
  * Requires: `cmake imagemagick libcap-dev librsvg2-bin libz-dev libbz2-dev libtiff-tools python-dev`
* ```make depends target=i686-linux-gnu``` for 32-bit linux binaries.
  * Requires: `g++-multilib bc`
* ```make depends target=i686-w64-mingw32``` for 32-bit windows binaries.
  * Requires: `python3 g++-mingw-w64-i686`
* ```make depends target=arm-linux-gnueabihf``` for armv7 binaries.
  * Requires: `g++-arm-linux-gnueabihf`
* ```make depends target=aarch64-linux-gnu``` for armv8 binaries.
  * Requires: `g++-aarch64-linux-gnu`
* ```make depends target=riscv64-linux-gnu``` for RISC V 64 bit binaries.
  * Requires: `g++-riscv64-linux-gnu`
* ```make depends target=x86_64-unknown-freebsd``` for freebsd binaries.
  * Requires: `clang-8`
* ```make depends target=arm-linux-android``` for 32bit android binaries
* ```make depends target=aarch64-linux-android``` for 64bit android binaries

The required packages are the names for each toolchain on apt. Depending on your distro, they may have different names. The `depends` system has been tested on Ubuntu 18.04, 20.04 and 22.04

Using `depends` might also be easier to compile Lunexa on Windows than using MSYS. Activate Windows Subsystem for Linux (WSL) with a distro (for example Ubuntu), install the apt build-essentials and follow the `depends` steps as depicted above.

The produced binaries still link libc dynamically. If the binary is compiled on a current distribution, it might not run on an older distribution with an older installation of libc. Passing `-DBACKCOMPAT=ON` to cmake will make sure that the binary will run on systems having at least libc version 2.17.

### Trezor hardware wallet support

LUNEXA currently doesnt support Trezor builds so it is best to disable it for the time being 


If you have an issue with building Lunexa with Trezor support, you can disable it by setting `USE_DEVICE_TREZOR=OFF`, e.g., 

```bash
USE_DEVICE_TREZOR=OFF make release
```

For more information, please check out Trezor [src/device_trezor/README.md](src/device_trezor/README.md).

### GUIX builds

Its recommended to build guix builds on **Ubuntu 22.04**, follow these steps to install GUIX and the necessary dependencies for building Lunexa:

1. **Install GUIX**:
   ```bash
   sudo apt-get install guix make curl git 
2. **Cloning Lunexa**
    ```bash
    git clone https://github.com/lunexa-project/lunexa && cd lunexa
2. **GUIX BUILD** 
    ```bash
    ./contrib/guix/guix-build


See [contrib/guix/README.md](contrib/guix/README.md) for more info.


## Installing Lunexa from a package

**Currently do not have a way to install Lunexa from a package**


Packaging for your favorite distribution would be a welcome contribution!

## Running lunexad

The build places the binary in `bin/` sub-directory within the build directory
from which cmake was invoked (repository root by default). To run in the
foreground:

```bash
./bin/lunexad
```

To list all available options, run `./bin/lunexad --help`.  Options can be
specified either on the command line or in a configuration file passed by the
`--config-file` argument.  To specify an option in the configuration file, add
a line with the syntax `argumentname=value`, where `argumentname` is the name
of the argument without the leading dashes, for example, `log-level=1`.

To run in background:

```bash
./bin/lunexad --log-file lunexad.log --detach
```

To run as a systemd service, copy
[lunexad.service](lunexad.service.md) to `/etc/systemd/system/` and
[lunexad.conf](lunexad.conf.md) to `/etc/`. The [](lunexad.service.md) assumes that the user `lunexa` exists
and its home is the data directory specified in the [](lunexad.conf.md).

If you're on Mac, you may need to add the `--max-concurrency 1` option to
lunexa-wallet-cli, and possibly lunexad, if you get crashes refreshing.

## Internationalization

See [README.i18n.md](docs/README.i18n.md).

## Using Tor

> There is a new, still experimental, [integration with Tor](docs/ANONYMITY_NETWORKS.md). The
> feature allows connecting over IPv4 and Tor simultaneously - IPv4 is used for
> relaying blocks and relaying transactions received by peers whereas Tor is
> used solely for relaying transactions received over local RPC. This provides
> privacy and better protection against surrounding node (sybil) attacks.

While Lunexa isn't made to integrate with Tor, it can be used wrapped with torsocks, by
setting the following configuration parameters and environment variables:

* `--p2p-bind-ip 127.0.0.1` on the command line or `p2p-bind-ip=127.0.0.1` in
  Lunexad.conf to disable listening for connections on external interfaces.
* `--no-igd` on the command line or `no-igd=1` in lunexad.conf to disable IGD
  (UPnP port forwarding negotiation), which is pointless with Tor.
* `DNS_PUBLIC=tcp` or `DNS_PUBLIC=tcp://x.x.x.x` where x.x.x.x is the IP of the
  desired DNS server, for DNS requests to go over TCP, so that they are routed
  through Tor. When IP is not specified, lunexad uses the default list of
  servers defined in [src/common/dns_utils.cpp](src/common/dns_utils.cpp).
* `TORSOCKS_ALLOW_INBOUND=1` to tell torsocks to allow lunexad to bind to interfaces
   to accept connections from the wallet. On some Linux systems, torsocks
   allows binding to localhost by default, so setting this variable is only
   necessary to allow binding to local LAN/VPN interfaces to allow wallets to
   connect from remote hosts. On other systems, it may be needed for local wallets
   as well.
* Do NOT pass `--detach` when running through torsocks with systemd, (see
  [lunexad.service](lunexad.service.md) for details).
* If you use the wallet with a Tor daemon via the loopback IP (eg, 127.0.0.1:9050),
  then use `--untrusted-daemon` unless it is your own hidden service.

Example command line to start lunexad through Tor:

```bash
DNS_PUBLIC=tcp torsocks lunexad --p2p-bind-ip 127.0.0.1 --no-igd
```

A helper script is in contrib/tor/lunexa-over-tor.sh. It assumes Tor is installed
already, and runs Tor and Lunexa with the right configuration.

### Using Tor on Tails

TAILS ships with a very restrictive set of firewall rules. Therefore, you need
to add a rule to allow this connection too, in addition to telling torsocks to
allow inbound connections. Full example:

```bash
sudo iptables -I OUTPUT 2 -p tcp -d 127.0.0.1 -m tcp --dport 9029 -j ACCEPT
DNS_PUBLIC=tcp torsocks ./lunexad --p2p-bind-ip 127.0.0.1 --no-igd --rpc-bind-ip 127.0.0.1 \
    --data-dir /home/amnesia/Persistent/your/directory/to/the/blockchain
```

## Debugging

This section contains general instructions for debugging failed installs or problems encountered with Lunexa. First, ensure you are running the latest version built from the GitHub repo.

### Obtaining stack traces and core dumps on Unix systems

We generally use the tool `gdb` (GNU debugger) to provide stack trace functionality, and `ulimit` to provide core dumps in builds which crash or segfault.

* To use `gdb` in order to obtain a stack trace for a build that has stalled:

Run the build.

Once it stalls, enter the following command:

```bash
gdb /path/to/lunexad `pidof lunexad`
```

Type `thread apply all bt` within gdb in order to obtain the stack trace

* If however the core dumps or segfaults:

Enter `ulimit -c unlimited` on the command line to enable unlimited filesizes for core dumps

Enter `echo core | sudo tee /proc/sys/kernel/core_pattern` to stop cores from being hijacked by other tools

Run the build.

When it terminates with an output along the lines of "Segmentation fault (core dumped)", there should be a core dump file in the same directory as lunexad. It may be named just `core`, or `core.xxxx` with numbers appended.

You can now analyse this core dump with `gdb` as follows:

```bash
gdb /path/to/lunexad /path/to/dumpfile`
```

Print the stack trace with `bt`

 * If a program crashed and cores are managed by systemd, the following can also get a stack trace for that crash:

```bash
coredumpctl -1 gdb
```

#### To run Lunexa within gdb:

Type `gdb /path/to/lunexad`

Pass command-line options with `--args` followed by the relevant arguments

Type `run` to run Lunexad

### Analysing memory corruption

There are two tools available:

#### ASAN

Configure Lunexa with the -D SANITIZE=ON cmake flag, eg:

```bash
cd build/debug && cmake -D SANITIZE=ON -D CMAKE_BUILD_TYPE=Debug ../..
```

You can then run the lunexa tools normally. Performance will typically halve.

#### valgrind

Install valgrind and run as `valgrind /path/to/lunexad`. It will be very slow.

### LMDB

Instructions for debugging suspected blockchain corruption as per @HYC

There is an `mdb_stat` command in the LMDB source that can print statistics about the database but it's not routinely built. This can be built with the following command:

```bash
cd ~/lunexa/external/db_drivers/liblmdb && make
```

The output of `mdb_stat -ea <path to blockchain dir>` will indicate inconsistencies in the blocks, block_heights and block_info table.

The output of `mdb_dump -s blocks <path to blockchain dir>` and `mdb_dump -s block_info <path to blockchain dir>` is useful for indicating whether blocks and block_info contain the same keys.

These records are dumped as hex data, where the first line is the key and the second line is the data.

# Known Issues

## Protocols

### Socket-based

Because of the nature of the socket-based protocols that drive lunexa, certain protocol weaknesses are somewhat unavoidable at this time. While these weaknesses can theoretically be fully mitigated, the effort required (the means) may not justify the ends. As such, please consider taking the following precautions if you are a Lunexa node operator:

- Run `lunexad` on a "secured" machine. If operational security is not your forte, at a very minimum, have a dedicated a computer running `lunexad` and **do not** browse the web, use email clients, or use any other potentially harmful apps on your `lunexad` machine. **Do not click links or load URL/MUA content on the same machine**. Doing so may potentially exploit weaknesses in commands which accept "localhost" and "127.0.0.1".
- If you plan on hosting a public "remote" node, start `lunexad` with `--restricted-rpc`. This is a must.

### Blockchain-based

Certain blockchain "features" can be considered "bugs" if misused correctly. Consequently, please consider the following:

- When receiving lunexa, be aware that it may be locked for an arbitrary time if the sender elected to, preventing you from spending that lunexa until the lock time expires. You may want to hold off acting upon such a transaction until the unlock time lapses. To get a sense of that time, you can consider the remaining blocktime until unlock as seen in the `show_transfers` command.
