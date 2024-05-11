#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int > bit;

void update(int i, int value)
{
    while (i <= n)
    {
        bit[i] = bit[i] ^ value;

        i = i + (i & -i);
    }
}

int query (int x)
{
    int answer = 0;

    while (x)
    {
        answer = answer ^ bit[x];

        x = x - (x & -x);
    }

    return answer;
}

void inputRead()
{
    cin >> n >> q;

    bit.resize((n + 1), 0);
    bit[0] = 0;

    for (int i = 1; i < (n + 1); i++)
    {
        int value;
        cin >> value;

        update(i, value);
    }
}

int main ()
{
    inputRead();

    for (int i = 0; i < q; i++)
    {
        // for (int j = 0; j < (n + 1); j++)
        // {
        //     printf("%d: %d\n", j, bit[j]);
        // }

        int t, x, y;
        cin >> t >> x >> y;

        if (t == 1)
        {
            update(x, y);
        }
        else
        {
            cout << (query(y) ^ query(x - 1)) << endl;
        }
    }

    return 0;
}
