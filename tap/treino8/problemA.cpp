// CSES 1646

#include <bits/stdc++.h>
using namespace std;

int n, q, length;
vector<int> a;
vector<long long> b;

void readInput()
{
    cin >> n >> q;

    a.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    length = (int) sqrt(n) + 1;

    b.resize(length, 0);

    for (int i = 0; i < n; i++)
    {
        b[ i/length ] += a[i];
    }
}

int main ()
{
    readInput();

    long long sum;

    for (int k = 0; k < q; k++)
    {
        int l, r;
        cin >> l >> r;
        l--; r--;

        sum = 0;

        int leftBlock = l/length;
        int rightBlock = r/length;

        if (leftBlock == rightBlock)
        {
            for (int i = l; i <= r; i++)
            {
                sum += a[i];
            }
        }
        else
        {
            for (int i = l, end = (leftBlock+1)*length - 1; i <= end; i++)
            {
                sum += a[i];
            }
            for (int i = leftBlock+1; i <= rightBlock-1; i++)
            {
                sum += b[i];
            }
            for (int i = rightBlock*length; i <= r; i++)
            {
                sum += a[i];
            }
        }

        cout << sum << endl;
    }

    return 0;
}
