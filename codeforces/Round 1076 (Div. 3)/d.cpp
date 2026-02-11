#include <bits/stdc++.h>
using namespace std;

#define ub upper_bound
#define lb lower_bound
#define pii pair<int, int>
#define int long long

void solve ()
{
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int& x : a) cin >> x;
    for(int& x : b) cin >> x;

    sort(a.begin(), a.end());

    int next_compress = 1;
    map<int, int> compress;
    vector<int> val(1);

    for(int i = 0; i < n; i++)
    {
        int x = a[i];

        if(compress[x])
        {
            a[i] = compress[x];
            continue;
        }

        compress[x] = next_compress;
        val.push_back(x);
        a[i] = compress[x];
        next_compress++;
    }

    vector<int> psum(n+1);
    partial_sum(b.begin(), b.end(), psum.begin()+1);

    int best;

    for(int x = 1; x < next_compress; x++)
    {
        int num_swords = n - (lb(a.begin(), a.end(), x) - a.begin());

        int num_levels = ub(psum.begin(), psum.end(), num_swords) - psum.begin() - 1;

        int score = val[x] * num_levels;
        // cout << num_swords << ' ' << num_levels << ' ' << score << '\n';
        if(x == 1 or score > best)
            best = score;
    }

    cout << best << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
