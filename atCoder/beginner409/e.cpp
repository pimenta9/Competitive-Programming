#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

#define max_n 100000

vector<pii> edges[max_n + 1];
long long charge[max_n + 1];
bool visited[max_n + 1];

long long min_energy(int u)
{
    visited[u] = true;
    long long answer = 0;

    for (auto [v, w] : edges[u])
    {
        if (visited[v])
            continue;

        long long minEnergy = min_energy(v);
        answer += minEnergy + abs(charge[v])*w;
        charge[u] += charge[v];
    }
    return answer;
}

int main ()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> charge[i];
    }

    for (int i = 1; i <= n-1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    cout << min_energy(1) << endl;

    return 0;
}
