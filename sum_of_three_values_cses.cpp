#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> do_it()
{

    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> v;
    for (ll i = 1; i <= n; i++)
    {
        ll ele;
        cin >> ele;
        ll pp = ele;
        ll qq = i;
        v.push_back({pp, qq});
    }
    sort(v.begin(), v.end());
    vector<ll> sol;
    for (ll i = 0; i < n; i++)
    {
        ll p1 = 0;
        ll p2 = n - 1;
        while (p1 < p2)
        {
            ll newx;
            newx = x - v[i].first;
            if (p1 != i && p2 != i && (v.at(p1).first + v.at(p2).first) == newx)
            {
                sol.push_back(v.at(i).second);
                sol.push_back(v.at(p1).second);
                sol.push_back(v.at(p2).second);

                if (sol.size() == 3)
                {
                    sort(sol.begin(), sol.end());
                    return sol;
                }
            }
            if (v.at(p1).first + v.at(p2).first > newx)
                p2--;
            else
                p1++;
        }
    }
    return sol;
}
int32_t main()
{
    vector<ll> sol = do_it();
    if (sol.size() == 3)
    {
        for (ll i = 0; i < sol.size(); i++)
            cout << sol[i] << " ";
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}