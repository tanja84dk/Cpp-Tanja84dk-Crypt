#ifndef TANJA84DK_CRYPT_BINARY_BINARY_H
#define TANJA84DK_CRYPT_BINARY_BINARY_H
#include <string>

namespace Tanja84dk::crypt::binary
{
    void encoding(void);
    void encoding(const std::string &data);
    void decoding_string(const std::string &inputFilename);
}

#endif // TANJA84DK_CRYPT_BINARY_BINARY_h