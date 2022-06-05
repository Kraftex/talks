#include <iostream>

#define macro(x,y)\
    ({\
     int z = x + y;\
     z;\
     })
#define VERBOSE_POINT false

class Point
{
    int x;
    int y;
    #if defined(VERBOSE_POINT) && VERBOSE_POINT
    int id;
    #endif

    public:
    const static Point ORIGIN;
    #if defined(VERBOSE_POINT) && VERBOSE_POINT
    static int ID;
    #endif
    Point ( ) = default; //Dejo al compilador que decida hacer el constructor, que pondrá todo 0.
    Point ( int x, int y ) //: x{x}, y{y} { } //Otra forma de hacer lo mismo
    {
        this->x = x;
        this->y = y;
        #if defined(VERBOSE_POINT) && VERBOSE_POINT
        id = ID;
        ID++;
        #endif
    }
    //Una posible implementación del constructor copia sería
    //  Point ( const Point& p ) : Point( p.x, p.y ) { }
    Point ( const Point& p ) //Constructor para lvalues y rvalues, a.k.a Constructor Copia
    {
        #if defined(VERBOSE_POINT) && VERBOSE_POINT
        std::cout << "[" << ID << "] Constructor copia\n";
        #endif
        this->x = p.x;
        this->y = p.y;
        #if defined(VERBOSE_POINT) && VERBOSE_POINT
        id = ID++;
        #endif
    }
    // Este otro constructor, no tiene mucho sentido aquí pero es el que sirve para
    //  los rvalues en especificos. Al definir este, el otro no será llamado.
    Point ( Point&& p )
    {
        #if defined(VERBOSE_POINT) && VERBOSE_POINT
        std::cout << "[" << ID << "] Constructor move\n";
        #endif
        this->x = p.x;
        this->y = p.y;
        #if defined(VERBOSE_POINT) && VERBOSE_POINT
        id = ID++;
        #endif
    }
    //Estos últimos dos constructores también se pueden definir de la siguiente forma
    //  dejando al compilador a cargo de hacer lo que le pedimos.
    //Point ( const Point& ) = default;
    //Point ( Point&& ) = default;
    friend Point operator+ ( Point lhs, const Point& rhs )
    {
        //return Point( lhs.x + rhs.x, lhs.y + rhs.y );
        #if defined(VERBOSE_POINT) && VERBOSE_POINT
        std::cout << "[" << ID << "] lhs.id: " << lhs.id << "\n";
        #endif
        lhs.x += rhs.x;
        lhs.y += rhs.y;
        return lhs;
    }
    // lhs: left hand side
    // rhs: right hand side
    //Con solo implementar < y == como operadores, el resto salen derivandose de esos
    friend inline bool operator== ( const Point& lhs, const Point& rhs )
    {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
    //También se pueden implementar más parecido a Java
    //  bool operator< ( const Point& rhshs )
    friend inline bool operator< ( const Point& lhs, const Point& rhs )
    {
        return lhs.x < rhs.x && lhs.y < rhs.y;
    }
    //
    friend std::ostream& operator<< (std::ostream& os, const Point& rhs)
    {
        return os << "(" << rhs.x << ", " << rhs.y << ")";
    }
    // Si te cuesta mucho aprenderte esto, C++ provee una librería para hacerlo más fácil.
    // Usando <utility>
    // Y poniendo: using namespace std::rel_ops;
    //  Dentro de un ámbito (scope)
    /* Otra forma de implementarlos pero no es la recomendada
    inline bool operator!= ( const Point& rhs )
    {
        return !(*this == rhs);
    }*/
    friend inline bool operator!= ( const Point& lhs, const Point& rhs )
    {
        return !(lhs == rhs);
    }
    friend inline bool operator> ( const Point& lhs, const Point& rhs )
    {
        return rhs < lhs;
    }
    friend inline bool operator<= ( const Point& lhs, const Point& rhs )
    {
        return !(lhs > rhs);
    }
    friend inline bool operator>= ( const Point& lhs, const Point& rhs )
    {
        return !(lhs < rhs);
    }
    #if defined(VERBOSE_POINT) && VERBOSE_POINT
    ~Point ( )
    {
        std::cout << "[" << id << "] Died\n";
    }
    #endif
    //Se pueden declarar dentro y definir a fuera
    friend Point operator/ ( Point& lhs, int rhs );
    friend Point operator/ ( Point&& lhs, int rhs );
};
const Point Point::ORIGIN = Point( );
#if defined(VERBOSE_POINT) && VERBOSE_POINT
int Point::ID = 0;
#endif

//Para los lvalue
Point operator/ ( Point& lhs, int rhs )
{
    Point res = lhs;
    res.x /= rhs;
    res.y /= rhs;
    return res;
}

//Para los rvalue
Point operator/ ( Point&& lhs, int rhs )
{
    Point res = lhs;
    res.x /= rhs;
    res.y /= rhs;
    return res;
}
//Si se usara 'const Point&' como tipo, valdría tanto para lvalues y rvalues

//Encapsulamos la expresion por si hubiera problemas con la precedencia de los operadores
#define show(expr) #expr ": " << (expr)
int main ( )
{
    //macro(macro(2,4), 6);
    std::cout << std::boolalpha; //Activar que se escriba true o false, en vez de 1 o 0
    const Point org = Point::ORIGIN;
    Point a( 3, 4 );
    Point b{ 2, -9 };
    Point c = Point{2, 3};
    Point d = a + b + c;
    Point e = d + c;
    std::cout << "org: " << org << '\n';
    std::cout << "ORIGIN: " << Point::ORIGIN << '\n';
    std::cout << "a + b: " << d << '\n';
    std::cout << show(a == b) << '\n';
    std::cout << show((a + b) == (a + b)) << '\n';
    std::cout << "d + c: " << e << '\n';
    std::cout << show(b) << '\n';
    std::cout << show(b / 2) << '\n'; //Se ejecuta la que está diseñada para los lvalue
    std::cout << show(b) << '\n';
    std::cout << show((b + b) / 2) << '\n'; //Se ejecuta la que está diseñada para los rvalue
    std::cout << show(b) << '\n';
    std::cout << show(Point( 20, 40 ) / 2) << '\n'; //Se ejecuta la que está diseñada para los rvalue
    std::cout << show(Point( 20, 40 ) + b) << '\n';
    //std::cout << show(2 / b) << '\n'; //No está definido esto y por tanto lanza el error
    return 0;
}
