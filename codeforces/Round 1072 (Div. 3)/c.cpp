#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n, k;
    cin >> n >> k;

    map<int, bool> in_q;
    map<int, int> dist;

    queue<pair<int, int>> q;

    q.push({n, 0});
    dist[n] = 0;
    in_q[n] = true;

    while(!q.empty())
    {
        auto [x, d] = q.front();
        q.pop();

        int low = x/2;
        int up = (x+1)/2;

        if(low > 0 and !in_q[low])
        {
            q.push({low, d+1});
            dist[low] = d+1;
            in_q[low] = true;
        }

        if(up > 0 and !in_q[up])
        {
            q.push({up, d+1});
            dist[up] = d+1;
            in_q[up] = true;
        }
    }

    if(in_q[k]) cout << dist[k] << '\n';
    else cout << "-1\n";
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
