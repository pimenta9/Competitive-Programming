#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

struct SegTree
{
    int n;
    vector<ull> tree;

    SegTree (int size)
    {
        n = size;
        tree.resize(4*size, 0);
    }

    void update_point (ull x, int i, int l, int r, int node)
    {
        if (l == r)
        {
            tree[node] = x;
            return;
        }

        int mid = (l + r)/2;
        
        if (i <= mid)
            update_point(x, i, l, mid, 2*node);
        else
            update_point(x, i, mid+1, r, 2*node+1);

        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void update (ull x, int i)
    {
        update_point (x, i, 0, n-1, 1);
    }

    ull query_range(int ql, int qr, int l, int r, int node)
    {
        if (r < ql or l > qr)
            return 0;

        if (l >= ql and r <= qr)
            return tree[node];

        int mid = (l + r)/2;
        ull left = query_range(ql, qr, l, mid, 2*node);
        ull right = query_range(ql, qr, mid+1, r, 2*node+1);

        return left + right;
    }

    ull query (int ql, int qr)
    {
        return query_range(ql, qr, 0, n-1, 1);
    }
};

int main ()
{
    int n, q;
    cin >> n >> q;

    SegTree st(n);

    for (int i = 0; i < n; i++)
    {
        ull x;
        cin >> x;

        st.update(x, i);
    }

    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int k;
            cin >> k;
            ull u;
            cin >> u;

            st.update(u, k-1);
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
