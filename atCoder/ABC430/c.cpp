#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, a, b;
    cin >> n >> a >> b;

    string s; cin >> s;

    vector<int> psum_a(n+1, 0), psum_b(n+1, 0);

    for (int i = 0; i < n; i++)
    {
        int add_a = s[i] == 'a' ? 1 : 0;
        int add_b = s[i] == 'b' ? 1 : 0;

        psum_a[i+1] = psum_a[i] + add_a;
        psum_b[i+1] = psum_b[i] + add_b;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << i << ": ";
        if (psum_a[i] < a) continue;

        int idx_a = upper_bound(psum_a.begin(), psum_a.end(), psum_a[i] - a) - psum_a.begin();
        int idx_b = lower_bound(psum_b.begin(), psum_b.end(), psum_b[i] - b + 1) - psum_b.begin() + 1;

        int add = max(0LL, idx_a - idx_b + 1);
        // cout << add << '\n';
        ans += add;
    }

    cout << ans << '\n';

    return 0;
}
