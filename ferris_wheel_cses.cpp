#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxii 200010

ll do_it()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    ll ptr1 = 0, ptr2 = n - 1;
    ll calci = n;

    while (ptr1 < ptr2) // equal to condition bcoz to work under odd size
    {
        if (v[ptr1] + v[ptr2] <= x)
        {
            calci--;
            ptr1++;
            ptr2--; // valid range
        }
        else
            ptr2--; // exceeded the size ..so find a number(smaller to get in range);
    }

    return calci;
}
int32_t main()
{
    ll sol = do_it();
    cout << sol << endl;
    return 0;
}