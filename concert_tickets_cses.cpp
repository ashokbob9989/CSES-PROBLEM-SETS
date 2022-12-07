#include <bits/stdc++.h>
using namespace std;
#define ll long long
void do_it()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> vn(n), vm(m);
    for (auto &it : vn)
        cin >> it;

    for (auto &it : vm)
        cin >> it;

    multiset<ll, greater<ll>> s;

    for (auto it : vn)
        s.insert(it);

    for (ll i = 0; i < vm.size(); i++)
    {
        auto it = s.lower_bound(vm[i]);
        if (it == s.end()) // we ran till last but no where we found such element less than or equal to maxprice in vm vector.
            cout << "-1" << endl;
        else
        {
            cout << *it << endl;
            s.erase(it); // ticket is sold so we need to delete it.
        }
    }
}
int32_t main()
{
    do_it();
    return 0;
}