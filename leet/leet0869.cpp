// ACCEPTED!

class Solution {
public:
    vector<int> digits (int n)
    {
        vector<int> ans(10, 0);

        while (n > 0)
        {
            ans[n%10]++;
            n /= 10;
        }

        return ans;
    }

    bool reorderedPowerOf2(int n)
    {
        map<vector<int>, bool> powers;

        for (int i = 1; i <= 1000000000; i = i << 1)
        {
            powers[digits(i)] = true;
        }

        return powers[digits(n)];
    }
};
