// ACCEPTED!

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
    {
        int arrSize = arr.size();

        vector<int> prefixXOR (arrSize + 1);
        prefixXOR[0] = 0;

        for(int i = 1; i <= arrSize; i++)
            prefixXOR[i] = arr[i - 1] ^ prefixXOR[i - 1];

        vector<int> answer;

        for(vector<int> query : queries)
        {
            int left = query[0];
            int right = query[1] + 1;

            answer.push_back(prefixXOR[right] ^ prefixXOR[left]);
        }

        return answer;
    }
};
