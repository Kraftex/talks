#include <iostream>

class PointC
{
};

struct PointS
{
};

union Number
{
    int i;
    long l;
    float f;
    double d;
};

int main ( )
{
    Number n;
    n.d = 34.56;
    std::cout << "Number: " << n.l << '\n';
    return 0;
}
