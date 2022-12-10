#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> do_it()
{
    int n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];

    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
    {
        vp.push_back({v[i], i + 1});
    }
    vector<ll> sol;
    sort(vp.begin(), vp.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 3; j < n; j++)
        {
            int p1 = i + 1, p2 = j - 1;
            int fir_last_sum = vp[i].first + vp[j].first;
            while (p1 < p2)
            {
                int sum_here = vp[p1].first + vp[p2].first + fir_last_sum;
                if (sum_here == x)
                {
                    sol.push_back(vp[i].second);
                    sol.push_back(vp[p1].second);
                    sol.push_back(vp[p2].second);
                    sol.push_back(vp[j].second);
                    if (sol.size() == 4)
                    {
                        sort(sol.begin(),sol.end());
                        return sol;
                    }
                }
                else if (sum_here > x)
                    p2--;
                else
                    p1++;
            }
        }
    }
    return sol;
}
int32_t main()
{
    vector<ll> sol = do_it();
    if (sol.size() == 4)
    {
        for (ll i = 0; i < 4; i++)
            cout << sol[i] << " ";
        cout << endl;
    }

    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}