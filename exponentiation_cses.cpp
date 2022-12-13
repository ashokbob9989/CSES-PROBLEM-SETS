#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll do_it(ll a, ll b)
{
    if (a == 0 && b == 0)
        return 1;
    else if (a == 0 && b > 0)
        return 0;

    ll res = 1;
    while (b != 0)
    {
        if (b & 1)
            res = res * a % mod;

        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int32_t main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        ll sol = do_it(a, b);
        cout << sol << endl;
    }
    return 0;
}