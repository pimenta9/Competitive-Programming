#include <bits/stdc++.h>
using namespace std;

int n, m;
vector< list< int > > graph;
vector< int > parent;
vector< int > dist;

void inputRead ()
{
    cin >> n >> m;

    graph.resize(n);
    parent.resize(n, -2);
    dist.resize(n, -1);
    dist[0] = 0;

    for (int i = 0; i < m; i++)
    {
        int from, to;

        cin >> from >> to;

        graph[from - 1].push_back(to - 1);
        graph[to - 1].push_back(from - 1);
    }
}

void bfs ()
{
    queue< int > q;

    q.push(0);
    parent[0] = -1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        list< int >::iterator it;
        for (it = graph[v].begin(); it != graph[v].end(); it++)
        {
            if (parent[*it] == -2)
            {
                parent[*it] = v;
                dist[*it] = dist[v] + 1;
                q.push(*it);
            }
        }
    }
}

int main ()
{
    inputRead();

    /*
    for (int i = 0; i < n; i++)
    {
        printf("[%d] : ", (i+1));

        for (list<int>::iterator it = graph[i].begin(); it != graph[i].end(); it++)
        {
            cout << (*it) + 1 << " --> ";
        }
        cout << "//\n";
    }
    */

   bfs();

    if (dist[n-1] == -1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int answer = dist[n-1];
    cout << (answer + 1) << endl;

    vector< int > path;
    for (int i = (n - 1); i >= 0; i = parent[i])
    {
        path.push_back(i);
    }

    for (int i = answer; i >= 0; i--)
    {
        cout << path[i] + 1 << " ";
    } cout << endl;

    return 0;
}
