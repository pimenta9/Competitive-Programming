// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

struct disjointSets
{
    vector<int> parent;

    disjointSets(int n)
    {
        parent.resize(n+1, -1);
    }

    int find (int a)
    {
        if (parent[a] < 0)
            return a;

        parent[a] = find(parent[a]);
        return parent[a];
    }

    bool unite (int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (-parent[b] > -parent[a])
            swap(a, b);

        parent[a] += parent[b];
        parent[b] = a;
        return true;
    }
};

int main ()
{
    int n, m;
    cin >> n >> m;

    disjointSets ds(n);
    int components = n, largest_size = 1;

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        if (ds.unite(a, b))
            components--;

        largest_size = max(largest_size, -(ds.parent[ds.find(a)]));
        cout << components << ' ';
        cout << largest_size << endl;
    }

    return 0;
}
