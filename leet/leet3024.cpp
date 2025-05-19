// ACCEPTED!

class Solution {
public:
    string triangleType(vector<int>& nums)
    {
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];

        if (a >= b+c or b >= a+c or c >= b+a)
            return "none";

        if (a == b and b == c)
            return "equilateral";

        if (a == b or a == c or b == c)
            return "isosceles";

        return "scalene";
    }
};
