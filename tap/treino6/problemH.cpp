// AtCoder chokudai_S001_h

#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
int n;

int a[N];
int tree[4*N];

void readInput()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void buildTree(int p, int l, int r)
{
    if (l == r)
    {
        tree[p] = 0;
        return;
    }

    int mid = (l+r)/2;
    buildTree(2*p, l, mid);
    buildTree(2*p+1, mid+1, r);

    tree[p] = max(tree[2*p], tree[2*p + 1]);
}

int query(int p, int l, int r, int Lfind, int Rfind)
{
    if (Lfind > Rfind)
        return -1;

    if (l == Lfind && r == Rfind)
    {
        return tree[p];
    }

    int mid = (l + r)/2;
    
    return max ( ( query ( 2*p, l, mid, Lfind, min(Rfind, mid) ) ), 
                 ( query ( 2*p+1, mid+1, r, max(Lfind, mid+1), Rfind ) ) );
}

void updateTree(int p, int l, int r, int val, int pos)
{
    if (l == r)
    {
        tree[p] = val;
        return;
    }

    int mid = (l+r)/2;
    if (pos <= mid)
        updateTree(2*p, l, mid, val, pos);
    else
        updateTree(2*p+1, mid+1, r, val, pos);

    tree[p] = max(tree[2*p], tree[2*p + 1]);
}

void printTree()
{
    for (int i = 1; i <= 9; i++)
    {
        if (i == 1 || i == 2 || i == 4 || i == 8)
            cout << endl;

        cout << tree[i] << " ";
    }
}

int main ()
{
    readInput();

    buildTree(1, 1, n);

    // printTree();

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        //                            -1?? sim ou não?
        int x = query(1, 1, n, 1, a[i]) + 1;

        if (x > max) max = x;

        updateTree(1, 1, n, x, a[i]);

        // cout << "----------\n";
        // printTree();
    }

    cout << max << endl;

    return 0;
}
