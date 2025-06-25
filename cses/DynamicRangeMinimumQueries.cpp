#include <bits/stdc++.h>
using namespace std;

struct SegTree
{
    int n;
    vector<int> tree;

    SegTree (int sz)
    {
        n = sz;
        tree.resize(4*n, INT_MAX);
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

        tree[nd] = min(tree[2*nd], tree[2*nd+1]);
    }

    int query (int ql, int qr)
    {
        return query_point(ql, qr, 0, n-1, 1);
    }

    int query_point (int ql, int qr, int l, int r, int nd)
    {
        if (l >= ql and r <= qr)
        {
            return tree[nd];
        }

        if (r < ql or l > qr)
        {
            return INT_MAX;
        }

        int mid = (l + r)/2;
        int left = query_point(ql, qr, l, mid, 2*nd);
        int right = query_point(ql, qr, mid+1, r, 2*nd+1);

        return min(left, right);
    }
};

int main ()
{
    int n, q;
    cin >> n >> q;

    SegTree st(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        st.update(i, x);
    }

    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int k, u;
            cin >> k >> u;

            st.update(k-1, u);
        }

        if (op == 2)
        {
            int a, b;
            cin >> a >> b;

            cout << st.query(a-1, b-1) << endl;
        }
    }

    return 0;
}
