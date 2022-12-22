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
#define modinv2 500000004
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

ll n,m;
vll vis;
vll par;
vvll adj;
ll start=0;
ll endv=0;

bool dfs(ll ver, ll p) // ver is the current vertex.... p = its parent.
{
    vis[ver]=true; // mark vertex as true.
    par[ver]=p; // parent of its vertex is p.
    for(auto child: adj[ver]) // for every child for ver..
    {
        if(child==p)continue;

        if(vis[child])// loop exists.
        {
            start=child;
            endv=ver;
            return true;
        }
        if(!vis[child])
            if(dfs(child,ver))
                return true;
    }
    return false;
}

bool is_cycle() // to check if cycle exists or not.
{
    for(ll i=1;i<=n;++i) 
    {
        if(!vis[i]) // if node is not visited.
            if(dfs(i,-1))return true;     // do dfs 
              
    }
    return false;
}
int32_t main()
{

    cin>>n>>m;
    adj.resize(n+1); // we will store parent to child in adjacency list.
    vis.resize(n+1); // we keep track we visited the vertex or not.
    par.resize(n+1);  // we store parent of current child.

    for(ll i=0;i<m;i++)
    {
        ll u,v; // conncetd components.
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if(!is_cycle())
    {
        cout<<"IMPOSSIBLE"<<endl; // if there is no cycle no point of printing.
        return 0;
    }

    vll calci; // cycle from where to where ??... so it behaves like sol vector.
    ll temp=endv;  // to iterate  from end to start again for getting values at nodes in cycle.
    calci.pb(temp); // starting from endvertex.

    while(temp!=start)  // ieretingtill start vertex.
    {
        calci.pb(par[temp]);
        temp=par[temp];
    }

    calci.pb(endv);
    cout<<calci.size()<<endl;

    for(auto it : calci){
    cout<<it<<" ";
    }

}