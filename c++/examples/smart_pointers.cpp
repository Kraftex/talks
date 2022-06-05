#include <iostream>
#include <memory>

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
    friend std::ostream& operator<< ( std::ostream& os, Dummy dummy )
    {
        os << "Dummy [" << dummy.get_id( ) << "]";
        return os;
    }
    ~Dummy ( )
    {
        std::cout << "[" << id << "] - ] Se acaba de destruir la clase Dummy\n";
    }
};

int main ( )
{
    std::string dp2s;
    std::weak_ptr<Dummy> dpw;
    std::unique_ptr<Dummy> dp(std::make_unique<Dummy>( ));
    { //Nuevo ambito
        auto dp1(std::make_unique<Dummy>(1));
        dp1->do_something( );
        auto dp2{std::make_shared<Dummy>(2)};
        dpw = dp2;
        dp2s = dpw.lock( )->to_string( );
        std::cout << "Direccion de memoria de " << dp2s << ": " << dpw.lock( ) << '\n';
        std::cout << dp2->to_string( ) << '\n';
        std::cout << "Referencias de dp2: " << dpw.use_count( ) << '\n';
        {
            auto dp2cp = dp2;
            std::cout << "Referencias de dp2: " << dpw.use_count( ) << '\n';
            dp2cp->do_something( );
            //auto dp4 = dp1; //No se puede copiar un 'unique_ptr', su constructor está eliminado.
        }
    } //dp2, dp1 mueren
    std::cout << "Direccion de memoria de " << dp2s << ": " << dpw.lock( ) << '\n';
    std::cout << "Referencias de dp2: " << dpw.use_count( ) << '\n';
    auto dp3 = std::make_unique<Dummy>(3);
    return 0;
}
