#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int s, a, b, x;
    cin >> s >> a >> b >> x;

    int cycles = x / (a + b);
    int remaining = x % (a + b);

    int ans = min(a, remaining) * s + cycles*a*s;

    cout << ans << '\n';

    return 0;
}
