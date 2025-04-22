#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> k(m);
    for (int i = 0; i < m; i++)
    {
        int k_i;
        cin >> k_i;
        k[i].resize(k_i);
        for (int j = 0; j < k_i; j++)
            cin >> k[i][j];
    }
    vector<int> day(n+1);
    for (int i = 1; i <=n ; i++)
    {
        int aux;
        cin >> aux;
        day[aux] = i;
    }

    vector<int> answer(n+1, 0);

    for (int i = 0; i < m; i++)
    {
        int max = 0;
        for (int j = 0; j < k[i].size(); j++)
        {
            if (day[k[i][j]] > max)
                max = day[k[i][j]];
        }
        answer[max]++;
    }

    for (int i = 1; i <= n; i++)
        answer[i] += answer[i-1];

    for (int i = 1; i <= n; i++)
        cout << answer[i] << endl;

    return 0;
}
