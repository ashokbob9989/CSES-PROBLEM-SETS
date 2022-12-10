#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int32_t main()
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(auto &it :v)
    cin>>it;

    map<ll,ll>m;
    for(ll i=0;i<n;i++)
    m[v[i]]++;

    ll calci=m.size();
    cout<<calci<<endl;
    return 0;

}