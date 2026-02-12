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

struct MonoQ
{
    deque<pii> dq;

    void insert(int x, int i)
    {
        while(!dq.empty() and dq.back().first > x)
            dq.pop_back();

        dq.eb(x, i);
    }

    void remove(int i)
    {
        if(dq.front().second == i)
            dq.pop_front();
    }

    int get ()
    {
        return dq.front().first;
    }
};

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    int x, a, b, c;
    cin >> x >> a >> b >> c;

    vi v(n);
    v[0] = x;
    rep(i, 1, n)
    {
        v[i] = (v[i-1]*a + b)%c;
    }

    MonoQ dq;

    rep(i, 0, k)
        dq.insert(v[i], i);

    int ans = dq.get();

    rep(i, k, n)
    {
        dq.remove(i-k);
        dq.insert(v[i], i);
        ans ^= dq.get();
    }

    cout << ans << '\n';

    return 0;
}
