#ifndef TANJA84DK_CRYPT_BASE32_BASE32_H
#define TANJA84DK_CRYPT_BASE32_BASE32_H
#include <Tanja84dk/crypt/pxx.h>

#include <string>

namespace Tanja84dk {
namespace crypt {
namespace base32 {

std::string decode(const std::string &input_data) noexcept;
std::string encode(const std::string &input_data) noexcept;

}  // namespace base32
}  // namespace crypt
}  // namespace Tanja84dk

#endif  // TANJA84DK_CRYPT_BASE32_BASE32_h