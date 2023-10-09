CPMAddPackage(
    NAME            cryptopp-cmake
    GIT_REPOSITORY  https://github.com/abdes/cryptopp-cmake
    VERSION         8.9.0
    GIT_TAG         CRYPTOPP_8_9_0
    OPTIONS
        "CRYPTOPP_BUILD_TESTING OFF"
)