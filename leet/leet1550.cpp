// ACCEPTED!

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr)
    {
        int odds = 0;
        for (int x : arr)
        {
            if (x & 1)
                odds++;
            else
                odds = 0;

            if (odds == 3)
                return true;
        }
        return false;
    }
};
