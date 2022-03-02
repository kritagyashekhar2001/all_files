#include <bits/stdc++.h>

using namespace std;
int main()
{
    map<string, int> m;
    for (int j = 0; j < 2; j++)
    {
        int n;
        string a;
        cin >> a >> n;
        m.insert({a, n});
    }

    for (auto &pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }
    return 0;
}