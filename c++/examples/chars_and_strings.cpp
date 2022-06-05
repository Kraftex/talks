#include <iostream>
#include <string>

//using namespace std::string_literals; // enables s-suffix for std::string literals

#define show_sizeof(var) std::cout << "Var " #var ": " << sizeof(var) << " bytes\n"
#define show_var(var, where) where << "Var " #var ": " << var << '\n'
#define show_func(var, call_func) std::cout << "Var " #var "." #call_func ": " << var.call_func << '\n'

typedef bool boolean;

int main ( )
{
    //auto S0 = "hello"s; // std::string
    char c = 'c';
    char16_t c16 = u'c';
    char32_t c32 = U'c';
    wchar_t wc = L'c';
    show_sizeof(c);
    show_sizeof(c16);
    show_sizeof(c32);
    show_sizeof(wc);
    show_var(c, std::cout);
    show_var(c16, std::cout);
    show_var(c32, std::wcout);
    show_var(wc, std::wcout);
    // Sus vertientes de string, vamos a poner un bonito pangrama
    const std::string s = "El pingüino Wenceslao hizo kilómetros bajo exhaustiva lluvia y frío, añoraba a su querido cachorro.";
    const std::u16string s16 = u"El pingüino Wenceslao hizo kilómetros bajo exhaustiva lluvia y frío, añoraba a su querido cachorro.";
    const std::u32string s32 = U"El pingüino Wenceslao hizo kilómetros bajo exhaustiva lluvia y frío, añoraba a su querido cachorro.";
    const std::wstring ws = L"El pingüino Wenceslao hizo kilómetros bajo exhaustiva lluvia y frío, añoraba a su querido cachorro.";
    //uint_fast16_t i = 0;
    //std::uint_fast16_t i_f = 89;
    show_var(s, std::cout);
    //show_var(s16, std::wcout);
    //show_var(s32, std::wcout);
    show_var(ws, std::wcout);
    show_func(s,   size());
    show_func(s16, size());
    show_func(s32, size());
    show_func(ws,  size());
    show_func(s,   length());
    show_func(s16, length());
    show_func(s32, length());
    show_func(ws,  length());
    //std::cout << "Size: " << "hola"s.size( ) << "\n";
    return 0;
}
