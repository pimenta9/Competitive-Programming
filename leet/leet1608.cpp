// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

vector<int > nums = {0, 0};

int specialArray(vector<int>& nums)
{
    int n = nums.size();

    sort ( nums.begin(), nums.end() );

    int index = 0;

    for (int testing = 0; testing <= n; testing++)
    {
        while (nums[index] < testing)
        {
            index++;

            if (index >= n)
            {
                return -1;
            }
        }

        if ((n - index) == testing)
        {
            return testing;
        }
    }

    return -1;
}

int main ()
{
    cout << specialArray(nums) << endl;

    return 0;
}