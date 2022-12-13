#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll do_it()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;

    ll p1 = 0;
    ll p2 = 0;
    ll sum = 0;
    ll calci = 0;
    while (p2 < n)
    {
        sum += v[p2];
        while (sum >= k)
        {
            if (sum == k)
                calci++;

            sum -= v[p1];
            p1++;
        }
        p2++;
    }
    return calci;
}
int32_t main()
{
    ll sol = do_it();
    cout << sol << endl;
    return 0;
}
