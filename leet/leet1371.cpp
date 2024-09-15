// ACCEPTED, but I had to use the editorial for this one

class Solution {
public:
    int maxValue(int x, int y)
    {
        if(x > y)
            return x;

        return y;
    }

    int findTheLongestSubstring(string s)
    {
        int prefixXOR = 0;

        vector<int> characterMap(26, 0);
        characterMap['a' - 'a'] = 1;
        characterMap['e' - 'a'] = 2;
        characterMap['i' - 'a'] = 4;
        characterMap['o' - 'a'] = 8;
        characterMap['u' - 'a'] = 16;

        vector<int> mp(32, -1);

        int longestSubstring = 0;

        for(int i = 0; s[i] != '\0'; i++)
        {
            prefixXOR = prefixXOR ^ characterMap[s[i] - 'a'];

            if(prefixXOR != 0 && mp[prefixXOR] == -1)
                mp[prefixXOR] = i;

            longestSubstring = max(longestSubstring, i - mp[prefixXOR]);
        }

        return longestSubstring;
    }
};
