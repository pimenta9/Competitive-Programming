#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

void solve ()
{
    int n; cin >> n;
    vector<int> p(n), a(n);
    for(int& x : p) cin >> x;
    for(int& x : a) cin >> x;

    vector<int> R(n+1), L(n+1);
    for(int i = 0; i < n; i++)
        R[a[i]] = i + 1;
    for(int i = n-1; i >= 0; i--)
        L[a[i]] = i + 1;

    vector<int> rightmost(n), leftmost(n);
    for(int i = 0; i < n; i++)
    {
        rightmost[i] = R[p[i]];
        leftmost[i] = L[p[i]];
    }

    // for(int i = 0; i < n; i++)
    //     cout << rightmost[i] << ' ';
    // cout << '\n';
    // for(int i = 0; i < n; i++)
    //     cout << leftmost[i] << ' ';
    // cout << '\n';

    vector<int> prefix_max(n);
    prefix_max[0] = rightmost[0];
    for(int i = 1; i < n; i++)
        prefix_max[i] = max(prefix_max[i-1], rightmost[i]);

    // for(int x : prefix_max) cout << x << ' ';
    // cout << '\n';

    for(int i = n-1; i >= 1; i--)
    {
        if(leftmost[i] == 0) continue;

        if(leftmost[i] < prefix_max[i-1])
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
