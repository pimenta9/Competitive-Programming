// ACCEPTED

#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> vec;
vector<int> tree;

void inputRead ()
{
    cin >> n >> q;

    vec.resize(n + 1);
    tree.resize((4*n) + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> vec[i];
    }
}

void build (int p, int l, int r)
{
    if (l == r)
    {
        tree[p] = vec[l];
        return;
    }

    int mid = (l + r)/2;

    build ((p*2), l, mid);
    build ((p*2 + 1), (mid + 1), r);

    tree[p] = min (tree[p*2], tree[p*2 + 1]);
}

int query (int p, int tl, int tr, int a, int b)
{
    if (a > b) return 1000000001;

    if (tl == a && tr == b)
        return tree[p];

    int tmid = (tl + tr)/2;
    return ( min (query((p*2), tl, tmid, a, min(b, tmid)),
                 query((p*2 + 1), (tmid + 1), tr, max(a, tmid + 1), b)) );
}

void update (int p, int tl, int tr, int pos, int val)
{
    if (tl == tr)
    {
        tree[p] = val;
        return;
    }

    int tmid = (tl + tr)/2;

    if (pos <= tmid)
    {
        update(p*2, tl, tmid, pos, val);
    }
    else
    {
        update(p*2 + 1, tmid+1, tr, pos, val);
    }

    tree[p] = min(tree[p*2], tree[p*2 + 1]);
}

int main ()
{
    inputRead();

    build (1, 1, n);

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << vec[i] << " ";
    // } cout << endl;

    // for (int i = 1; i <= (2*n - 1); i++)
    // {
    //     cout << tree[i] << " ";
    // } cout << endl;

    for (int i = 0; i < q; i++)
    {
        int operation; cin >> operation;

        if (operation == 1)
        {
            int k, u; cin >> k >> u;

            update (1, 1, n, k, u);
        }
        else
        {
            int a, b; cin >> a >> b;

            cout << query(1, 1, n, a, b) << endl;
        }
    }

    return 0;
}
