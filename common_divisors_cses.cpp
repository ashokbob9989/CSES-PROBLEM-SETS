#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eml 1000000
ll do_it()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;

    vector<ll> range(eml + 1, 0);
    for (auto it : v)
        range[it]++;  // if any numberepeated more than twice

    for (ll i = eml; i >= 1; i--) // we start from greater to saller bcoz optimally we can see we nned to print larger so its better to strat from geater itself.
    {
        ll multis = 0;
        for (ll j = i; j <= eml; j += i)
            multis += range[j]; // we find multipless of certain gcd if ..multis are >1 that means there exits 2 numbers which has max gcd

        if (multis >= 2)
            return i; // i is the gcd here
    }
}
int32_t main()
{
    ll sol = do_it();
    cout << sol << endl;
    return 0;
}