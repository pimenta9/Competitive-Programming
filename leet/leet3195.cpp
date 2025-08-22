// ACCEPTED!

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid)
    {
        int min_i = 1000;
        int max_i = 0;
        int min_j = 1000;
        int max_j = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    min_i = min(min_i, i);
                    max_i = max(max_i, i);
                    min_j = min(min_j, j);
                    max_j = max(max_j, j);
                }
            }
        }

        return (max_i - min_i + 1) * (max_j - min_j + 1);
    }
};
