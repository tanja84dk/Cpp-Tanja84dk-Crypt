#include <Tanja84dk/crypt/base64/base64.h>

#include <string>

using namespace Tanja84dk::crypt;

Base64::Base64(const std::string &input_data) noexcept { this->input_data_ = input_data; }

std::string Base64::encode() const noexcept {
    CryptoPP::Base64Encoder Encoder(NULL, false);
    std::string encoded_string = {};

    Encoder.Put((CryptoPP::byte *)this->input_data_.data(), this->input_data_.length());

    CryptoPP::word64 size_word64 = Encoder.MaxRetrievable();

    if (size_word64 && size_word64 <= SIZE_MAX) {
        encoded_string.resize(size_word64);
        Encoder.Get((CryptoPP::byte *)encoded_string.data(), encoded_string.size());
    }

    return encoded_string;
}

std::string Base64::decode() const noexcept {
    CryptoPP::Base64Decoder Decoder;
    std::string decoded_string = {};

    Decoder.Put((CryptoPP::byte *)this->input_data_.data(), this->input_data_.size());
    Decoder.MessageEnd();

    CryptoPP::word64 size_word64 = Decoder.MaxRetrievable();

    if (size_word64 && size_word64 <= SIZE_MAX) {
        decoded_string.resize(size_word64);
        Decoder.Get((CryptoPP::byte *)decoded_string.data(), decoded_string.size());
    }

    return decoded_string;
}