// ACCEPTED!

int numTeams(vector<int>& rating)
{
    int answer = 0;

    int n = rating.size();

    bool increasing;

    for (int i = 0; i < (n - 2); i++)
    {
        for (int j = (i + 1); j < (n - 1); j++)
        {
            if (rating[j] > rating[i]) increasing = true;
            else increasing = false;

            for (int k = (j + 1); k < n; k++)
            {
                if (rating[k] > rating[j] && increasing) answer++;

                if (rating[k] < rating[j] && !increasing) answer++;
            }
        }
    }

    return answer;
}
