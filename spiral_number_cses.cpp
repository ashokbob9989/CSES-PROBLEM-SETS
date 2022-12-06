#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll do_it()
{
    ll i,j;
    cin>>i>>j;
    if(i==j)
    {
        return i*j-(i-1);
    }
    else if(i>j)
    {
        if(i%2==0)
        {
            ll calci=i*i;
            return calci-j+1;
        }
        else
        {
            ll calci=(i-1)*(i-1)+1;
            return calci+j-1;
        }
    }
    else if(j>i)
    {
        if(j%2==0)
        {
            ll calci=(j-1)*(j-1)+1;
            return calci+i-1;
        }
        else
        {
            ll calci=j*j;
            return calci-i+1;
        }
    }
}
int32_t main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll sol=do_it();
        cout<<sol<<endl;
    }
    return 0;
}