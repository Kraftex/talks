#include <iostream>

auto square ( int n )
{
    return n*n;
}

auto fibonacci ( int n )
{
    if ( n < 2 )
        return n;
    return fibonacci( n - 1 ) + fibonacci( n - 2 );
}

int main ( )
{
    std::cout << "square(2) -> " << square(2) << '\n';
    std::cout << "square(4) -> " << square(4) << '\n';
    std::cout << "square(6) -> " << square(6) << '\n';
    std::cout << "square(8) -> " << square(8) << '\n';
    std::cout << "fibonacci(2) -> " << fibonacci(2) << '\n';
    std::cout << "fibonacci(5) -> " << fibonacci(5) << '\n';
    std::cout << "fibonacci(8) -> " << fibonacci(8) << '\n';
    std::cout << "fibonacci(20) -> " << fibonacci(20) << '\n';
    return 0;
}
