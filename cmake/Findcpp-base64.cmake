CPMAddPackage(
    NAME            cpp_base64
    GIT_REPOSITORY  https://github.com/ReneNyffenegger/cpp-base64
    VERSION         2.rc.09
    GIT_TAG         82147d6d89636217b870f54ec07ddd3e544d5f69
)

if(cpp_base64_ADDED)
  add_library(cpp-base64 STATIC ${cpp_base64_SOURCE_DIR}/base64.cpp)

  set_target_properties(cpp-base64
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
  )

  target_include_directories(cpp-base64 PUBLIC ${cpp_base64_SOURCE_DIR})

endif()
