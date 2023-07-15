// 010-TestCase.cpp
// And write tests in the same file:
#include <Tanja84dk/crypt/crypt.h>
#include <Tanja84dk/crypt/licenses.h>
#include <Tanja84dk/crypt/tanja84dk_crypt_licenses_macro.h>

#include <catch2/catch_test_macros.hpp>

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
    CHECK(Tanja84dk::crypt::base64::encode("") == "");
    CHECK(Tanja84dk::crypt::base64::encode("f") == "Zg==");
    CHECK(Tanja84dk::crypt::base64::encode("fo") == "Zm8=");
    CHECK(Tanja84dk::crypt::base64::encode("foo") == "Zm9v");
    CHECK(Tanja84dk::crypt::base64::encode("foob") == "Zm9vYg==");
    CHECK(Tanja84dk::crypt::base64::encode("fooba") == "Zm9vYmE=");
    CHECK(Tanja84dk::crypt::base64::encode("foobar") == "Zm9vYmFy");
}

TEST_CASE("Decode Base64") {
    CHECK(Tanja84dk::crypt::base64::decode("") == "");
    CHECK(Tanja84dk::crypt::base64::decode("Zg==") == "f");
    CHECK(Tanja84dk::crypt::base64::decode("Zm8=") == "fo");
    CHECK(Tanja84dk::crypt::base64::decode("Zm9v") == "foo");
    CHECK(Tanja84dk::crypt::base64::decode("Zm9vYg==") == "foob");
    CHECK(Tanja84dk::crypt::base64::decode("Zm9vYmE=") == "fooba");
    CHECK(Tanja84dk::crypt::base64::decode("Zm9vYmFy") == "foobar");
}
