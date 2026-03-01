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

const int mod = 998244353;
const int M = 1e7;
int lpf[M + 1];
vector<int> primes;

void init()
{
    for(int i = 2; i <= M; i++)
    {
        if(lpf[i] == 0)
        {
            primes.pb(i);
            lpf[i] = i;
        }

        for(int j = 0; i * primes[j] <= M; j++)
        {
            lpf[i * primes[j]] = primes[j];
            if(lpf[i] == primes[j]) break;
        }
    }
}

int fexp (int a, int b)
{
    if(b == 0) return 1;

    int h = fexp(a, b/2);
    h = mul_mod(h, h, mod);
    if(b & 1) h = mul_mod(h, a, mod);
    return h;
}

int inv(int n)
{
    return fexp(n, mod-2);
}

void solve ()
{
    int n; cin >> n;
    vi v(n); cin >> v;

    map<int, pii> e1, e2;
    for(int i = 0; i < n; i++)
    {
        int x = v[i];

        while(x > 1)
        {
            int p = lpf[x];
            int e = 0;
            while(x % p == 0)
            {
                e++;
                x /= p;
            }

            if(e1[p].first == 0)
            {
                e1[p] = {e, i};
                continue;
            }

            if(e > e1[p].first)
            {
                e2[p] = e1[p];
                e1[p] = {e, i};
                continue;
            }

            if(e > e2[p].first)
            {
                e2[p] = {e, i};
            }
        }
    }

    int lcm = 1;
    for(auto [p, val] : e1)
    {
        auto [e, i] = val;

        lcm = mul_mod(lcm, fexp(p, e), mod);
    }

    for(int i = 0; i < n; i++)
    {
        int x = v[i];
        int l = lcm;
        while(x > 1)
        {
            int p = lpf[x];

            while(x % p == 0)
            {
                x /= p;
            }

            if(e1[p].second == i)
            {
                l = mul_mod(l, inv(fexp(p, e1[p].first)), mod);
                l = mul_mod(l, fexp(p, e2[p].first), mod);
            }
        }
        cout << l << ' ';
    }
    cout << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    init();

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
