#ifndef TANJA84DK_CRYPT_CEASAR_CEASAR_H
#define TANJA84DK_CRYPT_CEASAR_CEASAR_H
#include <string>

namespace Tanja84dk::crypt::ceasar
{
    std::string encode(const int chipher_shift_key, const std::string &input_data);
    std::string decode(const int chipher_shift_key, const std::string &input_data);
    void decode_brute_force(const std::string &input_data);
}

#endif // TANJA84DK_CRYPT_CEASAR_CEASAR_h