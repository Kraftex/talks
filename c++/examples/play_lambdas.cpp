#include <iostream>
#include <functional>


//sum generic, using generic lambda functions. Available for C++14 and above
auto sum_gen = []( auto a, auto b ){ return a + b; };

//sum generic, using lambda functions with templates. Available for C++11 and above
template<typename T, typename D>
std::function<decltype(std::declval<T>()+std::declval<D>())(T, D)> sum_gen1 = []( T a, D b ) -> decltype(a+b) { return a + b; };

//sun generic, using template functions. Available for C++14 and above
template<typename T, typename D>
auto sum_gen2 ( T t, D d )
{
    return t + d;
}
//Para C++14, no es necesario escribir '-> returnType' porque sabe sacar el tipo de la expresión al usar solo auto

//sun generic, using template functions. Available for C++11 and above
template<typename T, typename D>
auto sum_gen3 ( T t, D d ) -> decltype(t+d)
{
    return t + d;
}
//Obligatorio usar el 'decltype(expr)' despues, ya que es otra forma de declarar funciones en C++
//  auto funcName ( args... ) -> returnType

#define show_value(x) std::cout << #x " -> " << x << '\n'

int main ( )
{
    auto f = []( int n ){ return n*2; };
    //En Java sería:
    //  UnaryOperator<Integer> f = n -> n*2;
    //  UnaryOperator<Integer> f = (n) -> {return n*2;};
    //  var f = (UnaryOperator<Integer>) n -> n*2; //Se debe de hacer el casteo si o si
    //  int value = f.apply(45); //Para usarlo hay que llamar a 'apply'.
    std::function<int(int)> ff = []( int n )/* -> int */{ return n+n/2; };
    //No es necesario decir el tipo, se infiere segun el return
    std::function<int(int, int)> sum = [](int a, int b){return a+b;};


    int i = 0;
    long nf = 3;
    int nff = 3;
    while( i++ < 10 )
    {
        std::cout << "sum_gen(" << nf << ", " << nff << ") -> " << sum_gen1<decltype(nf), decltype(nff)>(nf, nff) << "\n";
        std::cout << "f(" << nf << ") -> " << (nf = f(nf)) << "\n";
        std::cout << "ff(" << nff << ") -> " << (nff = ff(nff)) << "\n";
    }
    show_value(sum_gen(23, 4.5));
    return 0;
}
