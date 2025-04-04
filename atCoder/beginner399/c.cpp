#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    vector<int> visited(n, 0);

    int answer = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] != 0) continue;

        queue<int> q;
        q.push(i);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            visited[u] = 2;

            for (int v : g[u])
            {
                if (visited[v] == 0)
                {
                    q.push(v);
                    visited[v] = 1;
                }
                else if (visited[v] == 1)
                {
                    answer++;
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}
