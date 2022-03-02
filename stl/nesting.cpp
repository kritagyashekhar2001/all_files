#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<pair<string, string>, vector<int>> m;

    int n;
    cin >> n;

    for (auto i = 0; i < n; i++)
    {
        string first, second;
        int ct;
        cin >> first >> second >> ct;
        for (auto j = 0; j < ct; j++)
        {
            int x;
            cin >> x;
            m[{first, second}].push_back(x);
        }
    }

    for (auto &pr : m)
    {
        auto &fullname = pr.first;
        auto &list = pr.second;
        cout << fullname.first << " " << fullname.second << endl;
        cout << list.size() << endl;
        for (auto &element : list)
        {
            cout << element << " ";
        }
        cout << endl;
    }
}