// ACCEPTED!

class Solution {
public:
    int numberLength(int num)
    {
        int length = 0;

        while(num != 0)
        {
            length++;

            num /= 10;
        }

        return length;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2)
    {
        map<int, bool> prefix;

        for(int x : arr1)
        {
            while(x != 0 && prefix[x] == false)
            {
                cout << x << endl;

                prefix[x] = true;

                x /= 10;
            }
        }

        int max = 0;

        for(int y : arr2)
        {
            while(y != 0)
            {
                if(prefix[y] == true)
                {
                    int length = numberLength(y);

                    if (length > max)
                        max = length;
                }

                y /= 10;
            }
        }

        return max;
    }
};
