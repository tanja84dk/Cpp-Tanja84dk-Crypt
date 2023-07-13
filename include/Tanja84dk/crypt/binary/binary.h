#ifndef TANJA84DK_CRYPT_BINARY_BINARY_H
#define TANJA84DK_CRYPT_BINARY_BINARY_H

#include <Tanja84dk/crypt/pxx.h>

#include <bitset>
#include <string>
#include <vector>

namespace Tanja84dk {
namespace crypt {
namespace binary {

std::vector<std::bitset<8>> encode(const std::string &input_data) noexcept;
std::string decode(const std::string &input_data) noexcept;

}  // namespace binary
}  // namespace crypt
}  // namespace Tanja84dk

#endif  // TANJA84DK_CRYPT_BINARY_BINARY_h