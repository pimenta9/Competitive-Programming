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
// const int oo = 4e18;
// const long double pi = acos(-1.0);
// const int mod = (int) 1e9+7;
// const int MAXN = 1e5;

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
    vi v(n); cin >> v;

    vi l(n); stack<pii> s;
    for(int i = 0; i < n; i++)
    {
        int x = v[i];
        while(!s.empty() and s.top().first < x)
            s.pop();
        l[i] = s.empty()? -1 : s.top().second;
        s.emplace(x, i);
    }

    vvi ct(n, vi(2, -1));
    int root = 0;
    for(int i = 1; i < n; i++)
    {
        int x = v[i];
        if(x > v[root])
        {
            ct[i][0] = root;
            root = i;
            continue;
        }

        ct[i][0] = ct[l[i]][1];
        ct[l[i]][1] = i;
    }

    auto dfs = [&](auto rc, int u) -> int
    {
        if(u == -1) return 0;
        return 1 + max(rc(rc, ct[u][0]), rc(rc, ct[u][1]));
    };

    cout << n - dfs(dfs, root) << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
