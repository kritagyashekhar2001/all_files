#include <iostream>
using namespace std;
class inc
{
    int x, y, z;

public:
    void getdata(int a, int b, int c);
    void display();
    void operator++();
};

void inc::getdata(int a, int b, int c)
{
    x = a;
    y = b;
    z = c;
}

void inc::display()
{
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
}

void inc::operator++()
{
    x = ++x;
    y = ++y;
    z = ++z;
}

int main()
{
    inc a;
    a.getdata(10, 12, 14);
    ++a;
    a.display();
}