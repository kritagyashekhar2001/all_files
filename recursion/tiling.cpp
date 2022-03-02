#include <iostream>
using namespace std;

int tilingcount(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return tilingcount(n - 1) + tilingcount(n - 2);
    }
}

int main()
{
    cout << tilingcount(9);
}