/ ACCEPTED!

class Solution {
public:
    bool checkIfExist(vector<int>& arr)
    {
        map<int, bool> m;

        for(int i : arr)
        {
            if(i % 2 == 0)
            {
                if(m[i/2] || m[i*2])
                    return true;
            }
            else
            {
                if(m[i*2])
                    return true;
            }

            m[i] = true;
        }

        return false;
    }
};
