// ACCEPTED!

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (currentSum < 0)
                currentSum = 0;

            currentSum += nums[i];

            maxSum = maxSum > currentSum? maxSum : currentSum;
        }

        return maxSum;
    }
};
