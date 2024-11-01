// ACCEPTED!

class Solution {
public:
    string makeFancyString(string s)
    {
        string answer;
        answer.push_back(s[0]);
        int n = 1;
        for (int i = 1; s[i] != '\0'; i++)
        {
            if (s[i] != s[i-1])
                n = 0;

            if (n < 2)
                answer.push_back(s[i]);

            n++;
        }

        return answer;
    }
};
