#include <iostream>

[[deprecated("Mejor usar gato_gordo")]]
void gato ( )
{
    std::cout << "Miau\n";
}

void gato_gordo ( )
{
    std::cout << "Miauu\n";
}

int main ( )
{
    gato( );
    return 0;
}
