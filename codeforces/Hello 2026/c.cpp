#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    int a = 0, b = 0;
    int left = k - 1, right = n - k;

    while(true)
    {
        int expanded = 0;
        if(a + 1 <= left and (a+1) + b + max(a+1, b) - 1 <= m)
        {
            a++;
            expanded++;
        }
        if(b + 1 <= right and a + (b+1) + max(a, b+1) - 1 <= m)
        {
            b++;
            expanded++;
        }

        if(expanded == 0) break;
    }

    cout << a + b + 1 << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
