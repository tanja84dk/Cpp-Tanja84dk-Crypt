#ifndef TANJA84DK_CRYPT_LICENSES_H
#define TANJA84DK_CRYPT_LICENSES_H

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

#ifdef renenyffenegger_base64_LICENSE
std::string get_renenyffenegger_base64_license() {
    std::string license = renenyffenegger_base64_LICENSE;
    replace_all(license, ";", "\n");
    return license;
};
#endif  // renenyffenegger_base64_LICENSE

void print_all_licenses() {
#ifdef tanja84dk_crypt_LICENSE
    license::print_title_for_licenses("tanja84dk_crypt");
    std::cout << license::get_tanja84dk_crypt_license() << '\n' << '\n';
#endif  // tanja84dk_crypt_LICENSE

#ifdef renenyffenegger_base64_LICENSE
    license::print_title_for_licenses("renenyffenegger_base64");
    std::cout << license::get_renenyffenegger_base64_license() << '\n' << '\n';
#endif  // renenyffenegger_base64_LICENSE

    std::cout << std::flush;
}

}  // namespace license
}  // namespace crypt
}  // namespace Tanja84dk

#endif  // TANJA84DK_CRYPT_LICENSES_H