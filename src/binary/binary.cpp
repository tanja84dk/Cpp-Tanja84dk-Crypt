#include <Tanja84dk/crypt/binary/binary.h>
#include <iostream>

#include <string>
#include <sstream>
#include <vector>
#include <bitset>

std::vector<std::bitset<8>> Tanja84dk::crypt::binary::encode(const std::string &input_data) noexcept
{

    std::vector<std::bitset<8>> binary_output_vector = {};
    binary_output_vector.clear();
    binary_output_vector.reserve(100);

    for (std::size_t i = 0; i < input_data.size(); i++)
    {
        binary_output_vector.push_back(std::bitset<8>(input_data.c_str()[i]));
    }

    return binary_output_vector;
}

std::string Tanja84dk::crypt::binary::decode(const std::string &input_data) noexcept
{
    std::stringstream input_buffer_stringstream = {};
    std::string output_data_string = {};
    input_buffer_stringstream.clear();

    input_buffer_stringstream << input_data;

    while (input_buffer_stringstream.good())
    {
        std::bitset<8> bits;
        input_buffer_stringstream >> bits;
        char bits_decoded_char = char(bits.to_ulong());
        output_data_string += bits_decoded_char;
    }

    return output_data_string;
}
