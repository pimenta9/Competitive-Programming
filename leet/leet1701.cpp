// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

double averageWaitingTime (vector<vector<int>>& costumers)
{
    int n = costumers.size();

    long sum = 0;

    int time = 1;

    for (int i = 0; i < n; i++)
    {
        if (costumers[i][0] >= time)
        {
            sum += costumers[i][1];

            time = costumers[i][0] + costumers[i][1];
        }
        else
        {
            sum += (time - costumers[i][0]) + costumers[i][1];

            time += costumers[i][1];
        }
    }

    return (double)sum/n;
}

int main ()
{
    vector<vector<int>> costumers = {{5, 2}, {5, 4}, {10, 3}, {20, 1}};

    cout << averageWaitingTime(costumers) << endl;

    return 0;
}
