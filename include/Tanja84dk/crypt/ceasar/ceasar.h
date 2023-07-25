#ifndef TANJA84DK_CRYPT_CEASAR_CEASAR_H
#define TANJA84DK_CRYPT_CEASAR_CEASAR_H
#include <string>

#include "Tanja84dk/crypt/pxx.h"

namespace Tanja84dk {
namespace crypt {
namespace ceasar {

std::string encode(const int chipher_shift_key, const std::string &input_data);
std::string decode(const int chipher_shift_key, const std::string &input_data);
void decode_brute_force(const std::string &input_data);

}  // namespace ceasar
}  // namespace crypt
}  // namespace Tanja84dk

#endif  // TANJA84DK_CRYPT_CEASAR_CEASAR_h