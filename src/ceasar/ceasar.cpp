#include <Tanja84dk/crypt/ceasar/ceasar.h>
#include <iostream>

#include <string>
std::string Tanja84dk::crypt::ceasar::encode(const int chipher_shift_key, const std::string &input_data)
{
    std::string output_data_string;

    char buffer_char;
    for (int i = 0; i != input_data.length(); i++)
    {
        buffer_char = input_data[i];
        if (buffer_char >= 'a' && buffer_char <= 'z')
        {
            buffer_char = buffer_char + chipher_shift_key;
            if (buffer_char > 'z')
            {
                buffer_char = buffer_char - 'z' + 'a' - 1;
            }
            output_data_string += buffer_char;
        }
        else if (buffer_char >= 'A' && buffer_char <= 'Z')
        {
            buffer_char = buffer_char + chipher_shift_key;
            if (buffer_char > 'Z')
            {
                buffer_char = buffer_char - 'Z' + 'a' - 1;
            }
            output_data_string += buffer_char;
        }
        else
        {
            output_data_string += buffer_char;
        }
    }

    return output_data_string;
};

std::string Tanja84dk::crypt::ceasar::decode(const int chipher_shift_key, const std::string &input_data)
{
    std::string output_data_string;

    char buffer_char;
    for (int i = 0; i != input_data.length(); i++)
    {
        buffer_char = input_data[i];
        if (buffer_char >= 'a' && buffer_char <= 'z')
        {
            buffer_char = buffer_char - chipher_shift_key;
            if (buffer_char < 'a')
            {
                buffer_char = buffer_char + 'z' - 'a' + 1;
            }
            output_data_string += buffer_char;
        }
        else if (buffer_char >= 'A' && buffer_char <= 'Z')
        {
            buffer_char = buffer_char - chipher_shift_key;
            if (buffer_char < 'A')
            {
                buffer_char = buffer_char + 'Z' - 'A' + 1;
            }
            output_data_string += buffer_char;
        }
        else
        {
            output_data_string += buffer_char;
        }
    }

    return output_data_string;
};

void Tanja84dk::crypt::ceasar::decode_brute_force(const std::string &input_data)
{
    for (int i = 0; i <= 27; i++)
    {
        std::cout << "Key: " << i << "\n"
                  << Tanja84dk::crypt::ceasar::decode(i, input_data) << "\n\n\n";
    }
}
