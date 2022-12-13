#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll do_it1(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    ll res = 1;
    a = a % (m);
    while (b != 0)
    {
        if (b & 1)
            res = res * a % (m);

        a = a * a % (m);
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
        ll a, b, c;
        cin >> a >> b >> c;
        ll r = do_it1(b, c, mod - 1);
        // r is b^c (mod-1).
        ll sol = do_it1(a, r, mod);
        cout << sol << endl;
    }
    return 0;
}