// ACCEPTED!

// same solution as CSES: Increasing Subsequence

class Solution {
public:
    const int oo = 1e9;

    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> v(n+1, oo);
        v[0] = -oo;

        int ans = 0;
        for (int x : nums)
        {
            int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
            v[idx] = x;
            ans = max(ans, idx);
        }

        return ans;
    }
};
