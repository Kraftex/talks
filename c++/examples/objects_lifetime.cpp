#include <iostream>

class Dummy
{
    private:
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
        ~Dummy ( )
        {
            std::cout << "[" << id << "] - ] Se acaba de destruir la clase Dummy\n";
        }
};

int main ( )
{
    std::cout << "Main Starts\n";
    Dummy d1; //Se crea la clase, con el constructor por defecto.
    { //Crear un ambito, donde se verá que los objetos solo permanecen 'vivos' mientras existe el 'ámbito'.
        Dummy d1(1); //Al ser otro ámbito puedo crear una variable del mismo nombre.
    }
    Dummy d2(2);
    Dummy* d3 = new Dummy(3);
    Dummy* d4 = new Dummy(4);
    std::cout << "Main Ends\n";
    delete d4;
    return 0;
}
// d1 y d2 desaparecen.
// d3, no porque no se le ha hecho un delete.
// Si se hicieran operaciones con un archivo y este no se hubiera cerrado, se cierra.
