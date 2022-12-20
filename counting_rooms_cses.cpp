#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ebl 1000000007
#define modinv2 500000004

vector<pair<ll, ll>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; //upward ,down, left,right
vector<vector<bool>> vis; // to keep track that we visited a floor/room and is it possible to get on certain floor /room???
ll n, m;
ll tot_rooms = 0;
bool isvalid(ll x, ll y) // is va;id to move at certain floor /room
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;

    if (vis[x][y])
        return false; // if already visited

    return true;
}
void dfs(ll i, ll j)
{
    vis[i][j] = true;
    for (auto it : dir)
    {
        if (isvalid(i + it.first, j + it.second))
        {
            dfs(i + it.first, j + it.second); //do dfs untill we find no further moves
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    vis.resize(n);

    for (ll i = 0; i < n; i++)
        vis[i].resize(m);

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '#')
                vis[i][j] = true;//make firstly them as marked coz we cantgo here anyway
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                dfs(i, j);
                tot_rooms++;
            }
        }
    }
    cout << tot_rooms << endl;
}