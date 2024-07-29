// ACCEPTED!!

vector<vector<int>> build_graph(int n, vector<vector<int>> edges)
{
    vector<vector<int>> G(n);

    for (vector<int> edge : edges)
    {
        int from = edge[0] - 1;
        int to = edge[1] - 1;

        G[from].push_back(to);
        G[to].push_back(from);
    }

    return G;
}

int secondMinimum(int n, vector<vector<int>>& edges, int time, int change)
{
    vector<vector<int>> G = build_graph(n, edges);

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    vector<int> dist1(n, -1);
    vector<int> dist2(n, -1);

    while (!q.empty())
    {
        int v = q.front().first;
        int timeElapsed = q.front().second;
        q.pop();

        int traffic = timeElapsed/change;
        int wait = (traffic % 2 == 0)? 0 : (change*(traffic + 1) - timeElapsed);
        int nextTimeElapsed = timeElapsed + time + wait;

        for (int u : G[v])
        {
            if (dist1[u] == -1)
            {
                dist1[u] = nextTimeElapsed;
                q.push(make_pair(u, nextTimeElapsed));
            }
            else if (dist2[u] == -1 && nextTimeElapsed > dist1[u])
            {
                if (u == (n - 1)) return nextTimeElapsed;

                dist2[u] = nextTimeElapsed;
                q.push(make_pair(u, nextTimeElapsed));
            }
        }
    }

    return -1;
}
