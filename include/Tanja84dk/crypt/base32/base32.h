#ifndef TANJA84DK_CRYPT_BASE32_BASE32_H
#define TANJA84DK_CRYPT_BASE32_BASE32_H
#include <string>

#include "Tanja84dk/crypt/crypt_base_classes.h"
#include "Tanja84dk/crypt/pxx.h"

namespace Tanja84dk {
namespace crypt {
class Base32 : public Tanja84dk::crypt::EncoderBaseInterface {
   private:
    std::string _input_data = {};
    std::size_t _input_data_length = {};

   public:
    Base32(const std::string &input_data) noexcept;

    std::string decode() const noexcept override;
    std::string encode() const noexcept override;
};
}  // namespace crypt
}  // namespace Tanja84dk

#endif  // TANJA84DK_CRYPT_BASE32_BASE32_h