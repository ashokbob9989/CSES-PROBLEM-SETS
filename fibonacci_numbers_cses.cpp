#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long mod = 1000000007;
map<ll, ll> mfib;
ll fibo(ll n)
{
    if (mfib.count(n))
        return mfib[n];

    ll k = n / 2;
    if (n % 2 == 0)
        return mfib[n] = ((fibo(k) * fibo(k)) + (fibo(k - 1) * fibo(k - 1))) % mod;

    else
        return mfib[n] = ((fibo(k) * fibo(k + 1)) + (fibo(k - 1) * fibo(k))) % mod;
}
int32_t main()
{
    ll n;
    cin >> n;
    mfib[0] = 1;
    mfib[1] = 1;
    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    ll sol = fibo(n - 1);
    cout << sol << endl;

    // for(auto it : mfib)
    // cout<<it.first<<" "<<it.second<<endl;
}
