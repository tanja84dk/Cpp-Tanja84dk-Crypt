#include <Tanja84dk/crypt/base64/base64.h>

#include <iostream>
#include <string>

#include <base64.h>

std::string Tanja84dk::crypt::base64::decode(const std::string &input_data)
{
    return base64_decode(input_data);
}

std::string Tanja84dk::crypt::base64::encode(const std::string &input_data)
{
    return base64_encode(input_data);
}
