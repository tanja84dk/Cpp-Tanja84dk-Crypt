#ifndef TANJA84DK_CRYPT_BASE64_BASE64_H
#define TANJA84DK_CRYPT_BASE64_BASE64_H

#include <string>

#include <Tanja84dk/tools/tools.h>

namespace Tanja84dk::crypt::base64
{
    std::string decode(const std::string &input_data);
    std::string encode(const std::string &input_data);
}
#endif // TANJA84DK_CRYPT_BASE64_BASE64_h