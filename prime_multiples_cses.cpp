#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll do_it()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(k);
    for (auto &it : v)
        cin >> it;

    vector<ll> addsub_by_setbits(k + 1);
    for (ll mask = 1; mask < (1 << k); mask++)
    {
        ll setbit = 0;
        ll temp = n;
        for (ll j = 0; j < k; j++)
        {
            if (mask & (1 << j))
            {
                setbit = __builtin_popcount(mask);
                temp /= v[j];
            }
        }
        addsub_by_setbits[setbit] += temp;
    }
    ll sol = 0;
    for (ll i = 1; i <= k; i++)
    {
        if (i % 2 == 0)
            sol -= addsub_by_setbits[i];
        else
            sol += addsub_by_setbits[i];
    }
    return sol;
}
int32_t main()
{
    ll sol = do_it();
    cout << sol << endl;
    return 0;
}
