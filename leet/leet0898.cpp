// ACCEPTED!

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr)
    {
        map<int, bool> ans;
        ans[arr[0]] = true;
        map<int, bool> cur;
        cur[arr[0]] = true;
        for (int i = 1; i < arr.size(); i++)
        {
            map<int, bool> next;
            next[arr[i]] = true;
            for (auto [k, v] : cur)
                next[k | arr[i]] = true;

            for (auto [k, v] : next)
                ans[k] = true;

            for (auto [k, v] : cur)
            {
                cur.erase(k);
            }

            for (auto [k, v] : next)
            {
                cur[k] = true;
            }
        }

        return ans.size();
    }
};
