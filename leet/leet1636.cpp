// ACCEPTED!

vector<int> frequencySort(vector<int>& nums)
{
    map<int, int> m;

    int n = nums.size(), number_of_values = 0;

    for (int i = 0; i < n; i++)
    {
        if (m[nums[i]] == 0) number_of_values++;

        m[nums[i]]++;
    }

    priority_queue<pair<int, int>> q;

    for (int i = 0; i < number_of_values; i++)
    {
        int x = -(m.begin()->second);
        int y = m.begin()->first;

        m.erase(y);

        q.push(make_pair(x, y));
    }

    vector<int> answer;

    while(!q.empty())
    {
        int frequency = -(q.top().first);
        int value = q.top().second;

        q.pop();

        for (int i = 0; i < frequency; i++)
        {
            answer.push_back(value);
        }
    }

    return answer;
}
