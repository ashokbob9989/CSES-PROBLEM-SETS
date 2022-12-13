#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll binexpo(ll a, ll b)
{
    if (b == 0)
        return 1;

    ll res = 1;
    a = a % mod;
    while (b != 0)
    {
        if (b & 1)
            res = res * a % mod;

        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll do_it()
{
    ll n;
    cin >> n;
    ll sol = 0;
    for (ll oldi = 1, newi; oldi <= n; oldi = newi)
    {
        ll quo = n / (oldi);
        newi = n / quo + 1;
        ll sumtonewiless1 = ((((newi % mod) * ((newi - 1) % mod)) % mod) * binexpo(2, mod - 2)) % mod; // this is like n*(n=1)/2 //in modulo we cant do /2 or something in division so just find modulo inverse of ...like (a/b)say...so modulo inverse is binexpo(b,mod-2) the final res= ((a%mod)*(moduloinverse we calculated)%mod)%mod
        // sumtonewiless1 is sum from 1 2 ....j-1
        ll sumtooliless1 = ((((oldi % mod) * ((oldi - 1) % mod)) % mod) * binexpo(2, mod - 2)) % mod;
        // sumtooliless1 is sum from 1 2 .....i-1.
        ll tillquono_oftimes = (sumtonewiless1 - sumtooliless1 + mod) % mod; // for i to j sum...we calculate  sum from 1 to j and subtract sum from 1 to i-1 which gives sum from i to j.
        // but here j is not included in our qn so we do sum from 1 to j-1 and subtract sum of 1 to i-1 which indeeed gives sum from i to j-1.
        sol = (sol + (quo % mod) * tillquono_oftimes) % mod;
    }
    return sol;
}
int32_t main()
{
    ll sol = do_it();
    cout << sol << endl;
    return 0;
}