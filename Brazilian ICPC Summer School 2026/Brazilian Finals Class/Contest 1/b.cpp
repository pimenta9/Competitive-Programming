#include <bits/stdc++.h>
using namespace std;

#define int long long

int INF = 30'001;

struct SegTree
{
    int n;
    vector<int> tree, lazy;

    SegTree(int sz)
    {
        n = sz;
        tree.resize(4*n, 0);
        lazy.resize(4*n, 0);
    }

    void push(int nd, int l, int r)
    {
        tree[2*nd] += lazy[nd];
        lazy[2*nd] += lazy[nd];
        //
        tree[2*nd+1] += lazy[nd];
        lazy[2*nd+1] += lazy[nd];
        //
        lazy[nd] = 0;
    }

    void update (int ql, int qr, int x)
    {
        update(ql, qr, x, 0, n-1, 1);
    }

    void update (int ql, int qr, int x, int l, int r, int nd)
    {
        if(l > qr or r < ql)
            return;

        int size = r-l+1;

        if(l >= ql and r <= qr)
        {
            tree[nd] += x;
            lazy[nd] += x;
            return;
        }

        push(nd, l, r);
        int mid = (l+r)/2;
        update(ql, qr, x, l, mid, 2*nd);
        update(ql, qr, x, mid+1, r, 2*nd+1);
        tree[nd] = min(tree[2*nd], tree[2*nd+1]);
    }

    int query (int ql, int qr)
    {
        return query (ql, qr, 0, n-1, 1);
    }

    int query (int ql, int qr, int l, int r, int nd)
    {
        if(l > qr or r < ql)
            return INF;

        if(l >= ql and r <= qr)
        {
            return tree[nd];
        }

        push(nd, l, r);
        int mid = (l+r)/2;
        int left = query(ql, qr, l, mid, 2*nd);
        int right = query(ql, qr, mid+1, r, 2*nd+1);
        return min(left, right);
    }
};

void solve (int test)
{
    cout << "Test " << test << ":\n";

    int n; cin >> n;
    string s; cin >> s;

    SegTree st(n);

    for(int i = 0; i < n; i++)
    {
        st.update(i, n-1, s[i] == '(' ? 1 : -1);
    }

    // for(int i = 1; i <= 15; i++)
    // {
    //     cout << st.tree[i] << ' ';
    // }
    // cout << '\n';for(int i = 1; i <= 15; i++)
    // {
    //     cout << st.lazy[i] << ' ';
    // }
    // cout << '\n';

    int m; cin >> m;
    while(m--)
    {
        int q; cin >> q;

        if(q == 0)
        {
            if(st.query(0, n-1) == 0 and st.query(n-1, n-1) == 0)
                cout << "YES\n";
            else
                cout << "NO\n";

            continue;
        }

        bool open = s[q-1] == '(';
        s[q-1] = open ? ')' : '(';

        int add = open ? -2 : 2;
        st.update(q-1, n-1, add);
    }

    // for(int i = 1; i <= 15; i++)
    // {
    //     cout << st.tree[i] << ' ';
    // }
    // cout << '\n';for(int i = 1; i <= 15; i++)
    // {
    //     cout << st.lazy[i] << ' ';
    // }
    // cout << '\n';
}

int32_t main ()
{
    cin.tie(0)->sync_with_stdio(0);

    // MUDAR LIMITE PARA 10!!!
    for(int i = 1; i <= 10; i++)
        solve(i);

    return 0;
}
