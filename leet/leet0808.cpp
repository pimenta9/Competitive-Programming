// ACCEPTED!

class Solution {
public:
    map<pair<int, int>, double> dp;
    map<pair<int, int>, bool> calculated;

    double calculateDP (int i, int j)
    {
        if (i == 0 and j == 0)
            return 0.5;

        if (i == 0)
            return 1;

        if (j == 0)
            return 0;

        if (calculated[{i, j}])
            return dp[{i, j}];

        int x = max(0, i-4);
        int y = j;
        dp[{x, y}] = calculateDP(x, y);
        double op1 = 0.25 * dp[{x, y}];

        x = max(0, i-3);
        y = max(0, j-1);
        dp[{x, y}] = calculateDP(x, y);
        double op2 = 0.25 * dp[{x, y}];

        x = max(0, i-2);
        y = max(0, j-2);
        dp[{x, y}] = calculateDP(x, y);
        double op3 = 0.25 * dp[{x, y}];

        x = max(0, i-1);
        y = max(0, j-3);
        dp[{x, y}] = calculateDP(x, y);
        double op4 = 0.25 * dp[{x, y}];

        calculated[{i, j}] = true;
        return op1 + op2 + op3 + op4;
    }

    double soupServings(int n)
    {
        int m = n/25 + (n%25? 1 : 0);

        for (int i = 0; i <= m; i++)
        {
            dp[{i, i}] = calculateDP(i, i);

            if (dp[{i, i}] > 1 - 1e-5)
                return 1;
        }

        return dp[{m, m}];
    }
};
