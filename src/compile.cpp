#include <iostream>
#include "functions.hpp"

int main()
{
    std::cout << "This program is linking libraries during compilation. Select an action: " << std::endl
              << "\"1\" - Count prime nums." << std::endl
              << "\"2\" - Translate number from decimal to other system." << std::endl
              << "\"-1\" - Exit." << std::endl
              << "Input instruction: ";

    int option;
    std::cin >> option;

    while (option != -1) 
    {
        switch (option) 
        {
            case 1:
                int A, B;
                std::cin >> A >> B;
                std::cout << "The count is: " << PrimeCount(A, B) << std::endl << "Input instruction: ";
                std::cin >> option;
                break;

            case 2:
                long long num;
                std::cin >> num;
                std::cout << "The num in other system is: " << translation(num) << std::endl << "Input instruction: ";
                std::cin >> option;
                break;

            default:
                option = -1;
        }
    }
    return 0;
}
