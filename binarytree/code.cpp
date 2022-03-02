#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    cin >> s;

    if (s[0] == 'R' || s[2] == 'B' && s[0] == 'B' || s[2] == 'R')
    {
        cout << "R";
        return 0;
    }
    else if (s[0] == 'R' || s[2] == 'G' && s[0] == 'G' || s[2] == 'R')
    {
        cout << "R";
        return 0;
    }
    else if (s[0] == 'G' || s[2] == 'B' && s[0] == 'B' || s[2] == 'G')
    {
        cout << "B";
        return 0;
    }
    // else if (s[0] == s[2])
    // {
    //     cout << s[0];
    //     return 0;
    // }
    return 0;
}