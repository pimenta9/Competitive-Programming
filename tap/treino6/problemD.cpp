// CSES 1143

#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int tree[4*N];
int a[N], b[N];

void build (int p, int l, int r)
{
    if (l == r)
    {
        tree[p] = a[l];
        return;
    }

    int mid = (l + r)/2;
    build (2*p, l, mid);
    build (2*p + 1, mid + 1, r);

    tree[p] = max(tree[2*p], tree[2*p + 1]);
}

void update (int p, int l, int r, int val, int pos)
{
    if (l == r)
    {
        tree[p] = val;
        a[l] = val;
        return;
    }

    int mid = (l + r)/2;
    if (pos <= mid)
        update(2*p, l, mid, val, pos);
    else
        update(2*p + 1, mid+1, r, val, pos);

    tree[p] = max(tree[2*p], tree[2*p + 1]);
}

int query (int p, int l, int r, int val)
{
    if (tree[p] < val) return 0;

    if (l == r) return l;

    int mid = (l + r)/2;
    int left = query (2*p, l, mid, val);

    if (left != 0)
    {
        return left;
    }
    else
    {
        return query(2*p + 1, mid + 1, r, val);
    }

    return -1; // error;
}

int main ()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }

    build(1, 1, n);

    for (int i = 1; i <= m; i++)
    {
        int x = query(1, 1, n, b[i]);
        cout << x << " ";

        if (x)
            update(1, 1, n, (a[x] - b[i]), x);

        // for (int i = 1; i <= 15; i++)
        // {
        //     if (i == 2 || i == 4 || i == 8)
        //         cout << endl;

        //     cout << tree[i] << " ";
        // } cout << endl;
    }
    cout << endl;

    return 0;
}
