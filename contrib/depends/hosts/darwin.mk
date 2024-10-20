OSX_MIN_VERSION=10.13
OSX_SDK_VERSION=11.0
XCODE_VERSION=12.2
XCODE_BUILD_ID=12B45b
LD64_VERSION=609

OSX_SDK=$(host_prefix)/native/SDK

ifeq (aarch64, $(host_arch))
CC_target=arm64-apple-$(host_os)
else
CC_target=$(host)
endif
darwin_CC=clang -target $(CC_target) -mmacosx-version-min=$(OSX_MIN_VERSION) --sysroot $(host_prefix)/native/SDK/ -mlinker-version=$(LD64_VERSION) -B$(host_prefix)/native/bin/$(host)-
darwin_CXX=clang++ -target $(CC_target) -mmacosx-version-min=$(OSX_MIN_VERSION) --sysroot $(host_prefix)/native/SDK/ -mlinker-version=$(LD64_VERSION) -stdlib=libc++ -B$(host_prefix)/native/bin/$(host)-

darwin_CFLAGS=-pipe
darwin_CXXFLAGS=$(darwin_CFLAGS)
darwin_ARFLAGS=cr

darwin_release_CFLAGS=-O1
darwin_release_CXXFLAGS=$(darwin_release_CFLAGS)

darwin_debug_CFLAGS=-O1
darwin_debug_CXXFLAGS=$(darwin_debug_CFLAGS)

darwin_cmake_system=Darwin

darwin_native_toolchain=native_cctools darwin_sdk