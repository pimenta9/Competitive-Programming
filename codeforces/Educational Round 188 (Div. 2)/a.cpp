#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;
    string s; cin >> s;

    int ans;
    for(int i = 0; i < n; i++)
        if(s[i] == 'L') {ans = i+1; break;}

    cout << ans << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
