#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long

void do_it()
{
    ll n, k;
    cin >> n >> k;
    ordered_set os;
    for (ll i = 1; i <= n; i++)
        os.insert(i);

    ll pos = 0;
    while (os.size() > 1)
    {
        ll xx = os.size();
        pos = (pos + k) % xx;

        cout << *(os.find_by_order(pos)) << " ";

        os.erase(*(os.find_by_order(pos)));

        pos %= xx;
    }
    cout << *(os.begin()) << endl;
}
int32_t main()
{
    do_it();
    return 0;
}
