// ACCEPTED

class Solution {
public:
    vector<int> sortArray(vector<int>& nums)
    {
        int rangeMax = 2*50000 + 1;
        vector<int> freq(rangeMax + 1, 0);

        for (int i = 0; i < nums.size(); i++)
            freq[nums[i] + rangeMax/2]++;

        for(int i = 0, j = 0; i <= rangeMax; i++)
        {
            while (freq[i]--)
            {
                nums[j] = i - rangeMax/2;
                j++;
            }
        }

        return nums;
    }
};
