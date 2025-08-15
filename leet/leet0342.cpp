// ACCEPTED!

class Solution {
public:
    bool isPowerOfFour(int n)
    {
        if (n == 0)
            return false;

        if (n & 0xAAAAAAAA)
            return false;

        return !(n & n-1);
    }
};
