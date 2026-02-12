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
#define sz(x) int(x.size())
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

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    string s; cin >> s;

    int cur_ans = 0;
    map<int, int> freq;
    vi v(n);
    if (s[0] == 'A') v[0] = 1;
    if (s[0] == 'B') v[0] = -1;
    freq[v[0]]++;
    if(v[0] > 0) cur_ans++;
    rep(i, 1, n)
    {
        v[i] = v[i-1];
        if(s[i] == 'A') v[i]++;
        if(s[i] == 'B') v[i]--;
        freq[v[i]]++;
        if(v[i] > 0) cur_ans++;
    }

    int ans = 0;
    for(int i = 0; i < n; freq[v[i++]]--)
    {
        if(i == 0)
        {
            ans += cur_ans;
            continue;
        }

        int prev = i == 1 ? 0 : v[i-2];
        int diff = v[i-1] - prev;

        if(diff > 0)
        {
            cur_ans -= freq[v[i-1]]+1;
        }

        if(diff < 0)
        {
            cur_ans += freq[v[i-1]+1];
        }

        // debug(i);
        // debug(cur_ans);
        ans += cur_ans;
    }

    cout << ans << '\n';

    return 0;
}

// TESTAR CASO N == 1
