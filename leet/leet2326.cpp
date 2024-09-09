// ACCEPTED!

class Solution {
public:
    bool check(int i, int j, int* down, int* right, int* left, int* up)
    {
        if(j >= *right)
        {
            (*up)++;
            return false;
        }

        if(i >= *down)
        {
            (*right)--;
            return false;
        }

        if(j < *left)
        {
            (*down)--;
            return false;
        }

        if(i < *up)
        {
            (*left)++;
            return false;
        }

        return true;
    }

    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head)
    {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int step[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        int x = 0, y = 0, left = 0, up = 0;
        int dir = 0;
        while(head != NULL)
        {
            cout << x << " " << y << endl;

            matrix[x][y] = head->val;
            head = head->next;

            int nextX = x + step[dir][0];
            int nextY = y + step[dir][1];
            if(check(nextX, nextY, &m, &n, &left, &up))
            {
                x = nextX;
                y = nextY;
            }
            else
            {
                dir = (dir + 1) % 4;
                x = x + step[dir][0];
                y = y + step[dir][1];
            }
        }

        return matrix;
    }
};
