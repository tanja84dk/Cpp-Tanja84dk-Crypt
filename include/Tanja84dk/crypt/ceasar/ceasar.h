#ifndef TANJA84DK_CRYPT_CAESAR_CAESAR_H
#define TANJA84DK_CRYPT_CAESAR_CAESAR_H
#include <string>

#include "Tanja84dk/crypt/pxx.h"

namespace Tanja84dk {
namespace crypt {

class Caesar {
   public:
    std::string encode(const int cipher_shift_key, const std::string &input_data_string) const noexcept;
    std::string decode(const int cipher_shift_key, const std::string &input_data_string) const noexcept;

    void decode_brute_force(const std::string &input_data_string);

   private:
    std::string data_string = {};
};

// std::string encode(const int cipher_shift_key, const std::string &input_data);
// std::string decode(const int cipher_shift_key, const std::string &input_data);
// void decode_brute_force(const std::string &input_data);

}  // namespace crypt
}  // namespace Tanja84dk

#endif  // TANJA84DK_CRYPT_CAESAR_CAESAR_H