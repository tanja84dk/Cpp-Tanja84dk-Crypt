

find_package(Catch2 3 REQUIRED QUIET)
# These tests can use the Catch2-provided main
add_executable(tanja84dk_crypt_test src/test.cpp)
target_link_libraries(tanja84dk_crypt_test PRIVATE Catch2::Catch2WithMain Tanja84dk::crypt)

include(CTest)

# These tests need their own main
#add_executable(custom-main-tests test.cpp test-main.cpp)
#target_link_libraries(custom-main-tests PRIVATE Catch2::Catch2)