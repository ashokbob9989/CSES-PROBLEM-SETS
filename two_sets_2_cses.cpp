#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ebl 1000000007
#define modinv2 500000004

ll do_it()
{
    ll n;
    cin >> n;

    if ((n * (n + 1) / 2) % 2 == 1)
        return 0; // if sum is odd we cannot distribute it in two sets

    ll sum = n * (n + 1) / 2;
    sum /= 2; // search for how many sets are there if the sum  is half so that another set also contains equal sum

    vector<ll> dp(sum + 1); // sum cant exceed the (tot_sum)/2
    dp[0] = 1; // always true

    for (ll i = 1; i < n + 1; i++) // coins
    {
        for (ll j = sum; j >= i; j--) // if(j-i==0)valid coins and sum coz both has the same sum ...from the end calculations is optimal coz we cannot exceed the sum till the coin value 
        {
            dp[j] = (dp[j] + dp[j - i]) % ebl; // for each coin(i) we are constructing the ways to bould the sum j
        }
    }
    return (dp[sum] * modinv2) % ebl; // nothing but dp[sum]/2 but it is wrong here coz we have modulo value..so we take modulo inverse of 2 and multily with dp[sum] like a/b==a*b^-1 so here we are taking mod inverse of 2.
}
int32_t main()
{
    ll sol = do_it();
    cout << sol << endl;
    return 0;
}