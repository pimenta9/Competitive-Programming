#include <bits/stdc++.h>
using namespace std;

struct disjointSets
{
    vector<int> parent;

    disjointSets(int n)
    {
        parent.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find (int u)
    {
        if (u != parent[u])
        {
            parent[u] = find(parent[u]);
        }

        return parent[u];
    }

    void merge (int x, int y)
    {
        x = find(x);
        y = find(y);

        parent[y] = x;
    }
};

int main ()
{
    int n;
    cin >> n;

    disjointSets ds(n);

    for (int i = 0; i < n; i++)
    {
        cout << (ds.parent[i] + 1) << " ";
    }cout << endl;

    return 0;
}