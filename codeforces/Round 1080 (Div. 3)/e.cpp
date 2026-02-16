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
const int mod = 1e9+7;
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

void solve ()
{
    int n; cin >> n;
    vi parent(n+1);
    vvi children(n+1);

    rep(u, 1, n+1)
    {
        int a, b;
        cin >> a >> b;

        if(a == 0 and b == 0)
            continue;

        children[u].pb(a);
        children[u].pb(b);
        parent[a] = u;
        parent[b] = u;
    }

    vi subtree(n+1);

    auto dfs1 = [&](auto rc, int u) -> void
    {
        if(children[u].empty())
            return;

        rc(rc, children[u][0]);
        rc(rc, children[u][1]);

        subtree[u] = (subtree[children[u][0]] + subtree[children[u][1]] + 4) % mod;
    };

    dfs1(dfs1, 1);

    vi ans(n+1);

    auto dfs2 = [&](auto rc, int u) -> void
    {
        ans[u] = (subtree[u] + 1 + ans[parent[u]]) % mod;

        if(children[u].empty()) return;

        rc(rc, children[u][0]);
        rc(rc, children[u][1]);
    };

    dfs2(dfs2, 1);

    rep(i, 1, n+1) cout << ans[i] << ' ';
    cout << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
