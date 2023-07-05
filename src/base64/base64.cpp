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

void Tanja84dk::crypt::base64::myBase64Decoding()
{
    std::string input_filename_string;
    std::string output_filename_string;
    std::string output_data_string;

    printf("Enter the filename: ");
    std::getline(std::cin >> std::ws, input_filename_string);
    std::cout << std::endl;

    if (Tanja84dk::tools::file_exists(input_filename_string))
    {
        // outputData = Base64::Decode(Tanja84dk::tools::readFile(inputFilename));
        output_data_string = base64_decode(Tanja84dk::tools::read_file(input_filename_string));

        // Could not get printf to work with the Base64 decoding, guess its a incoding issue.
        // Falling back to cout until issue is located
        std::cout << output_data_string << std::endl;

        output_filename_string = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-" + input_filename_string + "-Decoded-Base64.txt";
        if (!Tanja84dk::tools::file_exists(output_filename_string))
        {
            Tanja84dk::tools::write_file(output_data_string, output_filename_string);
            printf("The output is also written to a file called %s in the folder you have the program in\n", output_filename_string.c_str());
        }
    };
}

void Tanja84dk::crypt::base64::myBase64Decoding(const std::string &input_data)
{
    std::string output_data_string;
    std::string output_filename_string;
    output_data_string = base64_decode(input_data);

    printf("\n%s\n", output_data_string.c_str());

    output_filename_string = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Decoded-Base64.txt";
    if (Tanja84dk::tools::file_exists(output_filename_string) == false)
    {
        Tanja84dk::tools::write_file(output_data_string, output_filename_string);
        printf("The output is also written to a file called %s in the folder you have the program in\n", output_filename_string.c_str());
    }
}

void Tanja84dk::crypt::base64::myBase64DecodingString(void)
{
    printf("Enter the string");
    std::string input_data_string;
    std::getline(std::cin >> std::ws, input_data_string);
    std::string output_data_string;
    std::string output_filename_string;

    output_data_string = base64_decode(input_data_string);

    printf("\n%s\n", output_data_string.c_str());

    output_filename_string = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-From_String-Decoded-Base64.txt";
    if (Tanja84dk::tools::file_exists(output_filename_string) == false)
    {
        Tanja84dk::tools::write_file(output_data_string, output_filename_string);
        printf("The output is also written to a file called %s in the folder you have the program in\n", output_filename_string.c_str());
    };
};

void myBase64Encoding(void)
{
    std::string inputFilename;
    printf("Enter Filename: ");
    std::getline(std::cin >> std::ws, inputFilename);
    std::string outputData;
    std::string outputFilename;

    outputData = base64_encode(Tanja84dk::tools::read_file(inputFilename));

    printf("\n%s\n", outputData.c_str());

    outputFilename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-" + inputFilename + "-Encoded-Base64.txt";
    if (Tanja84dk::tools::file_exists(outputFilename) == false)
    {
        Tanja84dk::tools::write_file(outputData, outputFilename);
        printf("The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str());
    }
};

void myBase64Encoding(const std::string &data)
{
    bool statusCode;
    std::string outputData;
    std::string outputFilename;

    outputData = base64_encode(data);

    printf("\n%s\n", outputData.c_str());

    outputFilename = Tanja84dk::tools::get_timestamp("%Y%m%d_%H%M%S") + "-Manual-Input-Encoded-Base64.txt";
    if (Tanja84dk::tools::file_exists(outputFilename) == false)
    {
        Tanja84dk::tools::write_file(outputData, outputFilename);
        printf("The output is also written to a file called %s in the folder you have the program in\n", outputFilename.c_str());
    }
}
