#include <dlfcn.h>
#include <iostream>

int main()
{
    std::cout << "This program is linking libraries during runtime. Select an action: " << std::endl
              << "\"0\" - Change implementation." << std::endl
              << "\"1\" - Count prime nums." << std::endl
              << "\"2\" - Translate number from decimal to other system." << std::endl
              << "\"-1\" - Exit." << std::endl
              << "Input instruction: ";

    int option;
    std::cin >> option;

    int impl = 1;
    auto handle = dlopen("libimpl1.dylib", RTLD_LAZY);

    char* error;
    error = dlerror();
    if (error) 
    {
        std::cerr << error << std::endl;
        return 1;
    }

    int (*prime)(int, int);
    prime = reinterpret_cast<decltype(prime)>(dlsym(handle, "PrimeCount"));
    error = dlerror();
    if (error)
    {
        std::cerr << error << std::endl;
        return 1;
    }

    char* (*translation)(long long);
    translation = reinterpret_cast<decltype(translation)>(dlsym(handle, "translation"));
    error = dlerror();
    if (error) 
    {
        std::cerr << error << std::endl;
        return 1;
    }

    while (option != -1) 
    {
        switch (option) 
        {
            case 0:
                dlclose(handle);
                error = dlerror();
                if (error) 
                {
                    std::cerr << error << std::endl;
                    return 1;
                }

                switch (impl) 
                {
                    case 1:
                        impl = 2;
                        handle = dlopen("libimpl2.dylib", RTLD_LAZY);
                        break;

                    case 2:
                        int impl = 1;
                        handle = dlopen("libimpl1.dylib", RTLD_LAZY);
                        break;
                }

                char* error;
                error = dlerror();
                if (error) 
                {
                    std::cerr << error << std::endl;
                    return 1;
                }

                prime = reinterpret_cast<decltype(prime)>(dlsym(handle, "PrimeCount"));
                error = dlerror();
                if (error)
                {
                    std::cerr << error << std::endl;
                    return 1;
                }

                translation = reinterpret_cast<decltype(translation)>(dlsym(handle, "translation"));
                error = dlerror();
                if (error) 
                {
                    std::cerr << error << std::endl;
                    return 1;
                }

                std::cout << "Implementation switched" << std::endl << "Input instruction: ";
                std::cin >> option;
                break;

            case 1:
                int A, B;
                std::cin >> A >> B;
                std::cout << "The count is: " << prime(A, B) << std::endl << "Input instruction: ";
                std::cin >> option;
                break;

            case 2:
                long num;
                std::cin >> num;
                std::cout << "The num in other system is: " << translation(num) << std::endl << "Input instruction: ";
                std::cin >> option;
                break;

            default:
                option = -1;
        }
    }

    dlclose(handle);
    error = dlerror();
    if (error) 
    {
        std::cerr << error << std::endl;
        return 1;
    }
    return 0;
}
