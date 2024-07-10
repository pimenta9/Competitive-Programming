// ACCEPTED!

class Solution {
public:
    int minOperations(vector<string>& logs)
    {
        int n = logs.size();

        int distance = 0;

        for (int i = 0; i < n; i++)
        {
            if (logs[i] == "../")
            {
                if (distance > 0)
                    distance--;
            }
            else if (logs[i] != "./")
            {
                distance++;
            }
        }

        return distance;
    }
};
