#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll do_it()
{
    ll n;
    cin >> n;
    vector<ll>v(n,0);
    for (ll i = 1; i <= n; i++)
    {
        ll ele;
        cin >> ele;
        v[ele] = i;
    }
    ll inb = 1, rounds = 1;
    for (ll i = 1; i <= n; i++)
    {
        if (inb > v[i])
            rounds++;

            inb = v[i];
    }
    return rounds;
}

int main()
{
    ll sol = do_it();
    cout << sol << endl;
    return 0;
}
