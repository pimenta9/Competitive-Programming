// Accepted!

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, x;
    cin >> n >> x;

    int h[n];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    
    int s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    vector<vector<int>> dp(n+1, vector<int>(x+1, -1));
    dp[0][x] = 0;
    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (dp[i][j] == -1)
                continue;

            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            answer = max(answer, dp[i+1][j]);

            int k = j - h[i];
            if (k < 0)
                continue;

            dp[i+1][k] = max(dp[i+1][k], dp[i][j] + s[i]);
            answer = max(answer, dp[i+1][k]);
        }
    }

    cout << answer << endl;

    return 0;
}
