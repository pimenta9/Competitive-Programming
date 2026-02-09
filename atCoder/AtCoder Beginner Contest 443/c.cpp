#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, t;
    cin >> n >> t;

    if(n == 0)
    {
        cout << t << '\n';
        return 0;
    }

    vector<int> v(n);
    for(int& x : v) cin >> x;
    v.push_back(t);

    int ans = v[0];
    int open = v[0]+100;

    for(int i = 1; i <= n; i++)
    {
        if(v[i] < open) continue;

        ans += v[i]-open;
        open = v[i]+100;
    }

    cout << ans << '\n';

    return 0;
}
