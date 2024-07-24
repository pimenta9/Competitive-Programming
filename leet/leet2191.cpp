// ACCEPTED!!

int jumble(int x, vector<int> mapping)
{
    if (x == 0) return mapping[0];

    int answer = 0;

    for (int i = 1; x != 0; i = i*10)
    {
        answer += mapping[x%10] * i;

        x /= 10;
    }

    return answer;
}

vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums)
{
    int n = nums.size();
    vector<pair<int, int>> aux;

    for (int i = 0; i < n; i++)
    {
        aux.push_back(make_pair(jumble(nums[i], mapping), i));
    }

    sort(aux.begin(), aux.end());

    int aux2[n];

    for (int i = 0; i < n; i++)
    {
        aux2[i] = nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        nums[i] = aux2[aux[i].second];
    }

    return nums;
}
