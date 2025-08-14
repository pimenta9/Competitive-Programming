// ACCEPTED!

class Solution {
public:
    string largestGoodInteger(string num)
    {
        string answer = "";

        for (int i = 0; i < num.size()-2; i++)
        {
            if (num[i] == num[i+1] and num[i] == num[i+2])
            {
                if (answer.size() == 0 or num[i] > answer[0])
                {
                    answer.clear();
                    answer.push_back(num[i]);
                    answer.push_back(num[i]);
                    answer.push_back(num[i]);
                }
            }
        }

        return answer;
    }
};
