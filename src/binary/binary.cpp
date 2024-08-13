#include <Tanja84dk/crypt/binary/binary.h>
#include <Tanja84dk/crypt/pxx.h>

#include <bitset>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

Tanja84dk::crypt::Binary::Binary(const std::string& input_data_string) noexcept {
    this->input_data = input_data_string;
    this->input_data_length = input_data_string.size();
}

std::string Tanja84dk::crypt::Binary::encode() const noexcept {
    std::string output_data_string = {};
    std::vector<std::bitset<8>> buffer_data = this->encode_to_bits();

    std::ostringstream buffer_sstream = {};

    for (std::vector<std::bitset<8>>::iterator it = buffer_data.begin(); it != buffer_data.end(); it++) {
        if (it != buffer_data.begin()) {
            buffer_sstream << " ";
        }
        buffer_sstream << *it;
    }

    output_data_string = buffer_sstream.str();

    return output_data_string;
}

std::vector<std::bitset<8>> Tanja84dk::crypt::Binary::encode_to_bits() const noexcept {
    std::vector<std::bitset<8>> binary_output_vector = {};
    binary_output_vector.clear();
    binary_output_vector.reserve(100);

    for (std::size_t i = 0; i < this->input_data_length; i++) {
        binary_output_vector.push_back(std::bitset<8>(this->input_data.c_str()[i]));
    }

    return binary_output_vector;
}

std::string Tanja84dk::crypt::Binary::decode() const noexcept {
    std::string result = {};
    std::bitset<8> bits = {};

    std::istringstream sstream(this->input_data);

    std::string bits_chunk;
    while (sstream >> bits_chunk) {
        bits = std::bitset<8>(bits_chunk);

        char buffer_char = static_cast<char>(bits.to_ulong());
        result.push_back(buffer_char);
    }

    return result;
}

std::string Tanja84dk::crypt::Binary::binary_vector_string_to_ascii(
    const std::vector<std::string>& binary_strings) noexcept {
    std::string result = {};
    std::bitset<8> bits = {};

    for (const std::string& binary_string : binary_strings) {
        bits = std::bitset<8>(binary_string);

        char ascii_char = static_cast<char>(bits.to_ulong());
        result.push_back(ascii_char);
    }

    return result;
}