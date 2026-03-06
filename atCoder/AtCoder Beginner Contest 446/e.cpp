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

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int m, a, b;
    cin >> m >> a >> b;

    vvi grid(m, vi(m));
    rep(j, 0, m) grid[0][j] = 1;
    rep(i, 0, m) grid[i][0] = 1;

    auto calc = [&](auto rc, int i, int j) -> int
    {
        if(grid[i][j] != 0)
        {
            if(grid[i][j] == 2)
                grid[i][j] = 3;
            return grid[i][j];
        }

        grid[i][j] = 2;
        int k = (b*i + a*j) % m;
        return grid[i][j] = rc(rc, j, k);
    };

    int ans = 0;
    rep(i, 1, m)
    {
        rep(j, 1, m)
        {
            if(calc(calc, i, j) == 3)
                ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
