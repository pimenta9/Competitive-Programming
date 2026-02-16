#include <bits/stdc++.h>
using namespace std;

// defines
#define pii pair<int, int>
#define int long long
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define gauss(x) ((x*(x+1))/2)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int32_t(x.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define rep(i, a, b) for(int i = a; i < b; i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vi>

// consts
const int oo = 4e18;
const long double pi = acos(-1.0);
const int mod = (int) 1e9+7;
const int MAXN = 1e5;

// templates
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}

template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; 
    return out;
}
//

int calc(const vvi& adj, const int& u, vi& dp, vi& vis)
{
    if(vis[u]) return dp[u];
    vis[u] = 1;

    int rtrn = 1;
    int add_on = 0;
    for(int v : adj[u])
    {
        add_on = max(add_on, calc(adj, v, dp, vis));
    }

    rtrn += add_on;
    return dp[u] = rtrn;
}

void solve ()
{
    int n; cin >> n;
    vvi v(n, vi(3));
    rep(i, 0, n)
        cin >> v[i][0] >> v[i][1] >> v[i][2];

    auto lower = [&](int i, int j) -> bool
    {
        int a1 = v[i][0], b1 = v[i][1], c1 = v[i][2];
        int a2 = v[j][0], b2 = v[j][1], c2 = v[j][2];
        int a = a2 - a1, b = b2 - b1, c = c2 - c1;

        if(a != 0)
        {
            int delta = b*b - 4*a*c;
            return delta < 0 and a > 0;
        }

        return b == 0 and c > 0;
    };

    vvi adj(n);
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            if(i == j)
                continue;

            if(lower(i, j))
                adj[i].pb(j);
        }
    }

    vi dp1(n), vis(n);
    rep(u, 0, n) calc(adj, u, dp1, vis);

    vvi adj2(n);
    rep(u, 0, n)
        for(int v : adj[u])
            adj2[v].pb(u);

    vi dp2(n), vis2(n);
    rep(u, 0, n) calc(adj2, u, dp2, vis2);

    rep(i, 0, n)
    {
        cout << dp1[i] + dp2[i] - 1 << ' ';
    }
    cout << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
