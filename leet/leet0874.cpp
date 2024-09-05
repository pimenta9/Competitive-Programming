// ACCEPTED!

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        map<vector<int>, bool> isObstacle;
        for(vector<int> obstacle : obstacles)
            isObstacle[obstacle] = true;

        vector<vector<int>> dir = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        int direction = 0, x = 0, y = 0, furthest = 0;
        for(int command : commands)
        {
            if(command == -1)
            {
                direction = (direction + 1) % 4;
                continue;
            }
            if(command == -2)
            {
                direction = ((direction - 1) + 4) % 4;
                continue;
            }

            for(int i = 0; i < command; i++)
            {
                int distance = x*x + y*y;
                if(distance > furthest)
                    furthest = distance;

                int nextX = x + dir[direction][0];
                int nextY = y + dir[direction][1];

                if(isObstacle[{nextX, nextY}])
                    break;

                x = nextX;
                y = nextY;
            }
            int distance = x*x + y*y;
            if(distance > furthest)
                furthest = distance;
        }

        return furthest;
    }
};
