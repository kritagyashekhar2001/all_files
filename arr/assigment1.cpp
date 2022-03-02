#include <iostream>
using namespace std;

int main()
{

    int a[30][30];
    cout << "enter the input";
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    // for printing
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0 && j == 0)
            {
                cout << "     ";
            }
            else if (i == 0)
            {
                cout << "stu" << j << " ";
            }
            else if (j == 0)
            {
                cout << "sub" << i << " ";
            }

            else if (a[i][j] < 0)
            {
                cout << "A"
                     << "    ";
            }
            else
            {
                cout << a[i][j] << "    ";
            }
        }
        cout << endl;
    }
    return 0;
}