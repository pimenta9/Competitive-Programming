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
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vi>
#define endl '\n'

// consts
// const int oo = 4e18;
// const long double pi = acos(-1.0);
// const int mod = (int) 1e9+7;
// const int MAXN = 1e5;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// templates
template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x : v) in >> x;
    return in;
}

template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) { 
    for (const T &x : v) out << x << ' '; 
    return out;
}

void solve ()
{
    int n; cin >> n;
    vi a(n); cin >> a;

    vvi adj(n);
    rep(i, 0, n-1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi seen(n);
    vi sum(n);

    auto calc_sum = [&](auto rc, int u) -> void
    {
        seen[u] = true;
        int cur = a[u];
        for(int v : adj[u])
        {
            if(seen[v]) continue;
            rc(rc, v);
            cur += sum[v];
        }
        sum[u] = cur;
    };

    calc_sum(calc_sum, 0);
    seen.assign(n, 0);

    vi height(n);

    auto calc_height = [&](auto rc, int u) -> void
    {
        seen[u] = true;
        int h = 0;
        for(int v : adj[u])
        {
            if(seen[v]) continue;
            rc(rc, v);
            h = max(h, height[v]);
        }
        height[u] = h + 1;
    };

    calc_height(calc_height, 0);
    seen.assign(n, 0);

    vi cost(n);

    auto calc_cost = [&](auto rc, int u) -> void
    {
        seen[u] = true;
        int ans = a[u];
        for(int v : adj[u])
        {
            if(seen[v]) continue;
            rc(rc, v);
            ans += cost[v] + sum[v];
        }
        cost[u] = ans;
    };

    calc_cost(calc_cost, 0);
    seen.assign(n, 0);

    vi ans(n);

    auto calc_ans = [&](auto rc, int u) -> void
    {
        seen[u] = true;
        vi children;
        int total = 0;
        for(int v : adj[u])
            if(!seen[v])
            {
                children.pb(v);
                total += cost[v];
            }
        int num_children = children.size();

        if(num_children == 0)
        {
            ans[u] = 0;
            return;
        }

        for(int v : children)
            rc(rc, v);

        if(num_children == 1)
        {
            ans[u] = ans[children[0]] + sum[children[0]];
            return;
        }

        int best = 0;
        for(int v : children)
        {
            int total_ = total;
            total_ -= cost[v];
            total_ += ans[v] + sum[v];
            best = max(best, total_);
        }

        ans[u] = best;

        int h1 = 0, h2 = 0;
        for(int v : children)
        {
            int h = height[v];
            if(h > h1)
            {
                swap(h1, h2);
                h1 = h;
            }
            else if (h > h2) h2 = h;
        }

        best = 0;
        for(int v : children)
        {
            int h = height[v] == h1 ? h2 : h1;
            best = max(best, sum[v]*h);
        }

        ans[u] = max(ans[u], total + best);
    };

    calc_ans(calc_ans, 0);
    seen.assign(n, 0);

    cout << ans << endl;
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
