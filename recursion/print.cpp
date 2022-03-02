#include <iostream>
using namespace std;
int print(int n, int k)
{
    if (k > n)
    {
        return 0;
    }
    else
    {
        cout << k;
    }
    print(n, k + 1);
}
int main()
{
    print(15, 5);
}