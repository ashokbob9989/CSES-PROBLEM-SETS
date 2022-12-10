#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int32_t main()
{
    ll n;
    cin>>n;
    ll calci=0;
    ll i=1;
    while(pow(5,i)<=n)
    {
        calci+=n/pow(5,i);
        i++;
    }
    cout<<calci<<endl;
}