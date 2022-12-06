#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int32_t main()
{
    ll n;
    cin>>n;
    if(n==1)
    {
        cout<<"0"<<endl;
        return 0;
    }
    vector<ll>v(n);
    for(auto &it:v)
    cin>>it;

    ll movesreq=0;
    for(ll i=1;i<v.size();i++)
    {
        if(v[i-1]>v[i])
        {
            ll calci=v[i]-v[i-1];
            movesreq+=v[i]-v[i-1];// movesreq to make two numbers equal
            v[i]=v[i]-calci;  // for next number comparision
        }
    }
    cout<<abs(movesreq)<<endl;

    return 0;
}