#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<int> v(n);
    for(int& x : v) cin >> x;

    int ans = 0, reach = 0;
    for (int i = 0; i < n; i++)
    {
        if (reach < i) break;

        ans++;
        reach = max(reach, i + v[i] - 1);
    }

    cout << ans << '\n';

    return 0;
}
