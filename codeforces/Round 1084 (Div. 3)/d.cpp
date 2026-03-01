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
    int n, x, y;
    cin >> n >> x >> y;

    vi v(n); cin >> v;

    vi between;
    rep(i, x, y)
    {
        between.pb(v[i]);
        v[i] = -1;
    }

    vi outside;
    rep(i, 0, n)
        if(v[i] != -1) outside.pb(v[i]);

    int lowest_btw = n+1;
    int first_btw = 0;
    rep(i, 0, sz(between))
        if(between[i] < lowest_btw)
        {
            lowest_btw = between[i];
            first_btw = i;
        }

    stack<int> ots, btw;
    for(int i = sz(outside)-1; i >= 0; i--)
        ots.push(outside[i]);
    for(int i = (first_btw-1+sz(between))%sz(between); between[i] != -1; i = (i - 1 + sz(between)) % sz(between))
    {
        btw.push(between[i]);
        between[i] = -1;
    }

    vi ans;
    while(!ots.empty() and !btw.empty())
    {
        if(ots.top() > btw.top())
            break;

        ans.push_back(ots.top());
        ots.pop();
    }

    while(!btw.empty())
    {
        ans.pb(btw.top());
        btw.pop();
    }
    while(!ots.empty())
    {
        ans.pb(ots.top());
        ots.pop();
    }

    cout << ans << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
