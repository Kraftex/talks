#include <iostream>
#include <limits>

union louble
{
    long l;
    double d;
    void* p;
    louble ( ) : l(0L) { }
    louble ( long l ) : l(l) { }
    louble ( double d ) : d(d) { }
    operator long ( )
    {
        return l;
    }
    operator double ( )
    {
        return d;
    }
};

struct Louble
{
    louble v;
    Louble ( long l )
    { v = l; }
    Louble ( double d )
    { v = d; }
    Louble ( louble ld )
    { v = ld; }
    operator double ( )
    {
        return v;
    }
    operator long ( )
    {
        return v;
    }
};

louble operator~ ( louble ld )
{
    return {~ld.l};
}

Louble operator~ ( Louble d )
{
    return {~d.v};
}

Louble exp ( Louble ld )
{
    return (long(ld) & 0x7ff0000000000000) >> 52;
}

Louble g_exp ( Louble ld )
{
    return exp(ld).v.l - 1023;
}

Louble mantisa ( Louble ld )
{
    return (long(ld) & 0x000fffffffffffff);
}

Louble g_mantisa ( Louble ld )
{
    return (long(ld) & 0x000fffffffffffff);
}

int main ( )
{
    double d = 0.0;
    for ( int i = 0;  i < 101; i++ )
    {
        Louble ld(d);
        std::cout << d << " -> " << (double)~ld << '\n';
        d = d + 0.01;
    }
    d = 0.00;
    for ( int i = 0;  i < 100; i++ )
    {
        std::cout << d << " -> " << (double)~Louble(d) << '\n';
        d = d + 1;
    }
    louble ld = 0.0;
    for( int i = 0; i < 65; i++ )
    {
        std::cout << "~(" << (double)ld << ") -> " << (double)~ld << '\n';
        ld.l <<= 1;
        ld.l++;
    }
    ld = -std::numeric_limits<double>::min( );
    std::cout << "~(" << (double)ld << ") -> " << (double)~ld << '\n';
    ld = std::numeric_limits<double>::max( );
    std::cout << "~(" << (double)ld << ") -> " << (double)~ld << '\n';
    return 0;
}
