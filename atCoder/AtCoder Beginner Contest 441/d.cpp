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
#define sz(x) int(x.size())
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

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m, L, s, t;
    cin >> n >> m >> L >> s >> t;

    vector<vector<pii>> adj(n);

    rep(i, 0, m)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;

        adj[u].eb(v, c);
    }

    map<int, bool> ans;

    queue<array<int, 3>> q;
    q.push({0, 0, 0});

    while(!q.empty())
    {
        auto [u, l, sum] = q.front();
        q.pop();

        if(l == L)
        {
            if(sum >= s and sum <= t)
                ans[u] = true;
            continue;
        }

        for(auto [v, c] : adj[u])
        {
            q.push({v, l+1, sum+c});
        }
    }

    for(auto [u, _] : ans)
        cout << u+1 << ' ';
    cout << '\n';

    return 0;
}
