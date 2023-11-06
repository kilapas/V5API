# V5API
This is a library based on libV5SDK that provides some simple APIs.
## Supported platforms:
- Windows x64
## Compile
### Windows(Visual Studio 2022)
Run Developer PowerShell for VS 2022 and cd to your repo dir.
```
git clone https://github.com/kilapas/libV5SDK libV5SDK
...
Compile libV5SDK with reference to the README.md of libV5SDK.
...
mkdir build
cd build
cmake -G "Visual Studio 17 2022" ../
msbuild /p:Configuration=Debug V5API.sln
```
Replace "Debug" with "Release" to build a release version.
