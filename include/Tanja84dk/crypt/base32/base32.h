#ifndef TANJA84DK_CRYPT_BASE32_BASE32_H
#define TANJA84DK_CRYPT_BASE32_BASE32_H
#include <string>

namespace Tanja84dk::crypt::base32
{
    std::string decode(const std::string &input_data) noexcept;
    std::string encode(const std::string &input_data) noexcept;
}

namespace Tanja84dk::crypt::base32hex
{
    std::string decode(const std::string &input_data) noexcept;
    std::string encode(const std::string &input_data) noexcept;
}

#endif // TANJA84DK_CRYPT_BASE32_BASE32_h