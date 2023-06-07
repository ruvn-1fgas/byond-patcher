#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>

#include <patcher.hpp>

int main(int argc, char **argv)
{
    std::string ds_path = "dreamseeker.exe";
    if (argc > 1 && std::filesystem::exists(argv[1]))
    {
        ds_path = argv[1];
    }
    else
    {
        std::cout << "Input path to dreamseeker.exe: ";
        std::getline(std::cin, ds_path);
    }

    if (!std::filesystem::exists(ds_path))
    {
        std::cout << "Error: " << ds_path << " does not exist." << std::endl;
        return 1;
    }

    std::cout << "Path to dreamseeker.exe: " << ds_path << std::endl;

    // read all bytes from dreamseeker.exe
    std::ifstream ds_file(ds_path, std::ios::binary);

    std::vector<char> ds_bytes((std::istreambuf_iterator<char>(ds_file)), std::istreambuf_iterator<char>());
    ds_file.close();

    std::vector<char> ds_new_bytes = ds_bytes;

    int position = 0;
    Patcher::PatchTriplet(ds_new_bytes, 0x0f, 0x45, 0xf9, 0x89, 0xCF, 0x90, position);
    Patcher::PatchPair(ds_new_bytes, 0x74, 0x48, 0x90, 0x90, position);
    Patcher::PatchQuintet(ds_new_bytes, 0x0f, 0x84, 0x44, 0x02, 0x00, 0x90, 0x90, 0x90, 0x90, 0x90, position);
    Patcher::PatchPair(ds_new_bytes, 0x74, 0x4A, 0x90, 0x90, position);
    Patcher::PatchPair(ds_new_bytes, 0x74, 0x3F, 0x90, 0x90, position);
    Patcher::PatchPair(ds_new_bytes, 0x74, 0x0E, 0x90, 0x90, position);
    Patcher::PatchPair(ds_new_bytes, 0x74, 0x0E, 0x90, 0x90, position);
    Patcher::PatchPair(ds_new_bytes, 0x74, 0x4F, 0x90, 0x90, position);

    // get number of changed bytes
    int changed_bytes = 0;
    for (int i = 0; i < ds_bytes.size(); i++)
    {
        if (ds_bytes[i] != ds_new_bytes[i])
        {
            changed_bytes++;
        }
    }

    std::cout << "Changed " << changed_bytes << " bytes." << std::endl;

    std::ofstream ds_new_file(ds_path, std::ios::binary);
    ds_new_file.write(ds_new_bytes.data(), ds_new_bytes.size());
    ds_new_file.close();

    std::cout << ds_path << '\n';

    std::cout << "Press enter to exit." << std::endl;
    std::cin.get();
}