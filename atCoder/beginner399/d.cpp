#include <bits/stdc++.h>
using namespace std;

int main ()
{
    vector<int> a(400002, 0);

    int t; cin >> t;

    while (t--)
    {
        int n; cin >> n;

        for (int i = 1 ; i <= 2*n; i++)
            cin >> a[i];

        vector<int> index(n+1, 0);

        int answer = 0;

        for (int i = 1; i <= 2*n; i++)
        {
            int j = index[a[i]];

            if (!j)
            {
                index[a[i]] = i;
                continue;
            }

            if (j == i-1) continue;

            // left
            int k = i-1;
            int x = a[k];

            if (a[j-1] == x)
                answer++;

            if (a[j+1] == x)
                if (j+2 < k)
                    answer++;

            // right
            if (i == 2*n) break;

            k = i+1;
            x = a[k];

            if (a[j-1] == x or a[j+1] == x)
                answer++;
        }

        cout << answer/2 << endl;
    }

    return 0;
}
