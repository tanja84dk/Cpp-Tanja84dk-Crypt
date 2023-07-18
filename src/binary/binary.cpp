#include <Tanja84dk/crypt/binary/binary.h>
#include <Tanja84dk/crypt/pxx.h>

#include <bitset>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace Tanja84dk::crypt;

Binary::Binary(const std::string& input_data) noexcept {
    this->input_data = input_data;
    this->input_data_length = input_data.size();
}

std::string Binary::encode() const noexcept {
    std::string output_data_string = {};
    std::vector<std::bitset<8>> buffer_data = this->encode_to_bits();
    for (std::vector<std::bitset<8>>::iterator i = buffer_data.begin(); i != buffer_data.end(); i++) {
        std::cout << *i << ' ';
    }
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

std::vector<std::bitset<8>> Binary::encode_to_bits() const noexcept {
    std::vector<std::bitset<8>> binary_output_vector = {};
    binary_output_vector.clear();
    binary_output_vector.reserve(100);

    for (std::size_t i = 0; i < this->input_data_length; i++) {
        binary_output_vector.push_back(std::bitset<8>(this->input_data.c_str()[i]));
    }

    return binary_output_vector;
}

std::string Binary::decode() const noexcept {
    std::string result;
    std::bitset<8> bits;

    std::istringstream sstream(this->input_data);

    std::string bits_chunk;
    while (sstream >> bits_chunk) {
        bits = std::bitset<8>(bits_chunk);

        char buffer_char = static_cast<char>(bits.to_ulong());
        result.push_back(buffer_char);
    }

    return result;
}

std::string Binary::binary_vector_string_to_ascii(const std::vector<std::string>& binary_strings) noexcept {
    std::string result;
    std::bitset<8> bits;

    for (const std::string& binary_string : binary_strings) {
        bits = std::bitset<8>(binary_string);

        char ascii_char = static_cast<char>(bits.to_ulong());
        result.push_back(ascii_char);
    }

    return result;
}