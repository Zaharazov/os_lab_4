#include <iostream>
#include "functions.hpp"

extern "C"
{
    int PrimeCount(int A, int B)
    {
        bool sieve[B];
        int count = 0;

        for (int i = 1; i <= B; i++) sieve[i] = true;    // Изначально все числа не вычеркнуты.

        for (int i = 2; i <= B; i++)
        {
            if (sieve[i])
            { // если i не вычеркнуто
                if (i >= A) count++;

                for (int j = i * i; j <= B; j += i) sieve[j] = false;   // вычеркиваем все кратные числа начиная с i^2
            }
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
            int digit = x % 3;
            rev[i] = digit + 48;
            x /= 3;
            ++i;
        }

        for (size_t j = 0; j != i; ++j) num[j] = rev[i - j - 1];

        delete[] rev;

        return num;
    }
}
