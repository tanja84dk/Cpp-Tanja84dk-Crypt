#include "Tanja84dk/crypt/base32/base32.h"

#include <Tanja84dk/crypt/pxx.h>

#include <string>

using namespace Tanja84dk::crypt;

Base32::Base32(const std::string &input_data) noexcept {
    this->input_data_ = input_data;
    this->input_data_length_ = input_data.size();
}

std::string Base32::decode() const noexcept {
    CryptoPP::Base32Decoder Decoder;
    std::string decoded_string;

    Decoder.Put((CryptoPP::byte *)this->input_data_.data(), this->input_data_.length());
    Decoder.MessageEnd();

    CryptoPP::word64 size_word64 = Decoder.MaxRetrievable();

    if (size_word64 && size_word64 <= SIZE_MAX) {
        decoded_string.resize(size_word64);
        Decoder.Get((CryptoPP::byte *)&decoded_string[0], decoded_string.size());
    }
    return decoded_string;
}

std::string Base32::encode() const noexcept {
    CryptoPP::Base32Encoder Encoder;
    std::string encoded_string = {};

    Encoder.Put((CryptoPP::byte *)this->input_data_.data(), this->input_data_.length());
    Encoder.MessageEnd();

    CryptoPP::word64 size_word64 = Encoder.MaxRetrievable();
    if (size_word64 && size_word64 <= SIZE_MAX) {
        encoded_string.resize(size_word64);
        Encoder.Get((CryptoPP::byte *)&encoded_string[0], encoded_string.size());
    }

    return encoded_string;
}
