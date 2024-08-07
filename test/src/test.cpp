// 010-TestCase.cpp
// And write tests in the same file:
#include <Tanja84dk/crypt/crypt.h>
#include <Tanja84dk/crypt/licenses.h>
#include <Tanja84dk/crypt/tanja84dk_crypt_licenses_macro.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Binary Encode") {
    CHECK(Tanja84dk::crypt::Binary("Hello").encode() == "01001000 01100101 01101100 01101100 01101111");
}

TEST_CASE("Binary Decode") {
    CHECK(Tanja84dk::crypt::Binary("01001000 01100101 01101100 01101100 01101111").decode() == "Hello");
}

TEST_CASE("Binary With spaces and ! Encode") {
    CHECK(Tanja84dk::crypt::Binary("this was a triumph!!!").encode() ==
          "01110100 01101000 01101001 01110011 00100000 01110111 01100001 01110011 00100000 01100001 00100000 01110100 "
          "01110010 01101001 01110101 01101101 01110000 01101000 00100001 00100001 00100001");
}
TEST_CASE("Binary With spaces and ! Decode") {
    CHECK(Tanja84dk::crypt::Binary(
              "01110100 01101000 01101001 01110011 00100000 01110111 01100001 01110011 00100000 01100001 00100000 "
              "01110100 01110010 01101001 01110101 01101101 01110000 01101000 00100001 00100001 00100001")
              .decode() == "this was a triumph!!!");
}

/*
TEST_CASE("Encode Base32") {
    REQUIRE(Tanja84dk::crypt::base32::encode("") == "");
    REQUIRE(Tanja84dk::crypt::base32::encode("f") == "MY======");
    REQUIRE(Tanja84dk::crypt::base32::encode("fo") == "MZXQ====");
    REQUIRE(Tanja84dk::crypt::base32::encode("foo") == "MZXW6===");
    REQUIRE(Tanja84dk::crypt::base32::encode("foob") == "MZXW6YQ=");
    REQUIRE(Tanja84dk::crypt::base32::encode("fooba") == "MZXW6YTB");
    REQUIRE(Tanja84dk::crypt::base32::encode("foobar") == "MZXW6YTBOI======");
}


TEST_CASE("Decode Base32") {
    REQUIRE(Tanja84dk::crypt::base32::decode("") == "");
    REQUIRE(Tanja84dk::crypt::base32::decode("MY======") == "f");
    REQUIRE(Tanja84dk::crypt::base32::decode("MZXQ====") == "fo");
    REQUIRE(Tanja84dk::crypt::base32::decode("MZXW6===") == "foo");
    REQUIRE(Tanja84dk::crypt::base32::decode("MZXW6YQ=") == "foob");
    REQUIRE(Tanja84dk::crypt::base32::decode("MZXW6YTB") == "fooba");
    REQUIRE(Tanja84dk::crypt::base32::decode("MZXW6YTBOI======") == "foobar");
}
*/

TEST_CASE("Encode Base64") {
    CHECK(Tanja84dk::crypt::Base64("").encode() == "");
    CHECK(Tanja84dk::crypt::Base64("f").encode() == "Zg==");
    CHECK(Tanja84dk::crypt::Base64("fo").encode() == "Zm8=");
    CHECK(Tanja84dk::crypt::Base64("foo").encode() == "Zm9v");
    CHECK(Tanja84dk::crypt::Base64("foob").encode() == "Zm9vYg==");
    CHECK(Tanja84dk::crypt::Base64("fooba").encode() == "Zm9vYmE=");
    CHECK(Tanja84dk::crypt::Base64("foobar").encode() == "Zm9vYmFy");
    CHECK(Tanja84dk::crypt::Base64("Welcome to Ubuntu 22.04.2 LTS (GNU/Linux 5.15.0-76-generic x86_64)").encode() ==
          "V2VsY29tZSB0byBVYnVudHUgMjIuMDQuMiBMVFMgKEdOVS9MaW51eCA1LjE1LjAtNzYtZ2VuZXJpYyB4ODZfNjQp");
}

TEST_CASE("Decode Base64") {
    CHECK(Tanja84dk::crypt::Base64("").decode() == "");
    CHECK(Tanja84dk::crypt::Base64("Zg==").decode() == "f");
    CHECK(Tanja84dk::crypt::Base64("Zm8=").decode() == "fo");
    CHECK(Tanja84dk::crypt::Base64("Zm9v").decode() == "foo");
    CHECK(Tanja84dk::crypt::Base64("Zm9vYg==").decode() == "foob");
    CHECK(Tanja84dk::crypt::Base64("Zm9vYmE=").decode() == "fooba");
    CHECK(Tanja84dk::crypt::Base64("Zm9vYmFy").decode() == "foobar");
    CHECK(Tanja84dk::crypt::Base64(
              "V2VsY29tZSB0byBVYnVudHUgMjIuMDQuMiBMVFMgKEdOVS9MaW51eCA1LjE1LjAtNzYtZ2VuZXJpYyB4ODZfNjQp")
              .decode() == "Welcome to Ubuntu 22.04.2 LTS (GNU/Linux 5.15.0-76-generic x86_64)");
}
