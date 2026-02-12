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
#define vb vector<bool>

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

    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    vb taka(26), aoki(26);
    for(char c : s) taka[c - 'a'] = true;
    for(char c : t) aoki[c - 'a'] = true;

    int q; cin >> q;

    while(q--)
    {
        string w; cin >> w;

        bool ok1 = true, ok2 = true;

        for(char c : w)
        {
            if(!taka[c - 'a'])
                ok1 = false;
            if(!aoki[c - 'a'])
                ok2 = false;
        }

        if(ok1 and ok2) cout << "Unknown\n";
        else if (ok1) cout << "Takahashi\n";
        else cout << "Aoki\n";
    }

    return 0;
}
