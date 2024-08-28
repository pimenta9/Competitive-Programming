// working on it...

#include <bits/stdc++.h>
using namespace std;

class Island
{
public:
    vector<pair<int, int>> cells;
};

class Solution
{
public:

    bool check(int i, int j, int n, int m)
    {
        return (i >= 0 && i < n) && (j >= 0 && j < m);
    }

    Island buildIsland(vector<vector<int>>& grid, int x, int y)
    {
        Island I;

        queue<pair<int, int>> q;
        q.push(make_pair(x, y));

        while(!q.empty())
        {
            pair<int, int> cell = q.front();
            q.pop();

            x = cell.first;
            y = cell.second;

            grid[x][y] = 0;

            I.cells.push_back(cell);

            int i, j;
            // up:
            i = x-1; j = y;
            if(check(i, j, grid.size(), grid[i].size()))
            {
                if(grid[i][j] == 1)
                {
                    q.push(make_pair(i, j));
                }
            }

            // right:
            i = x; j = y+1;
            if(check(i, j, grid.size(), grid[i].size()))
            {
                if(grid[i][j] == 1)
                {
                    q.push(make_pair(i, j));
                }
            }

            // down:
            i = x+1; j = y;
            if(check(i, j, grid.size(), grid[i].size()))
            {
                if(grid[i][j] == 1)
                {
                    q.push(make_pair(i, j));
                }
            }

            // left:
            i = x; j = y-1;
            if(check(i, j, grid.size(), grid[i].size()))
            {
                if(grid[i][j] == 1)
                {
                    q.push(make_pair(i, j));
                }
            }
        }

        return I;
    }

    vector<Island> findIslands(vector<vector<int>> grid)
    {
        vector<Island> islands;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    Island I = buildIsland(grid, i, j);

                    islands.push_back(I);
                }
            }
        }

        return islands;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        int numSubIslands = 0;

        vector<Island> islands = findIslands(grid2);

        for(Island i : islands)
        {
            if(checkGrid1(i, grid1))
            {
                numSubIslands++;
            }
        }

        return numSubIslands;
    }
};

int main()
{
    vector<vector<int>> grid1 = { 
                                { 1,1,1,0,0 }, 
                                { 0,1,1,1,1 },
                                { 0,0,0,0,0 }, 
                                { 1,0,0,0,0 }, 
                                { 1,1,0,1,1 }
                                };
    vector<vector<int>> grid2 = {
                                { 1,1,1,0,0 }, 
                                { 0,0,1,1,1 }, 
                                { 0,1,0,0,0 }, 
                                { 1,0,1,1,0 }, 
                                { 0,1,0,1,0 }
                                };

    Solution s;
    cout << s.countSubIslands(grid1, grid2) << endl;

    return 0;
}
