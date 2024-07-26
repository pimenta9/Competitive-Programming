// ACCEPTED!

vector<vector<int>> buildGraph(int n, vector<vector<int>> edges)
    {
        vector<vector<int>> G;

        G.resize(n);
        for (int i = 0; i < n; i++)
        {
            G[i].resize(n, 0);
        }

        for (int i = 0; i < edges.size(); i++)
        {
            int from = edges[i][0];
            int to = edges[i][1];
            int weight = edges[i][2];

            G[from][to] = weight;
            G[to][from] = weight;
        }

        return G;
    }

    int dijkstra(int source, int n, vector<vector<int>> graph, int distanceThreshold)
    {
        vector<int> d;
        d.resize(n, -1);
        d[source] = 0;

        queue<int> q;
        q.push(source);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (int i = 0; i < n; i++)
            {
                int weight = graph[current][i];
                if (weight != 0)
                {
                    if (d[i] == -1)
                    {
                        q.push(i);
                    }

                    int distance = d[current] + weight;

                    if (distance < d[i] || d[i] == -1)
                    {
                        d[i] = distance;
                        q.push(i);
                    }
                }
            }
        }

        int answer = -1;
        for (int i = 0; i < n; i++)
        {
            if (d[i] <= distanceThreshold)
                answer++;
        }

        return answer;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        vector<vector<int>> G = buildGraph(n, edges);

        int min = 100, answer;

        for (int i = 0; i < n; i++)
        {
            int current = dijkstra(i, n, G, distanceThreshold);

            if (current <= min)
            {
                min = current;
                answer = i;
            }
        }

        return answer;
    }
