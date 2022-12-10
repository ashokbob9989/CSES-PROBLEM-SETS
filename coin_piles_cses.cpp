#include <bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        ll maxii=max(x,y);
        ll mini=min(x,y);
        if(maxii>2*mini)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if ((x+y)%3==0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}