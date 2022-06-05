

// Los valores se suelen escribir en mayúsculas
enum Action
{
    ATACK,
    DEFEND,
    RUN_AWAY,
    TAKE_A_OBJECT
};

enum class Type
{
    //Para poder recorrer todos los valores,
    //  se suele escribir un FIRST, LAST
    FIRST, //Tomara valor 0
    NORMAL = 0, //Hacemos que tome valor 0 para que sea indistingible de FIRST
    FIRE,
    WATER,
    GRASS,
    FLYING,
    FIGHTING,
    POISON,
    ELECTRIC,
    GROUND,
    ROCK,
    PSYCHIC,
    ICE,
    BUG,
    GHOST,
    STEEL,
    DRAGON,
    DARK,
    FAIRY,
    LAST
};

template<typename T, typename U>
union Mix
{
    T t;
    U u;
};

int main ( )
{
    Mix<int,float> mif;
    mif.u = 0.5f;
    Type t = Type::FIRE; //Se necesita Type para acceder a los posible valores
    int it = (int)t; //Necesidad de un cast explicito
    Action a = ATACK; //No se necesita Action para acceder a los posible valores
    int ia = a; //No hay necesidad de un cast explicito
    return 0;
}
