#ifndef TANJA84DK_CRYPT_BASE32_BASE32HEX_H
#define TANJA84DK_CRYPT_BASE32_BASE32HEX_H
#include <string>

#include "Tanja84dk/crypt/crypt_base_classes.h"
#include "Tanja84dk/crypt/pxx.h"

namespace Tanja84dk {
namespace crypt {
class Base32Hex : public Tanja84dk::crypt::EncoderBaseInterface {
   private:
    std::string input_data = {};

   public:
    std::string decode() const noexcept override;
    std::string encode() const noexcept override;
};

}  // namespace crypt
}  // namespace Tanja84dk

#endif  // TANJA84DK_CRYPT_BASE32_BASE32HEX_h