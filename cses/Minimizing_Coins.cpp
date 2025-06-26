// Accepted!

#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
#define MAX 1000000

int main ()
{
    int n, x;
    cin >> n >> x;

    int coins[n];
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<int> dp(x + MAX, inf);
    dp[0] = 0;
    for (int i = 0; i < x; i++)
    {
        if (dp[i] == inf)
            continue;

        for (int c : coins)
        {
            dp[i+c] = min(dp[i+c], dp[i]+1);
        }
    }

    if (dp[x] == inf)
        dp[x] = -1;

    cout << dp[x] << endl;

    return 0;
}
