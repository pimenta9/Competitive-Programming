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

// testar caso N = 1;
void solve ()
{
    map<int, int> freq;
    int n; cin >> n;
    vvi v(n);
    rep(i, 0, n)
    {
        int l; cin >> l;
        v[i].resize(l);
        rep(j, 0, l)
        {
            cin >> v[i][j];
            freq[v[i][j]]++;
        }
        reverse(all(v[i]));
    }

    // debug v
    // for(auto u : v)
    //     cout << u << '\n';

    int num_elems = freq.size();

    map<int, bool> used;
    vi ans, skip(n);

    while(true)
    {
        int idx_smallest = 0;
        while(skip[idx_smallest]) idx_smallest++;

        for(int i = idx_smallest+1; i < n; i++)
        {
            if(skip[i]) continue;
            map<int, bool> seen;
            for(int j1 = 0, j2 = 0; ; j1++, j2++)
            {
                while(j1 < sz(v[idx_smallest]) and (used[v[idx_smallest][j1]] or seen[v[idx_smallest][j1]]))
                    j1++;
                while(j2 < sz(v[i]) and (used[v[i][j2]] or seen[v[i][j2]]))
                    j2++;

                if(j1 == sz(v[idx_smallest]) and j2 == sz(v[i]))
                    break;

                if(j1 == sz(v[idx_smallest]))
                    break;

                if(j2 == sz(v[i]))
                {
                    idx_smallest = i;
                    break;
                }

                if(v[idx_smallest][j1] < v[i][j2])
                    break;

                if(v[i][j2] < v[idx_smallest][j1])
                {
                    idx_smallest = i;
                    break;
                }

                seen[v[i][j2]] = true;
            }
        }
        skip[idx_smallest] = 1;
        
        for(int i = 0; i < sz(v[idx_smallest]); i++)
        {
            int x = v[idx_smallest][i];
    
            if(used[x]) continue;
            used[x] = true;

            ans.push_back(x);
            if(ans.size() == num_elems)
            {
                cout << ans << '\n';
                return;
            }
        }
    }
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
