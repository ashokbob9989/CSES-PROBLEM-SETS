#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s;
    cin >> s;
    ll ctr = 1;
    vector<ll> repc;

    if (s.size() == 1)
    {
        cout << "1" << endl;
        return 0;
    }
    for (ll i = 0; i < s.size() - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            repc.push_back(ctr);
            ctr = 1;
        }
        else if (s[i] == s[i + 1])
        {
            ctr++;
        }
    }
    repc.push_back(ctr);
    ll calci = *max_element(repc.begin(), repc.end());
    cout << calci << endl;

    return 0;
}