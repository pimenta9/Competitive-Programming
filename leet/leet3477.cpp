// ACCEPTED!

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets)
    {
        int answer = 0;
        for (int num_fruit : fruits)
        {
            bool added = false;
            for (int i = 0; i < baskets.size(); i++)
            {
                if (num_fruit <= baskets[i])
                {
                    baskets[i] = 0;
                    added = true;
                    break;
                }
            }
            if (!added)
                answer++;
        }

        return answer;
    }
};
