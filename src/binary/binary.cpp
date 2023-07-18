#include <Tanja84dk/crypt/binary/binary.h>
#include <Tanja84dk/crypt/pxx.h>

#include <bitset>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace Tanja84dk::crypt;

Binary::Binary(const std::string &input_data) noexcept {
    this->input_data = input_data;
    this->input_data_length = input_data.size();
}

std::string Binary::encode() const noexcept {
    // std::string output_data_string = {};
    std::vector<std::bitset<8>> buffer_data = this->encode_to_bits();
    std::stringstream buffer_sstream = {};

    for (auto it = buffer_data.begin(); it != buffer_data.end(); it++) {
        if (it != buffer_data.begin()) {
            buffer_sstream << " ";
        }
        buffer_sstream << *it;
    }

    return buffer_sstream.str();
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
    std::stringstream input_buffer_stringstream = {};
    std::string output_data_string = {};
    input_buffer_stringstream.clear();

    input_buffer_stringstream << this->input_data;

    while (input_buffer_stringstream.good()) {
        std::bitset<8> bits;
        input_buffer_stringstream >> bits;
        char bits_decoded_char = char(bits.to_ulong());
        output_data_string += bits_decoded_char;
    }

    return output_data_string;
}