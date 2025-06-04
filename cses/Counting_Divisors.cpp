// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

#define MAX_x 1000000

int divisors[MAX_x + 1];

void init()
{
    for (int i = 1; i <= MAX_x; i++)
    {
        for (int j = i; j <= MAX_x; j += i)
        {
            divisors[j]++;
        }
    }
}

int main ()
{
    init();

    int n;
    cin >> n;

    while (n--)
    {
        int x;
        cin >> x;

        cout << divisors[x] << endl;
    }

    return 0;
}
