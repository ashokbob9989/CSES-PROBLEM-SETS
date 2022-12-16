#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ebl 1000000007
#define modinv2 500000004
ll do_it()
{
    ll n;
    cin >> n;
    bool grid[n + 1][n + 1];

    for (ll i = 1; i < n + 1; i++)
        for (ll j = 1; j < n + 1; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '*')
                grid[i][j] = 1; // trap
            else
                grid[i][j] = 0; // safe
        }

    if (grid[n][n] == 1) // last block is trap we cant reach it anyway
        return 0;

    ll dp[n + 1][n + 1];
    for (ll i = n; i >= 1; i--)
    {
        for (ll j = n; j >= 1; j--)
        {
            if (i == n && j == n) // reaching last block from it is 1
                dp[i][j] = 1;
            else
            {
                ll op1 = (j == n) ? 0 : dp[i][j + 1]; // if we are at leftend so fro that we cant go anywhere so 0 else we can move
                ll op2 = (i == n) ? 0 : dp[i + 1][j]; // if we are topend then we cant go anywhere so  0. else we can move
                dp[i][j] = (op1 + op2) % ebl;         // from that(i,j) we have 2 options so we addthem to current (i,j)position

                if (grid[i][j] == 1) // if it has trap so 0.
                    dp[i][j] = 0;    // for this pos we found trap so dp[i][j]=0;
            }
        }
    }
    return dp[1][1]; // our total steps we can reach top leftcorner to bottom right corner is at dp[1][1]..coz we are doing botto up appoach
}

int32_t main()
{
    ll sol = do_it();
    cout << sol << endl;
    return 0;
}