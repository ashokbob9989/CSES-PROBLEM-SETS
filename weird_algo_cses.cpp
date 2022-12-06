#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
    ll  n;
    cin >> n;
    while (n != 1)
    {
        cout << n << " ";
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else if (n % 2 == 1)
        {
            n = n * 3 + 1;
        }
    }
    cout << "1" << endl;

    return 0;
}