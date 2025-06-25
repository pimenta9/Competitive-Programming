// Accepted!

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct SegTree
{
    int n;
    vector<int> tree;

    SegTree (int sz)
    {
        n = sz;
        tree.resize(4*n, 0);
    }

    void update (int ul, int ur, int x)
    {
        update_range(ul, ur, x, 0, n-1, 1);
    }

    void update_range (int ul, int ur, int x, int l, int r, int nd)
    {
        if (l >= ul and r <= ur)
        {
            tree[nd] += x;
            return;
        }

        if (l > ur or r < ul)
        {
            return;
        }

        int mid = (l + r)/2;
        update_range(ul, ur, x, l, mid, 2*nd);
        update_range(ul, ur, x, mid+1, r, 2*nd+1);
    }

    int query (int i)
    {
        return query_point (i, 0, n-1, 1);
    }

    int query_point (int i, int l, int r, int nd)
    {
        if (l == r)
        {
            return tree[nd];
        }

        int mid = (l + r)/2;

        if (i <= mid)
            return tree[nd] + query_point(i, l, mid, 2*nd);
        
        return tree[nd] + query_point(i, mid+1, r, 2*nd+1);
    }
};

signed main ()
{
    int n, q;
    cin >> n >> q;

    SegTree st(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        st.update(i, i, x);
    }

    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int a, b, u;
            cin >> a >> b >> u;

            st.update(a-1, b-1, u);
        }

        if (op == 2)
        {
            int k;
            cin >> k;

            cout << st.query(k-1) << endl;
        }
    }

    return 0ll;
}
