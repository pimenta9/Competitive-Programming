#include <bits/stdc++.h>
using namespace std;

#define int long long

#define max_n 500'000

int n;
vector<int> adj[max_n + 1];

void bfs (vector<int>& dist, const int& source)
{
    vector<bool> visited(n+1, false);

    dist[source] = 0;

    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (visited[v]) continue;
            visited[v] = true;

            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}

int32_t main ()
{
    cin >> n;

    for (int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist_aux(n+1);
    bfs(dist_aux, 1);

    int max_dist = -1, a;
    for (int i = 1; i <= n; i++)
    {
        if (max_dist == -1 or dist_aux[i] >= max_dist)
        {
            max_dist = dist_aux[i];
            a = i;
        }
    }

    vector<int> dist_a(n+1);
    bfs(dist_a, a);

    int b;
    max_dist = -1;
    for (int i = 1; i <= n; i++)
    {
        if (max_dist == -1 or dist_a[i] >= max_dist)
        {
            max_dist = dist_a[i];
            b = i;
        }
    }

    vector<int> dist_b(n+1);
    bfs(dist_b, b);

    for (int i = 1; i <= n; i++)
    {
        if (dist_a[i] > dist_b[i])
            cout << a << '\n';
        else if (dist_a[i] == dist_b[i])
            cout << max(a, b) << '\n';
        else
            cout << b << '\n';
    }

    return 0;
}
