#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ebl 1000000007
#define modinv2 500000004
ll do_it()
{
    string s; // actual string
    cin >> s;

    string pat; // pattern given 
    cin >> pat;

    ll n = s.length(); // string len
    ll m = pat.length();//pattern len

    vector<ll> pie(n + m + 1); // pie vector to store the lps values
    s = pat + "x" + s;//making as one string to insert one extra char
    n = n + m + 1; 
    pie[0] = 0;//first char we cant ake whole substr into cnsideration 
    ll len = 0;
    ll i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            pie[i] = len;
            i++;
        }
        else if (s[i] != s[len])
        {
            if (len == 0)//till now we havent find any pattern so stil 0
            {
                pie[i] = 0;
                i++;
            }
            else
                len = pie[len - 1];//shifting to the right place after found not equal but earlier foud it occured
        }
    }
    ll calci = 0;
    for (auto it : pie)
    {
        if (it == m)//if pattern len matches with values in pie array so we got pattern so just inc ctr
            calci++;
    }
    return calci;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll sol = do_it();
    cout << sol << endl;
    return 0;
}