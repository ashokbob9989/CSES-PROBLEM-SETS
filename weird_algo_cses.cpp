#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "1" << endl;
        return 0;
    }
    else
    {
        while (n != 1)
        {
            if (n % 2 == 0)
            {
                cout << n << " ";
                n /= 2;
            }
            else if (n % 2 == 1)
            {
                cout << n << " ";
                n = n * 3 + 1;
            }
        }
        if (n == 1)
        {
            cout << "1" << endl;
            return 0;
        }
    }

    return 0;
}