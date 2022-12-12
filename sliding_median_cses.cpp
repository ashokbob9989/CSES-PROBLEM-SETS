#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;

    ordered_set<pair<ll, ll>> os;
    for (ll i = 0; i < k; i++)
        os.insert({v[i], i});
    vector<ll> sol;
    sol.push_back(os.find_by_order((k - 1) / 2)->first);
    for (ll i = 1; i < n - k + 1; i++)
    {
        os.erase({v[i - 1], i - 1});
        os.insert({v[i + k - 1], i + k - 1});
        sol.push_back(os.find_by_order((k - 1) / 2)->first);
    }
    for (ll i = 0; i < sol.size(); i++)
        cout << sol[i] << " ";
    cout << endl;
    return 0;
}