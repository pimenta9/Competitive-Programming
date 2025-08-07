// ACCEPTED!

class Solution {
public:
    bool isPalindrome(string s)
    {
        string simple;
        for (int i = 0; i < s.size(); i++)
        {
            if ('A' <= s[i] and s[i] <= 'Z')
                simple.push_back(s[i] += ('a' - 'A'));
            else if ('a' <= s[i] and s[i] <= 'z' or '0' <= s[i] and s[i] <= '9')
                simple.push_back(s[i]);
            else
                continue;
        }

        for (int l = 0, r = simple.size()-1; l < r; l++, r--)
            if (simple[l] != simple[r])
                return false;

        return true;
    }
};
