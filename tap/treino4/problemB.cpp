#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int > p;

void inputRead()
{
    cin >> n >> q;

    p.resize(n + 1);

    p[0] = 0;
    cin >> p[1];
    int x;
    for (int i = 2; i < (n + 1); i++)
    {
        cin >> x;

        p[i] = p[i - 1] ^ x;
    }
}

int main ()
{
    inputRead();

    int a, b;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;

        int x = p[b] ^ p[a - 1];

        cout << x << endl;
    }

    return 0;
}
