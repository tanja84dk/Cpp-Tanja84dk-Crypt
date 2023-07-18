include(CTest)
find_package(Catch2 3 REQUIRED QUIET)
# These tests can use the Catch2-provided main
add_executable(tanja84dk_crypt_test src/test.cpp)
target_link_libraries(tanja84dk_crypt_test PRIVATE Catch2::Catch2WithMain Tanja84dk::crypt)
