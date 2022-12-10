#include <bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main()
{
    ll n;
    cin >> n;

    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;

    sort(v.begin(), v.end());

    ll mid_idx = n / 2;

    ll calci = v[mid_idx];
    ll cost = 0;
    
    for (auto it : v)
    {
        cost += abs(calci - it);
    }
    cout << cost << endl;
    return 0;
}