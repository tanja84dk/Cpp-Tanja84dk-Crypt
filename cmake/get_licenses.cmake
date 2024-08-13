
set(${PROJECT_NAME}_LICENSES_MACRO_FILE ${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}_licenses_macro.h.in)

if(EXISTS "${${PROJECT_NAME}_LICENSES_MACRO_FILE}")
    file(WRITE "${${PROJECT_NAME}_LICENSES_MACRO_FILE}" "")
endif()

file(APPEND "${${PROJECT_NAME}_LICENSES_MACRO_FILE}" "#ifndef TANJA84DK_CRYPT_LICENCES_MACRO_H\n")
file(APPEND "${${PROJECT_NAME}_LICENSES_MACRO_FILE}" "#define TANJA84DK_CRYPT_LICENCES_MACRO_H\n\n")

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
    file(STRINGS ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE tanja84dk_crypt_LICENSE)
    string(PREPEND tanja84dk_crypt_LICENSE "R\"(")
    string(APPEND tanja84dk_crypt_LICENSE ")\"")
    file(APPEND ${${PROJECT_NAME}_LICENSES_MACRO_FILE} "#define tanja84dk_crypt_LICENSE @tanja84dk_crypt_LICENSE@\n")
else()
    message("tanja84dk_crypt_LICENSE is missing")
endif()

if(EXISTS "${renenyffenegger_base64_SOURCE_DIR}/LICENSE")
    file(STRINGS ${renenyffenegger_base64_SOURCE_DIR}/LICENSE renenyffenegger_base64_LICENSE)
    string(PREPEND renenyffenegger_base64_LICENSE "R\"(")
    string(APPEND renenyffenegger_base64_LICENSE ")\"")
    file(APPEND ${${PROJECT_NAME}_LICENSES_MACRO_FILE} "#define renenyffenegger_base64_LICENSE @renenyffenegger_base64_LICENSE@\n")
else()
    message("renenyffenegger_base64_LICENSE is missing")
endif()

file(APPEND "${${PROJECT_NAME}_LICENSES_MACRO_FILE}"
"\n#endif // TANJA84DK_CRYPT_LICENCES_MACRO_H\n")

configure_file(${${PROJECT_NAME}_LICENSES_MACRO_FILE} include/Tanja84dk/crypt/${PROJECT_NAME}_licenses_macro.h)