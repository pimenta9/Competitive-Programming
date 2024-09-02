// ACCEPTED

vector<int> twoSum(vector<int>& nums, int target)
{
    map<int, int> m;

    for(int i = 0; i < nums.size(); i++)
    {
        int indexSum = m[target - nums[i]];
        if(indexSum != 0)
        {
            return {indexSum - 1, i};
        }

        m[nums[i]] = i + 1;
    }

    return {};
}
