#!/bin/bash
set -x
rm libhellocpp.so
/data/grwebrtc_gmaster/src/third_party/android_tools/ndk/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/bin/arm-linux-androideabi-g++ \
hello_jni.cpp \
--sysroot=/data/grwebrtc_gmaster/src/chromium/src/third_party/android_tools/ndk/platforms/android-21/arch-arm \
-I/data/grwebrtc_gmaster/src/chromium/src/third_party/android_tools/ndk/platforms/android-21/arch-arm/usr/include \
-fPIC -shared -o libhellocpp.so
ls -liah libhellocpp.so
