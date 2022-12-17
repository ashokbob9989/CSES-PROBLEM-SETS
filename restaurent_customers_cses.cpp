#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ebl 1000000007
#define modinv2 500000004

int main()
{
    ll t;
    cin >> t;
    map<ll, ll> m;
    while (t--)
    {
        ll entry;
        ll exit;
        cin >> entry >> exit;
        m[entry] = 1;
        m[exit] = -1;
    }
    ll calci = 0;
    ll maxii = LLONG_MIN;
    for (auto it : m)
    {
        calci += it.second;
        maxii = max(maxii, calci);
    }
    cout << maxii << endl;
    return 0;
}