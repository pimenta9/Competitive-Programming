// ACCEPTED!

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries)
    {
        vector<long long> powers;
        for (long long i = 1; n > 0; i*= 2, n /= 2)
        {
            if (n & 1)
                powers.push_back(i);
        }

        for (int x : powers)
            cout << x << ' ';
        cout << '\n';

        vector<int> answer;
        for (auto q : queries)
        {
            int ans = 1;
            for (int i = q[0]; i <= q[1]; i++)
                ans = (ans * powers[i])%1000000007;
            
            answer.push_back(ans);
        }

        return answer;
    }
};
