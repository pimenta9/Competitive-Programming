// ACCEPTED!

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums)
    {
        long long sum = 0;
        long long ans = 0;
        for (int num : nums)
        {
            if (num == 0)
                sum++;
            else
                sum = 0;

            ans += sum;
        }

        return ans;
    }
};
