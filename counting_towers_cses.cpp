#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ebl 1000000007
#define eml 1000010

int32_t main()
{
    vector<vector<ll>> ctrOfTowers(eml, vector<ll>(8, 0));
    for (ll i = 0; i < 8; i++)
        ctrOfTowers[0][i] = 1; // bcoz we can start from any possible boxes out of 8
    // this is initialization

    for (ll i = 1; i < eml; i++)
    {
        // 0 indexed
        for (ll j = 0; j < 8; j++)
        {
            if (j == 0 || j == 2 || j == 3 || j == 4 || j == 5) // all configurations which has top part on //zero based indx
                ctrOfTowers[i][j] = (ctrOfTowers[i - 1][0] + ctrOfTowers[i - 1][1] + ctrOfTowers[i - 1][3] + ctrOfTowers[i - 1][4] + ctrOfTowers[i - 1][5]) % ebl;

            // all configuration for bottom part off // zero based indx
            else
                ctrOfTowers[i][j] = (ctrOfTowers[i - 1][2] + ctrOfTowers[i - 1][6] + ctrOfTowers[i - 1][7]) % ebl;
        }
    }

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        // we precalculated all possible solutions for 1 to eml
        // we will find our ans at dp[n-1][2]+dp[n-1][6] // bcoz we used zero based indexing. if we use 1 based the sol found at dp[n][3]+dp[n][7].
        cout << (ctrOfTowers[n - 1][2] + ctrOfTowers[n - 1][6]) % ebl << endl;
    }
    return 0;
}