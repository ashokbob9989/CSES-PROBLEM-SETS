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

    multiset<ll>ms;
    for(ll i=0;i<n;i++)
    {
        auto it =ms.upper_bound(v[i]);
        //if no element is found to be just greater than v[i];it means we need construct new tower.
        if(it==ms.end())
        ms.insert(v[i]); // insert that element in ms
        else
        {
            //if there exits a next greater element than v[i]. so we can place this v[i] on the next greater element present in ms.
            ms.erase(it);// it points to nxt greater element in ms.
            ms.insert(v[i]);// for nxt comparision we need to check with this v[i].  
        }
    }
    return ms.size(); // size of ms is the no.of towers req 
}
int32_t main()
{
    ll sol=do_it();
    cout<<sol<<endl;
    return 0;
}