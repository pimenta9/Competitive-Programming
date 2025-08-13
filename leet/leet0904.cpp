// ACCEPTED!

class Solution {
public:
    int totalFruit(vector<int>& fruits)
    {
        int n = fruits.size();

        vector<pair<int, int>> fruits2;
        for (int i = 0; i < n; )
        {
            int f = fruits[i];
            int num = 0;
            int j;
            for (j = i; j < n; j++)
            {
                if (fruits[j] != f)
                    break;

                num++;
            }

            fruits2.push_back({f, num});
            i = j;
        }

        int a = fruits2[0].first;
        int b = a;
        n = fruits2.size();
        int cur = 0;
        int ans = 0;
        for (int r = 0; r < n; r++)
        {
            if (fruits2[r].first == a or fruits2[r].first == b)
            {
                cur += fruits2[r].second;
            }
            else
            {
                a = fruits2[r-1].first;
                b = fruits2[r].first;

                cur = fruits2[r-1].second + fruits2[r].second;
            }

            ans = max(ans, cur);
        }

        return ans;
    }
};
