#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;

    priority_queue<int> pq;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        pq.push(x);
    }

    for(int i = 0; i < n-1; i++)
    {
        int x = pq.top();
        pq.pop();
        pq.push(x-1);
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int x = pq.top();
        if(x) ans++;
        pq.pop();
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
