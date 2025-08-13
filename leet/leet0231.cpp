// ACCEPTED!

class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;

        while (n > 1)
        {
            if (n & 1)
                return false;

            n = n >> 1;
        }

        return true;
    }
};

// Other solution:
// cool trick using bits

class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;

        return !(n & (n-1));
    }
};
