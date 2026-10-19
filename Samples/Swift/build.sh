#!/bin/sh
set -eu
cd "$(dirname "$0")"
XCODEGEN="${XCODEGEN:-$HOME/.local/bin/xcodegen}"
if [ ! -x "$XCODEGEN" ]; then XCODEGEN=xcodegen; fi
"$XCODEGEN" generate --spec project.yml
xcrun xcodebuild -project SnapIPCNative.xcodeproj -scheme SnapIPCNative -configuration Debug -sdk iphonesimulator -derivedDataPath build/xcode-derived-data ARCHS=arm64 CODE_SIGNING_ALLOWED=NO build
