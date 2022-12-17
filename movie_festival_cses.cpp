#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ebl 1000000007
#define modinv2 500000004

int main()
{
    ll t;
    cin >> t;
    vector<pair<ll, ll>> vpEnd_Start;
    while (t--)
    {
        ll start;
        ll end;
        cin >> start >> end;
        vpEnd_Start.push_back({end, start});
    }
    sort(vpEnd_Start.begin(), vpEnd_Start.end());
    ll maxii = 1;
    ll first_end = vpEnd_Start[0].first;
    for (ll i = 1; i < vpEnd_Start.size(); i++)
    {
        ll herestart = vpEnd_Start[i].second;
        if (herestart >= first_end)
        {
            maxii++;
            first_end = vpEnd_Start[i].first; // nxt ending time;
        }
    }
    cout << maxii << endl;
    return 0;
}