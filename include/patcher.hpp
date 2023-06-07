#ifndef PATCHER_HPP
#define PATCHER_HPP

#include <vector>

class Patcher
{
public:
    static void PatchPair(std::vector<char> &bytes, char A0, char A1, char B0, char B1, int &i);
    static void PatchTriplet(std::vector<char> &bytes, char A0, char A1, char A2, char B0, char B1, char B2, int &i);
    static void PatchQuintet(std::vector<char> &bytes, char A0, char A1, char A2, char A3, char A4, char B0, char B1, char B2, char B3, char B4, int &i);
};

#endif // PATCHER_HPP