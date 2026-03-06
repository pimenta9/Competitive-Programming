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
    int n, h, k;
    cin >> n >> h >> k;

    vi v(n); cin >> v;

    int sum = 0;
    for(int x : v) sum += x;

    int ans = n*(h/sum) + ((h-1)/sum)*k;
    h %= sum;

    // debug(sum)
    // debug(h)
    // debug(ans)

    if(h == 0)
    {
        cout << ans << endl;
        return;
    }

    vi prefix_min(n), suffix_max(n);
    vi psum(n+1); partial_sum(all(v), psum.begin()+1);

    prefix_min[0] = v[0];
    for(int i = 1; i < n; i++)
        prefix_min[i] = min(v[i], prefix_min[i-1]);

    suffix_max[n-1] = v[n-1];
    for(int i = n-2; i >= 0; i--)
        suffix_max[i] = max(suffix_max[i+1], v[i]);

    // cout << psum << endl;
    // cout << prefix_min << endl;
    // cout << suffix_max << endl;

    for(int i = 0; i < n; i++)
    {
        if(i == n-1)
        {
            ans += n;
            break;
        }

        if(psum[i+1] >= h)
        {
            ans += i+1;
            break;
        }

        if(psum[i+1] - prefix_min[i] + suffix_max[i+1] >= h)
        {
            ans += i+1;
            break;
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
