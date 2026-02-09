#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    int total = n, ans = 0;
    while(total < k)
    {
        ans++;
        total += ++n;
    }

    cout << ans << '\n';

    return 0;
}
