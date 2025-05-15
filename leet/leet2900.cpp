// ACCEPTED!

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups)
    {
        vector<int> zero_first;
        int next = 0;
        for (int i = 0; i < groups.size(); i++)
        {
            if (groups[i] == next)
            {
                zero_first.push_back(i);
                next = (next + 1) % 2;
            }
        }

        vector<int> one_first;
        next = 1;
        for (int i = 0; i < groups.size(); i++)
        {
            if (groups[i] == next)
            {
                one_first.push_back(i);
                next = (next + 1) % 2;
            }
        }

        vector<string> answer;
        if (zero_first.size() > one_first.size())
        {
            for (int i = 0; i < zero_first.size(); i++)
                answer.push_back(words[zero_first[i]]);
        }
        else
        {
            
            for (int i = 0; i < one_first.size(); i++)
                answer.push_back(words[one_first[i]]);
        }

        return answer;
    }
};
