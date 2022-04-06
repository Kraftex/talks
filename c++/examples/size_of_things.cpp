#include <iostream>
#include <cinttypes>

#define USE_BITS false
#if defined(USE_BITS) && USE_BITS
#define show_sizeof(type) std::cout << "Type " #type ": " << sizeofb<type> << " bits\n"
template<typename T = char>
constexpr std::size_t sizeofb = sizeof(T) * 8;
#else
#define show_sizeof(type) std::cout << "Type " #type ": " << sizeof(type) << " bytes\n"
#endif

class Dummy
{
    //private por defecto
    unsigned id;
    public:
        Dummy ( )
        {
            std::cout << "[" << id << "] + ] Se acaba de crear la clase Dummy\n";
        }
        Dummy ( unsigned id )
        {
            this->id = id;
            std::cout << "[" << id << "] + ] Se acaba de crear la clase Dummy\n";
        }
        unsigned get_id ( )
        {
            return id;
        }
        void do_something ( )
        {
            std::cout << "[" << id << "] * ] Objeto Dummy haciendo cosas\n";
        }
        std::string to_string ( )
        {
            return "Dummy[" + std::to_string(id) + "]";
        }
        ~Dummy ( )
        {
            std::cout << "[" << id << "] - ] Se acaba de destruir la clase Dummy\n";
        }
};

struct Point2D
{
    float x, y;
    std::string to_string ( )
    {
        return "Point2D(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};

/*
 * Aquellos tipos donde se encuentra el comentario 'optional' significan
 *  que no tienen porque estar definidos por la librería usada...
 * */
//Si da problemas al compilar, poner OPTIONAL a false.
#define OPTIONAL true
int main ( )
{
    show_sizeof(bool);
    show_sizeof(char);
    show_sizeof(wchar_t);
    show_sizeof(char16_t);
    show_sizeof(char32_t);
    show_sizeof(short);
    show_sizeof(int);
    show_sizeof(long); //It's the same as 'long int'
    show_sizeof(float);
    show_sizeof(double);
    show_sizeof(long long); //It's the same as 'long long int'
    show_sizeof(long double);
    show_sizeof(void*);
    show_sizeof(Dummy);
    show_sizeof(Point2D);
    //Let's dig into INTs chaos.
    show_sizeof(intmax_t);
#if OPTIONAL
    show_sizeof(intptr_t); // optional
    show_sizeof(int8_t); // optional
    show_sizeof(int16_t); // optional
    show_sizeof(int32_t); // optional
    show_sizeof(int64_t); // optional
    show_sizeof(__int128_t); // optional, es posible que lance algun error sino está definido
#endif
    show_sizeof(int_least8_t);
    show_sizeof(int_least16_t);
    show_sizeof(int_least32_t);
    show_sizeof(int_least64_t);
    show_sizeof(int_fast8_t);
    show_sizeof(int_fast16_t);
    show_sizeof(int_fast32_t);
    show_sizeof(int_fast64_t);
    return 0;
}

/*
Resultado usando un Intel(R) Core(TM) i7-8550U
Compilado en GCC y Clang usando Linux (Elementary OS)

Type bool: 1 bytes
Type char: 1 bytes
Type wchar_t: 4 bytes
Type char16_t: 2 bytes
Type char32_t: 4 bytes
Type short: 2 bytes
Type int: 4 bytes
Type long: 8 bytes
Type float: 4 bytes
Type double: 8 bytes
Type long long: 8 bytes
Type long double: 16 bytes
Type void*: 8 bytes
Type Dummy: 4 bytes
Type Point2D: 8 bytes
Type intmax_t: 8 bytes
Type int8_t: 1 bytes
Type int16_t: 2 bytes
Type int32_t: 4 bytes
Type int64_t: 8 bytes
Type int_least8_t: 1 bytes
Type int_least16_t: 2 bytes
Type int_least32_t: 4 bytes
Type int_least64_t: 8 bytes
Type int_fast8_t: 1 bytes
Type int_fast16_t: 8 bytes
Type int_fast32_t: 8 bytes
Type int_fast64_t: 8 bytes
Type intptr_t: 8 bytes
*/
