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

struct BIT
{
    vi s;
    BIT(int sz)
    {
        s.resize(sz);
    }

    void update (int pos, int diff)
    {
        for(; pos < sz(s); pos |= pos + 1)
            s[pos] += diff;
    }

    int query (int pos)
    {
        int res = 0;
        for(; pos > 0; pos &= pos - 1)
            res += s[pos-1];
        return res;
    }
};

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m, q;
    cin >> n >> m >> q;

    vi x(m); cin >> x;
    vi v(m); cin >> v;
    
    vector<pii> init_harbors;
    rep(i, 0, m) init_harbors.eb(x[i], v[i]);
    sort(all(init_harbors));

    vi tree(n);
    map<int, int> harbors;
    BIT bit(n);
    int last_pos = -1, last_val = -1;
    for(auto [pos, val] : init_harbors)
    {
        harbors[pos] = val;
        if(last_pos == -1 and last_val == -1)
        {
            last_pos = pos, last_val = val;
            continue;
        }

        int sz = pos - last_pos - 1;
        bit.update(pos-1, gauss(sz)*last_val);
        tree[pos-1] = gauss(sz)*last_val;

        last_pos = pos, last_val = val;
    }

    auto query = [&](int pos) -> int
    {
        int ans = bit.query(pos);
        if(harbors[pos]) return ans;
        harbors.erase(pos);

        auto [r_pos, r_val] = *harbors.upper_bound(pos);
        auto [l_pos, l_val] = *(--(harbors.upper_bound(pos)));

        // for(auto [k, v] : harbors) cout << k << ' ' << v << endl;
        // debug(r_pos)
        // debug(r_val)
        // debug(l_pos)
        // debug(l_val)
        int sz1 = r_pos - l_pos - 1;
        int sz2 = r_pos - pos - 1;
        // debug(sz1)
        // debug(sz2)
        int sum = gauss(sz1) - gauss(sz2);
        ans += sum * l_val;

        return ans;
    };

    while(q--)
    {
        int type; cin >> type;

        if(type == 1)
        {
            int pos, val;
            cin >> pos >> val;

            auto [r_pos, r_val] = *harbors.upper_bound(pos);
            auto [l_pos, l_val] = *(--harbors.upper_bound(pos));

            // for(auto [k, v] : harbors) cout << k << ' ' << v << endl;
            // debug(r_pos)
            // debug(r_val)
            // debug(l_pos)
            // debug(l_val)

            harbors[pos] = val;
            int sz = pos - l_pos - 1;
            bit.update(pos-1, gauss(sz)*l_val);
            tree[pos-1] = gauss(sz)*l_val;
            sz = r_pos - pos - 1;
            bit.update(r_pos-1, gauss(sz)*val - tree[r_pos-1]);
            tree[r_pos-1] = gauss(sz)*val;
        }

        // cout << tree << '\n';

        if (type == 2)
        {
            int l, r;
            cin >> l >> r;

            int ans = query(r);
            // cout << query(r) << '\n';
            if (l > 1) ans -= query(l-1);

            cout << ans << endl;
        }
    }

    return 0;
}
