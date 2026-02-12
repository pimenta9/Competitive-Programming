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

void solve ()
{
    int n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;

    vi x(n), y(n);
    cin >> x;
    cin >> y;

    map<int, int> col_highest, col_lowest;
    
    rep(i, 0, n)
    {
        col_highest[x[i]] = max(col_highest[x[i]], y[i]);
        if(col_lowest[x[i]] == 0 or y[i] < col_lowest[x[i]])
            col_lowest[x[i]] = y[i];
    }

    vector<pii> col(sz(col_highest));
    int idx = 0;
    for(auto [c, h] : col_highest)
        col[idx++].fi = h;
    idx = 0;
    for(auto [c, h] : col_lowest)
        col[idx++].se = h;

    n = sz(col_highest);
    vector<pii> dp(n);
    int up = col[n-1].fi;
    int down = col[n-1].se;
    dp[n-1].fi = (up - down) + abs(down - by);
    dp[n-1].se = (up - down) + abs(up - by);

    for(int i = n-2; i >= 0; i--)
    {
        up = col[i].fi;
        down = col[i].se;
        int next_up = col[i+1].fi;
        int next_down = col[i+1].se;

        dp[i].fi = (up - down) + abs(down - next_up) + dp[i+1].fi;
        dp[i].fi = min(dp[i].fi, (up - down) + abs(down - next_down) + dp[i+1].se);

        dp[i].se = (up - down) + abs(up - next_up) + dp[i+1].fi;
        dp[i].se = min(dp[i].se, (up - down) + abs(up - next_down) + dp[i+1].se);
    }

    // for(int i = 0; i < n; i++)
    //     cout << dp[i].fi << ' ' << dp[i].se << '\n';

    int start_up = abs(ay - col[0].fi) + dp[0].fi;
    int start_down = abs(ay - col[0].se) + dp[0].se;

    int ans = min(start_up, start_down) + (bx - ax);
    cout << ans << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
