#!/bin/bash

set -x
rm libhello.so
/data/grwebrtc_gmaster/src/third_party/android_tools/ndk/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-gcc  \
hello.c hello_jni.c \
-I/data/grwebrtc_gmaster/src/chromium/src/third_party/android_tools/ndk/platforms/android-21/arch-arm/usr/include \
-nostdlib \
/data/grwebrtc_gmaster/src/chromium/src/third_party/android_tools/ndk/platforms/android-21/arch-arm/usr/lib/libc.so \
/data/grwebrtc_gmaster/src/chromium/src/third_party/android_tools/ndk/platforms/android-21/arch-arm/usr/lib/liblog.so \
 -fPIC -shared -o libhello.so
ls -liah lib*
