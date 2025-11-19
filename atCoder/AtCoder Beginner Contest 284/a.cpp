#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<string> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = n-1; i >= 0; i--) cout << v[i] << '\n';

    return 0;
}
