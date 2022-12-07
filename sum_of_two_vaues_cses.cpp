#include <bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;

    map<ll, ll> m;
    for (ll i = 0; i < n; i++)
    {
        m[v[i]] = i + 1;
    }
    vector<ll> temp = v;
    sort(v.begin(), v.end());
    ll p1 = 0, p2 = n - 1;
    while (p1 < p2)
    {
        if (v[p1] + v[p2] == x)
        {
            ll x = v[p1];
            ll y = v[p2];
            ll idx1 = 0, idx2 = 0;
            if (x == y)
            {
                for (ll i = 0; i < n; i++)
                {
                    if (temp[i] == x)
                    {
                        idx1 = i;
                        break;
                    }
                }
                for (ll i = 0; i < n; i++)
                {
                    if (temp[i] == y && i != idx1)
                    {
                        idx2 = i;
                        break;
                    }
                }
                ll maxii = (idx1 > idx2) ? idx1 : idx2;
                ll minii = (idx1 < idx2) ? idx1 : idx2;
                if (idx1 != idx2)
                    cout << minii + 1 << " " << maxii + 1 << endl;
                else
                    cout << "IMPOSSIBLE" << endl;

                return 0;
            }

            for (auto it : m)
            {
                if (it.first == x)
                {
                    idx1 = it.second;
                }
            }
            for (auto it : m)
            {
                if (it.first == y)
                    idx2 = it.second;
            }
            ll maxii = (idx1 > idx2) ? idx1 : idx2;
            ll minii = (idx1 < idx2) ? idx1 : idx2;
            cout << minii << " " << maxii << endl;

            return 0;
        }

        else if (v[p1] + v[p2] > x)
            p2--;
        else
            p1++;
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}