#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve ()
{
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int& y : a) cin >> y;

    sort(a.begin(), a.end());

    vector<int> ans_vec;
    int i = 0, j = n-1;
    int sum = 0, previous = 0, ans = 0;
    while (i <= j)
    {
        // cout << i << ' ' << j << '\n';
        if ((a[i] + sum)/x > previous)
        {
            ans += a[j];
            ans_vec.push_back(a[j]);
            sum += a[j];
            j--;
        }
        else
        {
            ans_vec.push_back(a[i]);
            sum += a[i];
            i++;
        }
        previous = sum/x;
        // cout << sum << '\n';
        // cout << previous << '\n';
    }

    cout << ans << '\n';
    for (int y : ans_vec) cout << y << ' ';
    cout << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
