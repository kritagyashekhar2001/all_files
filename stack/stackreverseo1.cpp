#include <iostream>
#include <stack>

using namespace std;

int putatend(stack<int> &s1, int k)
{
    if (s1.empty())
    {
        s1.push(k);
        return 0;
    }

    int temp = s1.top();
    s1.pop();

    putatend(s1, k);

    s1.push(temp);
}

int reverse(stack<int> &s1)
{
    if (s1.empty())
    {
        return 0;
    }

    int temp = s1.top();
    s1.pop();

    reverse(s1);

    putatend(s1, temp);

    return 0;
}
int printthestack(stack<int> &s1)
{
    if (s1.empty())
        return -1;

    cout << s1.top() << " ";
    int temp = s1.top();
    s1.pop();

    printthestack(s1);
    s1.push(temp);

    return 0;
}

int main()
{
    stack<int> s1;
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);

    cout << "Stack before reverse operation: ";
    printthestack(s1);
    cout << endl;

    reverse(s1);
    cout << "Reverse operation Applied" << endl;

    cout << "Stack after reverse operation: ";
    printthestack(s1);
    cout << endl;

    return 0;
}