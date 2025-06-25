#include <bits/stdc++.h>
using namespace std;

struct SegTree
{
    int n;
    vector<int> tree;

    SegTree (int size)
    {
        n = size;
        tree.resize(4*n, 0);
    }

    void update (int i, int x)
    {
        update_point(i, x, 0, n-1, 1);
    }

    void update_point (int i, int x, int l, int r, int nd)
    {
        if (l == r)
        {
            tree[nd] = x;
            return;
        }

        int mid = (l + r)/2;

        if (i <= mid)
            update_point(i, x, l, mid, 2*nd);
        else
            update_point(i, x, mid+1, r, 2*nd+1);

        tree[nd] = max(tree[2*nd], tree[2*nd+1]);
    }

    int query (int x)
    {
        if (tree[1] < x)
            return -1;

        return query_point(x, 0, n-1, 1);
    }

    int query_point (int x, int l, int r, int nd)
    {
        if (l == r)
        {
            update(l, tree[nd]-x);
            return l;
        }

        int mid = (l + r)/2;

        if (tree[2*nd] >= x)
            return query_point(x, l, mid, 2*nd);
        
        return query_point(x, mid+1, r, 2*nd+1);
    }
};

int main ()
{
    int n, m;
    cin >> n >> m;

    SegTree st(n);

    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;

        st.update(i, h);
    }

    while (m--)
    {
        int r;
        cin >> r;

        cout << st.query(r) + 1 << " ";
    }
    cout << endl;

    return 0;
}
