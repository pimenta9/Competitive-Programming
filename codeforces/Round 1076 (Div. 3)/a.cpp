#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

void solve ()
{
    int n, s, x;
    cin >> n >> s >> x;

    int sum = 0;
    vector<int> v(n);
    for(int& x : v)
    {
        cin >> x;
        sum += x;
    }

    if(sum == s)
    {
        cout << "YES\n";
        return;
    }

    if(sum > s)
    {
        cout << "NO\n";
        return;
    }

    int diff = s - sum;

    if(diff % x == 0) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
