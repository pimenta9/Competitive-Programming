// ACCEPTED!

class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
        vector<bool> a(101, false);

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < k)
                return -1;

            a[nums[i]] = true;
        }

        int answer = 0;
        for (int i = 100; i >= 1; i--)
        {
            if (i == k)
                return answer;

            if (a[i]) answer++;
        }

        return answer;
    }
};
