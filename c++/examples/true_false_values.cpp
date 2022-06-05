#include <iostream>

#define true_false_value(val) true_false_value_( val, #val )
#define true_false_value_(val, str) std::cout << str << "]: " << (val? "true\n" : "false\n")

class Dummy
{
    //private por defecto
    unsigned id;

    public:
    Dummy ( ) : Dummy(0) { }
    Dummy ( unsigned id )
    {
        this->id = id;
        //std::cout << "[" << id << "] + ] Se acaba de crear la clase Dummy\n";
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
        //std::cout << "[" << id << "] - ] Se acaba de destruir la clase Dummy\n";
    }
    // No necesita poner el tipo, ya que se sabe que se está cambiando a 'bool'
    // Esto se hace así, para poder comprobar con un if, si se puede usar el objeto.
    operator bool ( )
    {
        return id != 0;
    }
};

int main ( )
{
    Dummy d0, d1(1);
    true_false_value(false);
    true_false_value(true);
    true_false_value(10000);
    true_false_value(NULL);
    true_false_value(nullptr);
    true_false_value(0.f);
    true_false_value(0.1f);
    true_false_value(0.0);
    true_false_value(0.1);
    true_false_value('\0');
    true_false_value('a');
    true_false_value("");
    true_false_value("Hola");
    true_false_value(d0);
    true_false_value(d1);
    return 0;
}
