#ifndef TANJA84DK_CRYPT_BASE64_BASE64_H
#define TANJA84DK_CRYPT_BASE64_BASE64_H

#include <string>

#include <Tanja84dk/tools/tools.h>

namespace Tanja84dk::crypt::base64
{
    std::string decode(const std::string &input_data);
    std::string encode(const std::string &data);
    void myBase64Encoding(void);
    void myBase64Encoding(const std::string &input_data);
    void myBase64Decoding(void);
    void myBase64Decoding(const std::string &input_data);
    void myBase64DecodingString(void);
}
#endif // TANJA84DK_CRYPT_BASE64_BASE64_h