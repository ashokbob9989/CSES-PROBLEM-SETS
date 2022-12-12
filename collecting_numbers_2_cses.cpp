#include <bits/stdc++.h>
using namespace std;
#define ll long long
void do_it()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n + 1);
    vector<ll> loc(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
        loc[v[i]] = i;
    }
    ll rounds = 0;
    for (ll i = 1; i < n; i++)
        if (loc[i] > loc[i + 1])
            rounds++;

    rounds++;
    map<ll, ll> mloc;

    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        if (v[x] - 1 >= 1) // checking for left size
            mloc.insert({v[x] - 1, v[x]});
        if (v[x] + 1 <= n) // checking for right side
            mloc.insert({v[x], v[x] + 1});

        if (v[y] - 1 >= 1) // checking for left size
            mloc.insert({v[y] - 1, v[y]});
        if (v[y] + 1 <= n) // checking for right side
            mloc.insert({v[y], v[y] + 1});

        for (auto it = mloc.begin(); it != mloc.end(); it++)
            if (loc[it->first] > loc[it->second])
                rounds--;

        swap(v[x], v[y]);
        loc[v[x]] = x;
        loc[v[y]] = y;

        for (auto it = mloc.begin(); it != mloc.end(); it++)
            if (loc[it->first] > loc[it->second])
                rounds++;

        cout << rounds << endl;
        mloc.clear();
    }
}
int32_t main()
{
    do_it();
    return 0;
}