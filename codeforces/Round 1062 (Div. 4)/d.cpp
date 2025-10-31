#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve (const vector<int>& primes)
{
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        int x = a[i];

        int cur;
        for (int j = 0; j < primes.size(); j++)
        {
            if (x % primes[j] != 0)
            {
                cur = primes[j];
                break;
            }
        }

        if (ans == -1 or cur < ans)
        {
            ans = cur;
        }
    }

    cout << ans << '\n';

    return;
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;

    // I got these by running another code locally, on my PC
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

    while (t--) solve(primes);

    return 0;
}
