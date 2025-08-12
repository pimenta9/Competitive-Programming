// ACCEPTED!

class Solution {
public:
    string findValidPair(string s)
    {
        map<char, int> freq;

        for (char c : s)
            freq[c]++;

        string answer = "";
        for (int i = 0; i < s.size()-1; i++)
        {
            if (s[i] != s[i+1] and freq[s[i]] == (s[i] - '0') and freq[s[i+1]] == (s[i+1] - '0'))
            {
                answer.push_back(s[i]);
                answer.push_back(s[i+1]);
                return answer;
            }
        }

        return answer;
    }
};
