#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

vector<ll> do_it()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;

    vector<ll> sol;
    if (k == 1)
    {
        for (ll i = 0; i < n; i++)
            sol.push_back(0);

        return sol;
    }

    else if (k == 2)
    {
        for (ll i = 1; i < n; i++)
            sol.push_back(abs(v[i - 1] - v[i]));

        return sol;
    }
    indexed_set os;
    for (ll i = 0; i < k; i++)
        os.insert(v[i]);

    ll old_m = *os.find_by_order((k + 1) / 2 - 1);
    ll cost = 0;
    for (ll i = 0; i < k; i++)
    {
        cost += abs(v[i] - old_m);
    }
    sol.push_back(cost);
    for (ll i = 0; i < n - k; i++)
    {
        os.erase(os.find_by_order(os.order_of_key(v[i])));
        os.insert(v[i + k]);
        ll new_m = *os.find_by_order((k + 1) / 2 - 1);
        cost = cost + abs(new_m - v[i + k]) - abs(old_m - v[i]);
        if (k % 2 == 0)
            cost -= (new_m - old_m);
        old_m = new_m;
        sol.push_back(cost);
    }
    return sol;
}
int32_t main()
{
    vector<ll> sol = do_it();
    for (ll i = 0; i < sol.size(); i++)
        cout << sol[i] << " ";
    cout << endl;

    return 0;
}