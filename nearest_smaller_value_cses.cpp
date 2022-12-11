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

    stack<pair<ll, ll>> sp;
    cout << "0"
         << " ";
    sp.push({v[0], 1});
    for (ll i = 1; i < n; i++)
    {
        if (sp.top().first < v[i])
        {
            cout << sp.top().second << " ";
            sp.push({v[i], i + 1});
        }
        else if (sp.top().first >= v[i])
        {
            while (!sp.empty() && sp.top().first >= v[i])
                sp.pop();

            if (sp.empty())
            {
                cout << "0"
                     << " ";
                sp.push({v[i], i + 1});
            }
            else if (!sp.empty())
            {
                cout << sp.top().second << " ";
                sp.push({v[i], i + 1});
            }
        }
    }

    return 0;
}