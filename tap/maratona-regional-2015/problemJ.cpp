// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int j, r;

    while (scanf("%d %d", &j, &r) != EOF)
    {
        int n = j*r;

        vector<int> points;
        points.resize(j, 0);

        for (int i = 0; i < n; i++)
        {
            int aux; cin >> aux;

            points[i % j] += aux;
        }

        int max = points[0];
        int maxPlayer = 0;
        for (int i = 1; i < j; i++)
        {
            if (points[i] >= max)
            {
                max = points[i];
                maxPlayer = i;
            }
        }

        cout << maxPlayer + 1 << endl;
    }

    return 0;
}
