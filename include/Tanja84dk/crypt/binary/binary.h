#ifndef TANJA84DK_CRYPT_BINARY_BINARY_H
#define TANJA84DK_CRYPT_BINARY_BINARY_H

#include <Tanja84dk/crypt/crypt_base_classes.h>
#include <Tanja84dk/crypt/pxx.h>

#include <bitset>
#include <string>
#include <vector>

namespace Tanja84dk {
namespace crypt {
class Binary : public Tanja84dk::crypt::EncoderBaseInterface {
   private:
    std::string input_data;
    std::size_t input_data_length;

   public:
    Binary(const std::string& input_data) noexcept;
    std::string decode() const noexcept override;
    std::string encode() const noexcept override;
    std::string binary_vector_string_to_ascii(const std::vector<std::string>& binary_strings) noexcept;
    std::vector<std::bitset<8>> encode_to_bits() const noexcept;
};
}  // namespace crypt
}  // namespace Tanja84dk

#endif  // TANJA84DK_CRYPT_BINARY_BINARY_h