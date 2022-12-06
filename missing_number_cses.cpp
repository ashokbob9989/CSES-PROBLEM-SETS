#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin >> n;
    bool fg = true;
    vector<ll> v(n - 1);
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (ll i = 0; i < n - 1; i++)
    {
        if (v[i] != i + 1)
        {
            cout << i + 1 << endl;
            fg = false;
            break;
        }
    }
    if (fg == true)
    {
        cout << n << endl;
    }

    return 0;
}