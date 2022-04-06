#include <iostream>
#include <string>
#include <vector>


template<typename T>
void show ( std::vector<T> );

// Existe en el header file 'algorithm'
template<typename T, typename F>
void transform ( std::vector<T>&, const F& );

int main ( )
{
    std::vector<int> arr{ 1, 2, 3, 4, 5 };
    std::vector<int> arr2(arr);
    std::vector<int> arr1(arr);
    transform( arr1, []( auto x ){ return (x+x)*x; } );
    transform( arr2, []( auto x ){ return x*2; } );
    std::cout << "x = ";
    show(arr);
    std::cout << "x * 2 = ";
    show(arr2);
    std::cout << "(x+x)*x = ";
    show(arr1);
    return 0;
}

template<typename T, typename F>
void transform ( std::vector<T>& vec, const F& func )
{
    for( T& v: vec )
    {
        v = func(v);
    }
}

template<typename T>
void show ( std::vector<T> vec )
{
    bool first = false;
    std::cout << "[ ";
    for( T v: vec )
    {
        if (!first)
        {
            std::cout << v;
            first = true;
        }
        else
        {
            std::cout << ", " << v;
        }
    }
    std::cout << " ]\n";
}
