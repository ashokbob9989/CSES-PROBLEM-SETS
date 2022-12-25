#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ebl 1000000007
#define modinv2 500000004

int main()
{
    string str;
    cin >> str;
    set<string> s;
    ll n = str.length();
    sort(str.begin(), str.end());
    do
    {
        s.insert(str);
    } while (next_permutation(str.begin(), str.end())); // if the string/array is sorted in reverse order it return false. like 321 then it returen false;

    cout << s.size() << endl;
    for (auto it : s)
        cout << it << endl;
    return 0;
}