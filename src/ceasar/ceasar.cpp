

#include <Tanja84dk/crypt/ceasar/ceasar.h>
#include <Tanja84dk/crypt/pxx.h>

#include <iostream>
#include <string>

std::string Tanja84dk::crypt::Caesar::encode(const int cipher_shift_key, const std::string &input_data) const noexcept {
    std::string output_data_string;

    char buffer_char;
    for (int i = 0; i != input_data.length(); i++) {
        buffer_char = input_data[i];

        if (buffer_char >= 'a' && buffer_char <= 'z') {
            buffer_char = buffer_char + cipher_shift_key;

            if (buffer_char > 'z') {
                buffer_char = buffer_char - 'z' + 'a' - 1;
            }

            output_data_string += buffer_char;

        } else if (buffer_char >= 'A' && buffer_char <= 'Z') {
            buffer_char = buffer_char + cipher_shift_key;

            if (buffer_char > 'Z') {
                buffer_char = buffer_char - 'Z' + 'a' - 1;
            }

            output_data_string += buffer_char;
        } else {
            output_data_string += buffer_char;
        }
    }
    return output_data_string;
};

std::string Tanja84dk::crypt::Caesar::decode(const int cipher_shift_key, const std::string &input_data) const noexcept {
    std::string output_data_string;

    char buffer_char;
    for (int i = 0; i != input_data.length(); i++) {
        buffer_char = input_data[i];

        if (buffer_char >= 'a' && buffer_char <= 'z') {
            buffer_char = buffer_char - cipher_shift_key;

            if (buffer_char < 'a') {
                buffer_char = buffer_char + 'z' - 'a' + 1;
            }

            output_data_string += buffer_char;

        } else if (buffer_char >= 'A' && buffer_char <= 'Z') {
            buffer_char = buffer_char - cipher_shift_key;

            if (buffer_char < 'A') {
                buffer_char = buffer_char + 'Z' - 'A' + 1;
            }

            output_data_string += buffer_char;
        } else {
            output_data_string += buffer_char;
        }
    }
    return output_data_string;
};

void Tanja84dk::crypt::Caesar::decode_brute_force(const std::string &input_data) {
    for (int i = 0; i <= 27; i++) {
        std::cout << "Key: " << i << "\n" << this->decode(i, input_data) << "\n\n\n";
    }
}
