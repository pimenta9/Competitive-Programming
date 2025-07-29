// ACCEPTED!

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums)
    {
        int currentPositive = nums[0];
        int currentNegative = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (currentPositive < 0)
                currentPositive = 0;

            currentPositive += nums[i];

            maxSum = currentPositive > maxSum? currentPositive : maxSum;

            if (currentNegative > 0)
                currentNegative = 0;

            currentNegative += nums[i];

            minSum = currentNegative < minSum? currentNegative : minSum;
        }

        maxSum = maxSum < 0? -maxSum : maxSum;
        minSum = minSum < 0? -minSum : minSum;

        int answer = maxSum > minSum? maxSum : minSum;

        return answer;
    }
};
