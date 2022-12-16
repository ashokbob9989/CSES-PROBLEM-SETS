#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll do_it()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;

    sort(v.begin(), v.end());
    ll calci = 1;
    ll ptr = 0;
    while (ptr < n && v[ptr] <= calci)
    {
        calci += v[ptr];
        ptr++;
    }
    return calci;
}
int32_t main()
{
    ll sol = do_it();
    cout << sol << endl;
    return 0;
}