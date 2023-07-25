#ifndef TANJA84DK_CRYPT_BASE32_MY_BASE64_H
#define TANJA84DK_CRYPT_BASE32_MY_BASE64_H

#include <string>

#include "Tanja84dk/crypt/crypt_base_classes.h"
#include "base64.h"

namespace Tanja84dk {
namespace crypt {
class Base64 : public Tanja84dk::crypt::EncoderBaseInterface {
   private:
    std::string input_data_ = {};

   public:
    Base64(const std::string &input_data) noexcept;
    std::string encode() const noexcept override;
    std::string decode() const noexcept override;
};

}  // namespace crypt
}  // namespace Tanja84dk

#endif  // TANJA84DK_CRYPT_BASE32_MY_BASE64_H