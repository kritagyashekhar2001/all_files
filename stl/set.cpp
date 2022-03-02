#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<string> s;
    for (auto i = 0; i < 5; ++i)
    {
        string a;
        cin >> a;
        s.insert(a);
    }

    for (auto &str : s)
    {
        cout << str << endl;
    }
}