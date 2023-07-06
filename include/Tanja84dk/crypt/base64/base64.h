#ifndef TANJA84DK_CRYPT_BASE64_BASE64_H
#define TANJA84DK_CRYPT_BASE64_BASE64_H

#include <iostream>
#include <fstream>
#include <string>

namespace Tanja84dk::crypt::base64
{
    std::string decode(const std::string &input_data) noexcept;
    std::string encode(const std::string &input_data) noexcept;
    std::ofstream decode(const std::ifstream &input_file_handler) noexcept;
    std::ofstream encode(const std::ifstream &input_file_handler) noexcept;
}
#endif // TANJA84DK_CRYPT_BASE64_BASE64_h