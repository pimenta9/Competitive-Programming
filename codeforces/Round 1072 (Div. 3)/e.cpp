#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;

    vector<int> p(n);
    for(int& x : p) cin >> x;

    vector<vector<int>> idx(n);

    for(int i = 0; i < n-1; i++)
    {
        int dist = abs(p[i+1] - p[i]);

        idx[dist].push_back(i);
    }

    // for(int i = 1; i <= n-1; i++)
    // {
    //     cout << i << ": ";
    //     for(int x : idx[i]) cout << x << ' ';
    //     cout << '\n';
    // }

    int ans = ((n)*(n+1))/2 - n;

    cout << ans << ' ';

    map<int, bool> used1, used2;
    used1[-1] = true, used1[n-1] = true;
    used2[1] = true, used2[-(n-1)] = true;

    for(int k = 2; k <= n-1; k++)
    {
        int dist = k-1;

        for(int i = 0; i < size(idx[dist]); i++)
        {
            int index = idx[dist][i];

            int up = used1.upper_bound(index)->first;
            int down = -used2.upper_bound(-index)->first;

            // cout << up << ' ' << down << '\n';

            int left = index - down;
            int right = up - index;

            ans -= left*right;

            used1[index] = true;
            used2[-index] = true;
        }

        cout << ans << ' ';
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
