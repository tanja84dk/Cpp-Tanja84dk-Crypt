#ifndef TANJA84DK_CRYPT_BINARY_BINARY_H
#define TANJA84DK_CRYPT_BINARY_BINARY_H

#include <bitset>
#include <string>
#include <vector>

#include "Tanja84dk/crypt/crypt_base_classes.h"
#include "Tanja84dk/crypt/pxx.h"

namespace Tanja84dk {
namespace crypt {
class Binary : public Tanja84dk::crypt::EncoderBaseInterface {
   private:
    std::string input_data = {};
    std::size_t input_data_length = {};

   public:
    Binary(const std::string& data_string) noexcept;
    /// @brief Decoding 8bit string separated with spaces for each 8 bit chunks
    /// @return The ascii reconversion of the binary string as a string
    std::string decode() const noexcept override;
    std::string encode() const noexcept override;
    std::string binary_vector_string_to_ascii(const std::vector<std::string>& binary_strings) noexcept;
    /// @brief encoding the string sat in constructor to a 8bit vector
    /// @return a vector of std::bitset<8>
    std::vector<std::bitset<8>> encode_to_bits() const noexcept;
};
}  // namespace crypt
}  // namespace Tanja84dk

#endif  // TANJA84DK_CRYPT_BINARY_BINARY_h