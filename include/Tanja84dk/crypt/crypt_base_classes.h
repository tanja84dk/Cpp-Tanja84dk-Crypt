#ifndef TANJA84DK_CRYPT_CRYPT_BASE_CLASSES_H
#define TANJA84DK_CRYPT_CRYPT_BASE_CLASSES_H

#include <string>

namespace Tanja84dk {
namespace crypt {
class EncoderBaseInterface {
   public:
    virtual std::string decode() const = 0;
    virtual std::string encode() const = 0;
};
}  // namespace crypt
}  // namespace Tanja84dk

#endif  // TANJA84DK_CRYPT_CRYPT_BASE_CLASSES_H