#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;

    int ans = 0, prev;
    cin >> prev;
    for(int i = 1; i < n; i++)
    {
        int cur; cin >> cur;

        ans += max(0ll, prev - cur);
        prev = max(prev, cur);
    }

    cout << ans << '\n';

    return 0;
}
