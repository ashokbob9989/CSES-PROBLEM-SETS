#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll binexpo(ll a, ll b)
{
    ll res = 1;
    while (b != 0)
    {
        if (b % 2 == 1)
        {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}
void do_it(ll n, ll l, ll m, ll r)
{
    if (n == 0)
        return;

    do_it(n - 1, l, r, m); // moving from A->B so helping is C..thats why it is m.
    cout << l << " " << r << endl;
    do_it(n - 1, m, l, r); // B->C so not used or helping is A thats why it is m.
}
int32_t main()
{
    ll n;
    cin >> n;
    cout << (binexpo(2, n)-1) << endl;
    ll left = 1, mid = 2, right = 3;
    do_it(n, left, mid, right);
    return 0;
}