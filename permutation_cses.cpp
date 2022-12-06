#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int32_t main()
{
    ll n;
    cin>>n;
    if(n==2 || n==3)
    {
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    vector<ll>v(n+1);
    v[0]=0;
    for(ll i=1;i<=n;i++)
    v[i]=i;

    vector<ll>even,odd;
    for(ll i=1;i<=n;i++)
    {
        if(v[i]%2==0)
        even.push_back(v[i]);
        else
        odd.push_back(v[i]);
    }
    for(auto it :even)
    cout<<it<<" ";
    for(auto it :odd)
    cout<<it<<" ";

    return 0;
}