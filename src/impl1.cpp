#include <iostream>
#include "functions.hpp"

extern "C"
{
    bool bruteforce(int n)
    {
        int i = 2;
        while (i * i <= n)
        {
            if (n % i == 0) return true;
            ++i;
        }
        return false;
    }

    int PrimeCount(int A, int B)
    {
        int count = 0;
        for (int i = A; i <= B; ++i)
        {
            if (not bruteforce(i)) count++;
        }
        return count;
    }
}

extern "C" 
{
    char* translation(long long x) 
    {
        char* num = new char[1000];
        char* rev = new char[1000];
        size_t i = 0;

        while (x != 0) 
        {
            int digit = x % 2;
            rev[i] = digit + 48;
            x /= 2;
            ++i;
        }

        for (size_t j = 0; j != i; ++j) num[j] = rev[i - j - 1];

        delete[] rev;

        return num;
    }
}
