#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ebl 1000000007

ll do_it()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;

    vector<ll> lis;
    lis.push_back(v[0]); // in lis vestor push first element for nxt comparisions.

    for (ll i = 1; i < n; i++)  // start from second element in vector
    {
        ll last = lis.back(); // get the last element in ls vestor for check are we increasing or decreasing our seq
        if (v[i] > last)
            lis.push_back(v[i]); // if curr ele is greater then we need to push in our req seq

        else
        {
            auto it = lower_bound(lis.begin(), lis.end(), v[i]); // else find the position  in lis to put this ele at that pos(use lower_bound).. gives the ele>=curr if we wamt to replece ele the we find the pos in lis 
            *it = v[i];
        }
    }
    ll sol = lis.size();
    for(auto it :lis)
    cout<<it<<" ";
    cout<<endl;
    return sol;
}
int32_t main()
{
    ll sol = do_it();
    cout << sol << endl;
    return 0;
}