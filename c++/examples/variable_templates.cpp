#include <iostream>
#include <string>

template<typename T = double>
constexpr T pi = T(3.141592653589793238462643383);

template<> // Especializar el 'template'.
constexpr const char* pi<const char*> = "pi";
template<> // Especializar el 'template'.
std::string pi<std::string> = "PI";

double tau ( )
{
    return 2.0*pi<>;
    //return 2.0*pi; // In C++17
}

int main ( )
{
    std::cout << "PI: " << pi<long> << '\n';
    std::cout << "&PI: " << &pi<> << '\n';
    std::cout << "&PI: " << &pi<float> << '\n';
    std::cout << "&PI: " << &pi<long> << '\n';
    return 0;
}
