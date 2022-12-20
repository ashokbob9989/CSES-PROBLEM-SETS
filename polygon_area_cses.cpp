#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld double
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ff first
#define ss second
#define ins insert
#define vll vector <ll>
#define vvll vector <vll>
#define vbool vector <bool>
#define pll pair <ll,ll>
#define vpll vector <pll>
#define set_bits __builtin_popcountll
#define sz(v) (int)v.size()
#define allin(v) v.begin(), v.end()
#define allinr(v) v.rbegin(), v.rend()
#define desc() greater <ll>()
#define jaldi ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class key, class value> using omap = tree <key,value,less<key>,rb_tree_tag,tree_order_statistics_node_update>;
const int ebl = 1e9+7;
const int newmod = 998244353;
const int N = 2e5+7;
const ll inf = 1e18;
const ld eps = 1e-9;
#define PI 3.141592653589793238462
ll gcd(ll a, ll b) { while (b) {a %= b; swap(a,b);} return a; }
ll lcm(ll a, ll b) { ll g=gcd(a,b); ll res=a*(b/g); return res; }
ll extended_gcd(ll a, ll b, ll &x, ll &y) { if (b==0) { x=1; y=0; return a; } ll x1,y1; ll g=extended_gcd(b,a%b,x1,y1); x=y1; y=x1-y1*(a/b); return g; }
ll binExp(ll a, ll b, ll m=ebl) { a = a % m; ll res = 1; while (b) { if (b&1) { res=(res * a) % m; } a=(a * a) % m; b>>=1; } return res; }
ll mod_inv(ll a, ll m=ebl) { a = a % m; return binExp(a,m-2,m); }
ll mod_add(ll a, ll b, ll m=ebl) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
ll mod_sub(ll a, ll b, ll m=ebl) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m=ebl) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
ll mod_div(ll a, ll b, ll m=ebl) { a = a % m; ll binv = mod_inv(b,m); return (((a * binv) % m) + m) % m; }
ll sqrtll(ll n) { ll lo=0,hi=1e9+7; while (hi-lo>1) { ll m=(hi+lo)/2; if (m*m<=n) { lo=m; } else { hi=m-1; }} if (hi*hi<=n) { return hi; }
return lo; }
ld sqrtld(ll n) { ld lo=0,hi=1e9+7; while (hi-lo>eps) { ld m=(hi+lo)/2; if ((n-m*m)>eps) { lo=m; } else { hi=m-eps; }} return lo; }
ll do_it()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> vp;
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        vp.push_back({x, y});
        // vp[i]=make_pair(x,y);
    }
    ll calci = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x1 = vp.at(i).first;
        ll y1 = vp.at(i).second;
        ll x2 = vp.at((i + 1) % n).first; // taking of mod value coz:: for the all pairs we iterated its fine but now ... for the last vertex at pos ==n-1 if we add +1 then n-1+1=n its mod n%n==0 so it becomes as first position..so actually we are doing this to get pair between first and last vertex too.coz they said line exits between 1 and last vertex.
        ll y2 = vp.at((i + 1) % n).second;

        calci += ((x1 * y2) - (x2 * y1)); // actual area is ((x1*y2)-(x2*y1))/2; for each step .... so at final 2*area we need to find so....2*(a1/2 + a2/2 +....)= just do a1+a2+....
    }
    return abs(calci); // area cant be negative
}
int32_t main()
{
    ll sol = do_it();
    cout << sol << endl;
    return 0;
}