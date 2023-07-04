

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>

#include <Tanja84dk/crypt/binary/binary.h>
#include <Tanja84dk/tools/tools.h>

template <size_t N>
std::vector<std::bitset<N>> encoding(const char *input_filename)
{
    std::string buffer_input_string;

    std::vector<std::bitset<N>> binary_output_vector;
    binary_output_vector.reserve(100);

    std::ifstream file_handler(input_filename, std::ifstream::in);
    file_handler.seekg(0, std::ios::end);
    buffer_input_string.reserve(file_handler.tellg());
    file_handler.seekg(0, std::ios::beg);
    buffer_input_string.assign((std::istreambuf_iterator<char>(file_handler)),
                               std::istreambuf_iterator<char>());

    for (std::size_t i = 0; i < buffer_input_string.size(); i++)
    {
        binary_output_vector.push_back(std::bitset<8>(buffer_input_string.c_str()[i]));
    }

    return binary_output_vector;
}

void encoding(const std::string &data)
{
    std::vector<std::bitset<8>> binaryOutputVector;
    std::string outputFilename;

    for (std::size_t i = 0; i < int(data.size()); i++)
    {
        binaryOutputVector.push_back(std::bitset<8>(data.c_str()[i]));
    }

    outputFilename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Encoded-8Bit-Binary.txt";

    if (!Tanja84dk::tools::file_exists(outputFilename))
    {
        Tanja84dk::tools::write_file(binaryOutputVector, outputFilename);
        printf("The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str());
    }
}

/*
void decoding_string(const std::string &inputFilename)
{

    std::string outputFilename;
    std::string buffer_input_string;
    std::string outputData;
    outputFilename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-" + inputFilename + "-Binary-Decoded.txt";

    if (Tanja84dk::tools::file_exists(inputFilename) == true)
    {
        std::ifstream inputFileHandler(inputFilename, std::ifstream::in);
        inputFileHandler.seekg(0, std::ios::end);
        buffer_input_string.reserve(inputFileHandler.tellg());
        inputFileHandler.seekg(0, std::ios::beg);
        buffer_input_string.assign((std::istreambuf_iterator<char>(inputFileHandler)),
                                   std::istreambuf_iterator<char>());

        std::stringstream binaryStringStream(buffer_input_string);

        while (binaryStringStream.good())
        {
            std::bitset<8> bits;
            binaryStringStream >> bits;
            char characterDecoded = char(bits.to_ulong());
            outputData += characterDecoded;
        }

        printf("\n%s\n", outputData.c_str());
    }

    if (Tanja84dk::tools::file_exists(outputFilename) == false)
    {
        Tanja84dk::tools::write_file(outputData, outputFilename);
        printf("The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str());
    }
}
*/