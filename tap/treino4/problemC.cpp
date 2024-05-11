#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<long long> BIT;

void update(int i, int value)
{
    while (i <= n)
    {
        BIT[i] += value;

        i = i + (i & -i);
    }
}

void inputRead ()
{
    cin >> n >> q;

    BIT.resize(n + 1, 0);

    for (int i = 1; i < (n + 1); i++)
    {
        int x;
        cin >> x;
        update(i, x);
    }
}

long long query (int n)
{
    if (n == 0) return 0;
    long long sum = 0;
    int x = n;

    while (x)
    {
        sum += BIT[x];

        x = x - (x & -x);
    }

    return sum;
}

int main ()
{
    inputRead();

    int operation;
    for (int i = 0; i < q; i++)
    {     
        cin >> operation;

        if (operation == 1)
        {
            int l, r;
            cin >> l >> r;

            cout << query(r) - query(l) << endl;
        }
        else
        {
            int p, x;
            cin >> p >> x;

            update(p + 1, x);
        }
    }

    return 0;
}
