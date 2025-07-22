// ACCEPTED!

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> greater(10001);

        stack<int> s;

        for (int i = nums2.size()-1; i >= 0; i--)
        {
            int x = nums2[i];

            while (!s.empty() and s.top()<x)
                s.pop();

            greater[x] = s.empty()? -1 : s.top();

            s.push(x);
        }

        vector<int> answer;
        for (int y : nums1)
        {
            answer.push_back(greater[y]);
        }

        return answer;
    }
};
