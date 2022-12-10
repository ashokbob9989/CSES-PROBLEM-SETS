#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];

    ll arr_sum = 0;
    for (ll i = 0; i < n; i++)
        arr_sum += v[i];

    ll min_sol = LLONG_MAX;
    for (ll i = 0; i < (1 << n); i++)
    {
        ll curr_seq_sum = 0;
        for (ll j = 0; j < n; j++)
        {
            if (i & (1 << j))
                curr_seq_sum += v[j];
        }
        min_sol = min(min_sol, abs((arr_sum - curr_seq_sum) - curr_seq_sum));
    }
    cout << min_sol << endl;

    return 0;
}