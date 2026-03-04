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

const int mod = 998'244'353;

void solve ()
{
    int n; cin >> n;
    vi v(n); cin >> v;

    vi dp(n+1);
    dp[n] = 1;

    for(int l = n-1; l >= 0; l--)
    {
        dp[l] += dp[l+1], dp[l] %= mod;
        vector<int> pi(n - l);
        for(int i = l+1; i < n; i++)
        {
            int j = pi[(i-1)-l]+l;
            while(j > l and v[i] != v[j])
                j = pi[(j-1)-l]+l;
            if(v[i] == v[j])
                j++;
            pi[i-l] = j-l;
            if(pi[i-l] == 0)
                dp[l] += dp[i+1], dp[l] %= mod;
        }
    }
    cout << dp[0] << endl;
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
