#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<int> v(n);
    for(int& x : v) cin >> x;

    vector<int> psum(n+1);
    partial_sum(v.begin(), v.end(), psum.begin()+1);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = psum[j+1] - psum[i];
            bool found = false;
            for (int k = i; k <= j; k++)
            {
                if (sum % v[k] == 0) found = true;
            }
            if (!found) ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
