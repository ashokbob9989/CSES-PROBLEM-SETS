#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ebl 1000000000
ll do_it()
{
    ll n, w;
    cin >> n >> w;
    vector<ll> wt(n);
    for (ll i = 0; i < n; i++)
        cin >> wt[i];

    vector<ll> dp(w + 1, ebl);
    dp[0] = 0;
    for (ll i = 1; i <= w; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            ll curr_sum = i;
            ll wt_ele = wt[j];
            if (curr_sum - wt_ele >= 0)
                dp[curr_sum] = min(dp[curr_sum - wt_ele] + 1, dp[curr_sum]); // +1 bcoz to get  nxt step atleast we used 0ne coin
        }
    }
    if (dp[w] == ebl)
        return -1;

    else
        return dp[w];
}
int32_t main()
{

    ll sol = do_it();
    cout << sol << endl;
    return 0;
}