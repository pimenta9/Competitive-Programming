// ACCEPTED!

class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        int max = 0, longestSubarray = 0;

        int i, j;
        for(i = 0; i < nums.size(); i = j)
        {
            if(nums[i] >= max)
            {
                for(j = i; j < nums.size() && nums[j] == nums[i]; j++)
                    ;

                if(j - i > longestSubarray || nums[i] > max)
                    longestSubarray = j - i;

                max = nums[i];
            }
            else
                j++;
        }

        return longestSubarray;
    }
};
