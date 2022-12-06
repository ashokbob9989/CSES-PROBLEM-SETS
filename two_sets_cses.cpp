#include <bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main()
{
    ll n;
    cin >> n;
    ll calci = n * (n + 1) / 2;
    if (calci % 2 == 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<ll> set1, set2;
    if (n % 4 == 0)
    {
        for (ll i = 1; i <= n; i++)
        {
            if (i % 4 == 0 || i % 4 == 1)
                set1.push_back(i);

            else
                set2.push_back(i);
        }
    }
    else if (n % 4 == 3)
    {
        for (ll i = 1; i <= n; i++)
        {
            if (i % 4 == 1 || i % 4 == 2)
                set1.push_back(i);

            else
                set2.push_back(i);
        }
    }
    ll calci_size1 = set1.size();
    ll calci_size2 = set2.size();

    cout << calci_size1 << endl;
    for (auto it : set1)
        cout << it << " ";
    cout << endl;

    cout << calci_size2 << endl;
    for (auto it : set2)
        cout << it << " ";
    cout << endl;

    return 0;
}