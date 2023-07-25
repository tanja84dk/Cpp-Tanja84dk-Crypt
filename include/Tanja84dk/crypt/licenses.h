#ifndef TANJA84DK_CRYPT_LICENCES_H
#define TANJA84DK_CRYPT_LICENCES_H

#include <iostream>
#include <string>

#include "Tanja84dk/crypt/pxx.h"
#include "Tanja84dk/crypt/tanja84dk_crypt_licenses_macro.h"

namespace Tanja84dk {
namespace crypt {
namespace license {
namespace {

void print_title_for_licenses(const std::string &title) {
    std::cout << "---------------------------\n"
              << '\t' << "License for: " << title << '\n'
              << "---------------------------\n";
}

void replace_all(std::string &str, const std::string &from, const std::string &to) {
    if (from.empty()) {
        return;
    };
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

}  // namespace

#ifdef tanja84dk_crypt_LICENSE
std::string get_tanja84dk_crypt_license() {
    std::string license = tanja84dk_crypt_LICENSE;
    replace_all(license, ";", "\n");
    return license;
};
#endif  // tanja84dk_crypt_LICENSE

#ifdef cryptopp_cmake_LICENSE
std::string get_cryptopp_cmake_license() {
    std::string license = cryptopp_cmake_LICENSE;
    replace_all(license, ";", "\n");
    return license;
};
#endif  // cryptopp_cmake_LICENSE

#ifdef cryptopp_LICENSE
std::string get_cryptopp_license() {
    std::string license = cryptopp_LICENSE;
    replace_all(license, ";", "\n");
    return license;
};
#endif  // cryptopp_LICENSE

void print_all_licenses() {
#ifdef tanja84dk_crypt_LICENSE
    license::print_title_for_licenses("tanja84dk_crypt");
    std::cout << license::get_tanja84dk_crypt_license() << '\n' << '\n';
#endif  // tanja84dk_crypt_LICENSE

#ifdef cryptopp_cmake_LICENSE
    license::print_title_for_licenses("cryptopp-cmake");
    std::cout << license::get_cryptopp_cmake_license() << '\n' << '\n';
#endif  // cryptopp_cmake_LICENSE

#ifdef cryptopp_LICENSE
    license::print_title_for_licenses("cryptopp");
    std::cout << license::get_cryptopp_license() << '\n' << '\n';
#endif  // cryptopp_LICENSE
    std::cout << std::flush;
}

}  // namespace license
}  // namespace crypt
}  // namespace Tanja84dk

#endif  // TANJA84DK_CRYPT_LICENCES_H