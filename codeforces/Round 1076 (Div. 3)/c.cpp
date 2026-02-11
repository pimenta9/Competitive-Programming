#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define int long long

void solve ()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n), b(n);
    for(int& x : a) cin >> x;
    for(int& x : b) cin >> x;

    for(int i = 0; i < n; i++)
        a[i] = max(a[i], b[i]);

    for(int i = n-2; i >= 0; i--)
        a[i] = max(a[i], a[i+1]);

    vector<int> psum(n+1);
    partial_sum(a.begin(), a.end(), psum.begin()+1);

    while(q--)
    {
        int l, r;
        cin >> l >> r;

        cout << psum[r] - psum[l-1] << ' ';
    }
    cout << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
