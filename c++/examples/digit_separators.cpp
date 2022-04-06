#include <iostream>

int main ( )
{
    int kilo = 1'000;
    int mega = 1'000'000;
    long giga = 1'000'000'000;
    float pi = 3.1'4'1'5;
    //float pi = 3.1'4'1'5'; // Error
    //float pi = 3'.1'4'1'5;
    std::cout << "kilo: " << kilo << '\n';
    std::cout << "mega: " << mega << '\n';
    std::cout << "giga: " << giga << '\n';
    std::cout << "pi: " << pi << '\n';
    return 0;
}
