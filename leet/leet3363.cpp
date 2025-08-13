// ACCEPTED!

class Solution {
public:
    int n;
    vector<vector<bool>> calculated;
    vector<vector<int>> dp;

    int calc1 (int i, int j, vector<vector<int>>& fruits)
    {
        if (i >= n or j >= i)
            return 0;

        if (calculated[i][j])
            return dp[i][j];

        int op1 = calc1(i, j+1, fruits);
        int op2 = calc1(i-1, j+1, fruits);
        int op3 = calc1(i+1, j+1, fruits);

        dp[i][j] = fruits[i][j] + max(op1, max(op2, op3));
        calculated[i][j] = true;
        return dp[i][j];
    }

    int calc2 (int i, int j, vector<vector<int>>& fruits)
    {
        if (j >= n or i >= j)
            return 0;

        if (calculated[i][j])
            return dp[i][j];

        int op1 = calc2(i+1, j, fruits);
        int op2 = calc2(i+1, j+1, fruits);
        int op3 = calc2(i+1, j-1, fruits);

        dp[i][j] = fruits[i][j] + max(op1, max(op2, op3));
        calculated[i][j] = true;
        return dp[i][j];
    }

    int maxCollectedFruits(vector<vector<int>>& fruits)
    {
        n = fruits.size();

        dp.resize(n, vector<int>(n, 0));
        calculated.resize(n, vector<bool>(n, false));

        int answer = 0;

        for (int i = 0; i < n; i++)
        {
            answer += fruits[i][i];
        }

        dp[n-1][n-2] = fruits[n-1][n-2];
        calculated[n-1][n-2] = true;
        answer += calc1(n-1, 0, fruits);

        dp[n-2][n-1] = fruits[n-2][n-1];
        calculated[n-2][n-1] = true;
        answer += calc2(0, n-1, fruits);

        return answer;
    }
};
