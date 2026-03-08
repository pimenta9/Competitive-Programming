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
    int n, h;
    cin >> n >> h;

    vi a; a.pb(h);
    rep(i, 0, n)
    {
        int x; cin >> x;
        a.pb(x);
    }
    a.pb(h);

    if(n == 1)
    {
        cout << h - a[1] << endl;
        return;
    }

    vi L(n+2); stack<pii> s1;
    for(int i = 0; i <= n+1; i++)
    {
        int x = a[i];
        while(!s1.empty() and s1.top().first <= x)
            s1.pop();

        L[i] = s1.empty()? 0 : s1.top().second;
        s1.emplace(x, i);
    }

    // cout << L << endl;

    vi R(n+2); stack<pii> s2;
    for(int i = n+1; i >= 0; i--)
    {
        int x = a[i];
        while(!s2.empty() and s2.top().first <= x)
            s2.pop();

        R[i] = s2.empty()? n+1 : s2.top().second;
        s2.emplace(x, i);
    }

    // cout << R << endl;

    vector<pii> order;
    for(int i = 1; i <= n; i++)
        order.eb(a[i], i);
    sort(rall(order));

    vi dp(n+2);

    for(auto [h, i] : order)
    {
        int next = a[L[i]] < a[R[i]] ? L[i] : R[i];
        int cur = (a[next] - h) * (R[i] - L[i] - 1);
        if(next > 0 and next < n+1) cur += dp[next];
        dp[i] = cur;
    }

    int ans = 0;
    for(int i = 1; i < n; i++)
    {
        map<int, int> mp;
        mp[a[i]] = i;
        for(int j = i+1; j <= n; j++)
        {
            mp[a[j]] = j;

            int cur = dp[i] + dp[j] - dp[mp.rbegin()->second];
            ans = max(ans, cur);
        }
    }

    cout << ans << endl;
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
