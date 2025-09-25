// Accepted!

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main ()
{
    int n;
    cin >> n;

    vector<int> dp(n+1, 0);
    dp[0] = 1;

    int outcomes[] = {1, 2, 3, 4, 5, 6};
    for (int i = 1; i <= n; i++)
    {
        for (auto o : outcomes)
        {
            int j = i - o;
            if (j < 0)
                continue;

            dp[i] = (dp[i] + dp[j]) % MOD;
        }
    }

    cout << dp[n] << endl;

    return 0;
}
