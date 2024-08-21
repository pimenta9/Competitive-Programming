// ACCEPTED!

int maxStones(int index, int M, vector<int>& suffixSum, vector<vector<int>>& memo)
{
    if ((index + 2*M) >= suffixSum.size())
    {
        return suffixSum[index];
    }

    if(memo[index][M] > 0) return memo[index][M];

    int min = INT_MAX;
    for (int i = 1; i <= 2*M; i++)
    {
        int temp = maxStones(index+i, max(M, i), suffixSum, memo);

        if (temp < min)
        {
            min = temp;
        }
    }

    memo[index][M] = suffixSum[index] - min;
    return memo[index][M];
}

int stoneGameII(vector<int>& piles)
{
    int n = piles.size();

    vector<vector<int>> memo(n, vector<int>(n));

    vector<int> suffixSum(n);

    suffixSum[n-1] = piles[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        suffixSum[i] = piles[i] + suffixSum[i+1];
    }

    return maxStones(0, 1, suffixSum, memo);
}
