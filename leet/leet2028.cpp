class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n)
    {
        int sum = 0;
        for(int x : rolls)
            sum += x;

        int m = rolls.size();

        int target = (n + m)*mean - sum;

        if(target < n || target > 6*n)
            return {};

        vector<int> missingObservations;

        for(int i = 0, j = n; i < n; i++, j--)
        {
            missingObservations.push_back(target/(j));

            target -= missingObservations[i];
        }

        return missingObservations;
    }
};
