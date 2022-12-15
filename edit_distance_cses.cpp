#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll min(ll a, ll b, ll c)
{
    return min(min(a, b), c);
}
ll do_it()
{
    string s1;
    string s2;
    cin >> s1 >> s2;
    ll m = s1.size();
    ll n = s2.size();
    vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, 0));
    for (ll i = 0; i < m + 1; i++)
    {
        for (ll j = 0; j < n + 1; j++)
        {
            if (i == 0)
                dp[i][j] = j;

            else if (j == 0)
                dp[i][j] = i;

            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
        }
    }
    return dp[m][n];
}
int32_t main()
{
    ll sol = do_it();
    cout << sol << endl;
    return 0;
}