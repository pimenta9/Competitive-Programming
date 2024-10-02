// ACCEPTED!

class Solution {
public:
    int memo[46];

    int climbStairs(int n)
    {
        if (n <= 1) return 1;

        if (memo[n] != 0)
            return memo[n];

        memo[n] = climbStairs(n - 1) + climbStairs(n - 2);

        return memo[n];
    }
};
