#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n; cin >> n;

    vector<int> p(n);
    vector<int> scores(101, 0);
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        scores[p[i]]++;
        if (p[i] > max)
        {
            max = p[i];
        }
    }

    int r = 1, k;

    vector<int> answer(n);
    while (r <= n)
    {
        for (int i = 0; i < n; i++)
        {
            if (p[i] == max)
                answer[i] = r;
        }

        int lastMax = max;

        k = scores[max];
        r += k;

        max = 0;
        for (int i = 0; i < n; i++)
        {
            if (p[i] > max && p[i] < lastMax)
                max = p[i];
        }
    }

    for (int i = 0; i < n; i++)
        cout << answer[i] << endl;

    return 0;
}
