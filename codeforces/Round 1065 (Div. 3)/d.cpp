#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n; cin >> n;
    vector<int> v(n);
    for(int& x : v) cin >> x;

    int sum = 0;
    for (int i = n-1; i >= 1; i--)
    {
        sum += v[i];

        int sz = n - i;
        if (sum == (sz*(sz+1))/2)
        {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
