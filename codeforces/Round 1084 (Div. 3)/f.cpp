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
    int n, m;
    cin >> n >> m;

    vvi yx(n + 1);
    rep(i, 0, n)
    {
        int x, y;
        cin >> x >> y;
        yx[y].pb(x);
    }

    priority_queue<int, vi, greater<int>> pq;
    int best_sum = 0, sum = 0;
    vi left(n+2);
    for(int y = n; y >= 0; y--)
    {
        int sz = y + 1;
        while(pq.size() > sz)
        {
            sum -= pq.top();
            pq.pop();
        }
        int next_left = pq.size() < sz ? sum : sum - pq.top();
        left[sz] = max(left[sz], next_left);
        for(int x : yx[y])
        {
            if(pq.size() < sz)
            {
                pq.push(x);
                sum += x;
            }
            else
            {
                while(pq.size() > sz)
                {
                    sum -= pq.top();
                    pq.pop();
                }
                if(x > pq.top())
                {
                    sum -= pq.top();
                    pq.pop();
                    pq.push(x);
                    sum += x;
                }
            }

            best_sum = max(best_sum, sum);

            next_left = pq.size() < sz ? sum : sum - pq.top();
            left[sz] = max(left[sz], next_left);
        }
    }

    vi prefix_max(n+2);
    rep(i, 1, n+2)
    {
        prefix_max[i] = max(prefix_max[i-1], left[i]);
    }

    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        cout << max(best_sum, x + prefix_max[y+1]) << ' ';
    }
    cout << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
