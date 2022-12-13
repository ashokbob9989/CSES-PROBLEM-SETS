#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll findprimes(ll n)
{
    map<ll, ll> mp;
    while (n % 2 == 0)
    {
        mp[2]++;
        n /= 2;
    }
    for (ll i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            mp[i]++;
            n /= i;
        }
    }
    if (n > 2)
        mp[n]++;

    ll calci = 1;
    for (auto it : mp)
    {
        calci = calci * (it.second + 1);
    }
    return calci;
}
ll do_it()
{
    ll n;
    cin >> n;
    ll sol = findprimes(n);
    return sol;
}
int32_t main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll sol = do_it();
        cout << sol << endl;
    }
    return 0;
}