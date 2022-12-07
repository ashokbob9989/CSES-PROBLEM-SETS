#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll do_it()
{
    ll n;
    cin>>n;
    //kadanes algorithm we use here.
    vector<ll>v(n);
    for(auto &it :v)
    cin>>it;

    ll curr_sum=0;
    ll maxii=LLONG_MIN;
    for(ll i=0;i<v.size();i++)
    {
        curr_sum+=v[i];
        
        if(maxii<curr_sum)
        maxii=curr_sum;

        if(curr_sum<0)
        curr_sum=0;

    }
    return maxii;
}
int32_t main()
{
    ll sol=do_it();
    cout<<sol<<endl;
    return 0;
}