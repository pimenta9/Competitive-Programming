// ACCEPTED!

class Solution {
public:
    int absoluteValue(int n)
    {
        if(n < 0)
            return -n;

        return n;
    }
    int scoreOfString(string s)
    {
        int score = 0;

        for(int i = 1; s[i] != '\0'; i++)
            score += absoluteValue(s[i]-s[i-1]);

        return score;
    }
};
