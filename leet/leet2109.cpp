// ACCEPTED!

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces)
    {
        string answer;

        for (int i = 0, j = 0; s[i] != '\0'; i++)
        {
            if (j < spaces.size() && i == spaces[j])
            {
                answer.push_back(' ');
                j++;
            }

            answer.push_back(s[i]);
        }

        return answer;
    }
};
