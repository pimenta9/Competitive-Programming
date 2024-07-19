// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

vector<int> f = {1};

int fac(int x)
{
    return (x * f[x -1]);
}

int main ()
{
    int n;

    while (scanf("%d", &n) != EOF)
    {
        int answer = 0;

        for (int i = (f.size() - 1); f[i] < n; )
        {
            f.resize(f.size() + 1);

            i++;
            f[i] = fac(i);
        }

        int j = f.size() - 2;
        while (n > 0)
        {
            answer += n/f[j];

            n = n % f[j];

            j--;
        }

        cout << answer << endl;
    }

    return 0;
}
