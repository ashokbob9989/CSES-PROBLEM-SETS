#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int32_t main()
{
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        if(i==1)
        {
            cout<<"0"<<endl; // for 1*1 we acnt place 2 knights so sol=0;
            continue;
        }
        ll calci=pow(i,2); //placing first knight has k^2 choices 
        ll tot_ways=calci*(calci-1)/2; // for second knight has k^2-1 choices ../2 did bcoz to avoid duplicates in placing the knights
        tot_ways=tot_ways-((8*(i-1)*(i-2))/2);  //2*3 board we have (k-1)*(k-2) ways of placing in attacking positions
        // so toatal ways == tot possible ways of placing two knights on baord-(two knights unserattack positions).
        cout<<tot_ways<<endl;
    }
    return 0;
}