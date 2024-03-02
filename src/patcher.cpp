#include "patcher.hpp"
#include <iostream>

void Patcher::PatchPair(std::vector<char> &bytes, char A0, char A1, char B0, char B1, int &i)
{
    const size_t size = bytes.size();
    for (; i < size - 1; i++)
    {
        if (bytes[i] == A0 && bytes[i + 1] == A1)
        {
            bytes[i] = B0;
            bytes[i + 1] = B1;

            std::cout << "Patched bytes " << std::hex << (int)A0 << " " << (int)A1 << " to " << (int)B0 << " " << (int)B1 << " at offset " << std::hex << i << std::endl;
        }
    }
}

void Patcher::PatchTriplet(std::vector<char> &bytes, char A0, char A1, char A2, char B0, char B1, char B2, int &i)
{
    const size_t size = bytes.size();
    for (; i < size - 2; i++)
    {
        if (bytes[i] == A0 && bytes[i + 1] == A1 && bytes[i + 2] == A2)
        {
            bytes[i] = B0;
            bytes[i + 1] = B1;
            bytes[i + 2] = B2;

            std::cout << "Patched bytes " << std::hex << (int)A0 << " " << (int)A1 << " " << (int)A2 << " to " << (int)B0 << " " << (int)B1 << " " << (int)B2 << " at offset " << std::hex << i << std::endl;
        }
    }
}

void Patcher::PatchQuintet(std::vector<char> &bytes, char A0, char A1, char A2, char A3, char A4, char B0, char B1, char B2, char B3, char B4, int &i)
{
    const size_t size = bytes.size();

    for (; i < size - 4; i++)
    {
        if (bytes[i] == A0 && bytes[i + 1] == A1 && bytes[i + 2] == A2 && bytes[i + 3] == A3 && bytes[i + 4] == A4)
        {
            bytes[i] = B0;
            bytes[i + 1] = B1;
            bytes[i + 2] = B2;
            bytes[i + 3] = B3;
            bytes[i + 4] = B4;

            std::cout << "Patched bytes " << std::hex << (int)A0 << " " << (int)A1 << " " << (int)A2 << " " << (int)A3 << " " << (int)A4 << " to " << (int)B0 << " " << (int)B1 << " " << (int)B2 << " " << (int)B3 << " " << (int)B4 << " at offset " << std::hex << i << std::endl;
        }
    }
}