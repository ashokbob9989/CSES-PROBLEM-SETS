#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll do_it()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> vn(n), vm(m);
    for (ll i = 0; i < n; i++)
        cin >> vn[i];

    for (ll i = 0; i < m; i++)
        cin >> vm[i];

    sort(vn.begin(), vn.end());
    sort(vm.begin(), vm.end());

    // t(n)=O(nlog(n)+mlog(m))

    ll calci = 0;
    ll ptr1 = 0, ptr2 = 0; // ptr1 for applicant .. ptr2 is for appartment size
    while (ptr1 < n && ptr2 < m)
    {
        if (abs(vn[ptr1] - vm[ptr2]) <= k) // valid range so move both pointers and increment ans
        {
            ptr1++;
            ptr2++;
            calci++;
        }
        else
        {
            if (vn[ptr1] - vm[ptr2] > k) // the desired apartment size of applicant is too big .. so find another big apartment size ..move apartment pointer to the right.
                ptr2++;

            else
                // the desired apartment size is too small ..so we skip that applicant
                ptr1++;
        }
    }

    return calci;

    // tle apparoach ...O(n*m)=t(n)  // with one test case fails.

    // vector<pair<ll, ll>> vp;
    // for (ll i = 0; i < n; i++)
    // {
    //     ll x = vn[i] - k;
    //     ll y = vn[i] + k;

    //     vp.push_back({x, y});
    // }
    // vector<bool> vmb(m);
    // for (ll i = 0; i < m; i++)
    // {
    //     vmb[i] = false;
    // }
    // for (ll i = 0; i < vm.size(); i++)
    // {
    //     for (auto it : vp)
    //     {
    //         ll x = it.first;
    //         ll y = it.second;
    //         if (vm[i] >= x && vm[i] <= y && vmb[i] == false)
    //         {
    //             calci++;
    //             vmb[i] = true;
    //         }
    //     }
    // }
}

int32_t main()
{
    ll sol = do_it();
    cout << sol << endl;
    return 0;
}