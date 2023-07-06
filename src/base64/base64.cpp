#include <Tanja84dk/crypt/base64/base64.h>
#include <string>
#include <sstream>

#include <base64.h>

std::string Tanja84dk::crypt::base64::decode(const std::string &input_data)
{
    return base64_decode(input_data);
}

std::string Tanja84dk::crypt::base64::encode(const std::string &input_data)
{
    return base64_encode(input_data);
}

std::ofstream Tanja84dk::crypt::base64::decode(const std::ifstream &input_file_handler) noexcept
{
    std::stringstream buffer_input_sstream = {};
    buffer_input_sstream.clear();
    std::ofstream output_file_handler;
    while (input_file_handler.good())
    {
        buffer_input_sstream << input_file_handler.rdbuf();
    }
    base64_decode(buffer_input_sstream.str());

    return output_file_handler;
}

std::ofstream Tanja84dk::crypt::base64::encode(const std::ifstream &input_file_handler) noexcept
{
    std::stringstream buffer_input_sstream = {};
    buffer_input_sstream.clear();
    std::ofstream output_file_handler;
    while (input_file_handler.good())
    {
        buffer_input_sstream << input_file_handler.rdbuf();
    }
    base64_decode(buffer_input_sstream.str());

    return output_file_handler;
}
