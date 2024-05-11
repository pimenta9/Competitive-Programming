#include <bits/stdc++.h>
using namespace std;

int n, m, number_of_zeroes;
vector<list<int > > edges;
vector<int > teams;

void inputRead()
{
    cin >> n >> m;

    edges.resize(n);
    teams.resize(n, 0);
    number_of_zeroes = n;

    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        from--; to--;

        edges[from].push_back(to);
        edges[to].push_back(from);
    }
}

int findZero()
{
    for (int i = 0; i < n; i++)
    {
        if (teams[i] == 0)
        {
            return i;
        }
    }

    return -1;
}

int main ()
{
    inputRead();

    while (number_of_zeroes > 0)
    {

        int source = findZero();

        queue<int > q;
        teams[source] = 1;
        number_of_zeroes--;
        q.push(source);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();

            list<int >::iterator it;
            for (it = edges[v].begin(); it != edges[v].end(); it++)
            {
                if (teams[*it] == 0)
                {
                    if (teams[v] == 1)
                    {
                        teams[*it] = 2;
                    }
                    else
                    {
                        teams[*it] = 1;
                    }
                    q.push(*it);
                    number_of_zeroes--;
                }
                else
                    if (teams[*it] == teams[v])
                    {
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
            }
        }

    }

    for (int i = 0; i < n; i++)
    {
        cout << teams[i] << " ";
    } cout << endl;

    return 0;
}
