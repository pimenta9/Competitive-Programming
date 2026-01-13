#include <bits/stdc++.h>
using namespace std;

#define int long long

int c_n_k[31][31];

void init()
{
    for(int n = 0; n < 31; n++)
    {
        for(int k = 0; k < 31; k++)
        {
            if(k > n)
            {
                c_n_k[n][k] = 0;
                continue;
            }

            if(k == 0)
            {
                c_n_k[n][k] = 1;
                continue;
            }

            c_n_k[n][k] = c_n_k[n-1][k-1] + c_n_k[n-1][k];
        }
    }
}

void solve ()
{
    int n, k;
    cin >> n >> k;

    int ans = 0;
    for(int mask = n >> 1; mask > 0; mask = mask >> 1)
    {
        int N = __builtin_ctz(mask);

        for(int K = 0; K <= N; K++)
        {
            int ways = c_n_k[N][K];

            if(N + K + 1 > k)
                ans += ways;
        }
    }

    if(__builtin_ctz(n) + 1 > k)
        ans++;

    cout << ans << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    init();

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
