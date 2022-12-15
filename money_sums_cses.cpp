#include <bits/stdc++.h>
using namespace std;
#define ll long long
void do_it()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &it : v)
        cin >> it;

    ll sum = accumulate(v.begin(), v.end(), 0); // we cant exceed totsum in array..coz that is the max sum we can form from all coins
    vector<bool> dp(sum + 1);                   // for combinations of coins is it possible to form that particular sum..if yes we will make true ele false;
    set<ll> s;
    dp[0] = true; // forming 0(sum) with 1 coin is also true.
    ll upto = 0;
    for (auto it : v) // for each element in array...check what sum we can form
    {
        upto += it; // with that coin say 4 we can form sum upto 4 not more than that so,starting from that number is optimal.
        for (ll i = upto; i >= it; i--)
        {
            if (dp[i - it] && dp[i] != 1)
            {
                dp[i] = true;

                s.insert(i);
            }
            // if(now curr sum-ele ==0)so we can say it is a valid sum  ..like if sum is 4 and ele is 4 the 4-4==0 so we can form 4 using coin value 4..... and for recursive checkibg for already checked we do HAVE WE NOT CHECKED THIS KIND OF COMBINATION YET?? IF YES THEN MAKE THIS SUM POSSIBLE ..IF ALREDAY CHECKED ..JUST KEEP moving on the nxt
        }
    }
    cout << s.size() << endl;
    for (auto it : s)
        cout << it << " ";
    cout << endl;
}
int32_t main()
{
    do_it();
    return 0;
}