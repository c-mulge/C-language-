#include <iostream>
using namespace std;

class integer
{
    int m, n;

public:
    integer(int, int);
    void display()
    {
        cout << "m: " << m << endl;
        cout << "n: " << n << endl;
    }
};

integer::integer(int x, int y)
{
    m = x;
    n = y;
}

int main()
{
    integer int1(0, 100);           // constructor called implicitly
    integer int2 = integer(25, 75); // constructor called explicitly
    cout << "Object1: " << endl;
    int1.display();

    cout << "Object2: " << endl;
    int2.display();
    return 0;
}