#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll do_it()
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(auto &it :v)
    cin>>it;
    ll isit=0;
    ll isnot=0;
    for(ll i=0;i<n-1;i++)
    {
          if(v[i]<v[i+1])
          isit++;
          if(v[i]>v[i+1])
          isnot++;
    }
    if(isit==n-1)
    {
        return 1;
    }
    else if(isnot==n-1)
    {
      return n;
    }

    ll rounds=0;
    ll ptr=0;
    for(ll i=1;i<n;i++)
    {
        if(v[ptr]>v[i])
        {
            rounds++;
            ptr++;
        }
    }
    return rounds;
}
int32_t main()
{
    ll sol=do_it();
    cout<<sol<<endl;
    return 0;
}
