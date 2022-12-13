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

    ll calci = 0;
    ll curr = 0;
    map<ll, ll> m; // to store the no.of times one duplicates can be also included in making sun==k.
    m[0]++;        // first element and last element in prefix sum array if it makes sum==k.
    for (ll i = 0; i < n; i++)
    {
        curr += v[i];
        ll wefind = curr - k; // for (i,j)=prefix[j]-prefix[i-1]; ..like if our curr is 9 the we need 2 to make sum==7 so if we fimd 2 in map then we incease our count.
        calci += m[wefind];
        m[curr]++;
    }
    return calci;
}
int main()
{
    ll sol = do_it();
    cout << sol << endl;
    return 0;
}