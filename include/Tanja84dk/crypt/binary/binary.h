#ifndef TANJA84DK_CRYPT_BINARY_BINARY_H
#define TANJA84DK_CRYPT_BINARY_BINARY_H
#include <string>
#include <vector>
#include <bitset>

namespace Tanja84dk::crypt::binary
{
    std::vector<std::bitset<8>> encode(const std::string &input_data) noexcept;
    std::string decode(const std::string &input_data) noexcept;
}

#endif // TANJA84DK_CRYPT_BINARY_BINARY_h