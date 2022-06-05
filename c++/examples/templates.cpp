#include <iostream>

/*
 * Los templates se pueden usar en variables, funciones, clases y etc...
 * Si el compilador puede deducirlos, no es necesario declararlos explicitamente.
 * */

template<typename T>
T sum ( T a, T b )
{
    return a + b;
}

template<typename T>
class pointer
{
    private:
        T* ptr;
    public:
        pointer ( ) = delete;
        pointer ( T value )
        {
            ptr = new T;
            *ptr = value;
        }
        ~pointer ( )
        {
            delete ptr;
        }
};

int main ( )
{
    //No es necesario escribir pointer<int> porque el propio cosntructor que usamos nos permite deducir el tipo.
    pointer num = 42;
    //De no explicitar en sum que queremos float, no sería capaz de compilar
    //  ya que '3.f' es float y '0.1416' es double.
    pointer pi = sum<float>( 3.f, 0.1416 );
    return 0;
}
