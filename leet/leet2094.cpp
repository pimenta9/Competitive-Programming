// ACCEPTED!

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits)
    {
        int n = digits.size();
        vector<int> all_concatenations;
        for (int i = 0; i < n-2; i++)
        {
            for (int j = i+1; j < n-1; j++)
            {
                for (int k = j+1; k < n; k++)
                {
                    all_concatenations.push_back(digits[i]*100+digits[j]*10+digits[k]);
                    all_concatenations.push_back(digits[i]*100+digits[k]*10+digits[j]);
                    all_concatenations.push_back(digits[j]*100+digits[i]*10+digits[k]);
                    all_concatenations.push_back(digits[j]*100+digits[k]*10+digits[i]);
                    all_concatenations.push_back(digits[k]*100+digits[i]*10+digits[j]);
                    all_concatenations.push_back(digits[k]*100+digits[j]*10+digits[i]);
                }
            }
        }
        vector<bool> in_answer(1000, false);
        vector<int> answer;
        for (int x : all_concatenations)
        {
            if (!in_answer[x] and x >= 100 and !(x & 1))
            {
                answer.push_back(x);
                in_answer[x] = true;
            }
        }

        sort(answer.begin(), answer.end());

        return answer;
    }
};
