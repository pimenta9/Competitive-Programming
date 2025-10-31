#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    map<int, bool> mp;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;

        sum += a;
        mp[a] = true;
    }

    if (mp[sum - m]) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
