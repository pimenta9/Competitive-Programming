#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;

    vector<pair<int, int>> stops;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        stops.emplace_back(x, y);
    }

    int l, p;
    cin >> l >> p;

    if(l == 0)
    {
        cout << "0\n";
        return;
    }

    for(auto& [x, y] : stops)
        x = l - x;

    sort(stops.begin(), stops.end());

    int r = p, idx = 0, ans = 0;
    priority_queue<int> pq;
    while(true)
    {
        while(idx < n and stops[idx].first <= r)
        {
            pq.push(stops[idx].second);
            idx++;
        }

        if(pq.empty())
        {
            cout << "-1\n";
            return;
        }

        if(r >= l)
            break;

        r += pq.top();
        pq.pop();
        ans++;

        if(r >= l)
            break;
    }

    cout << ans << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
