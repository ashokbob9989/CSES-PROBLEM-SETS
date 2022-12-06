#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define m 1000000007
int do_it(ll a, ll b)
{
    ll res = 1;
    while (b != 0)
    {
        if (b % 2 == 1) // if odd power we have one extra poswer time multiplied
        {
            res = res * a % m;
        }
        a = a * a % m; // if power is even then doing it same as itself is enough.
        b >>= 1;       // dividing the power by 2 ...or doing half.
    }
    return res;
}
int32_t main()
{
    ll n;
    cin >> n; // for n possible values are 2^n
    // for greater n ..we cant find value so we use BINARY EXPONENTIATION.
    ll sol = do_it(2, n);
    cout << sol << endl;
    return 0;
}