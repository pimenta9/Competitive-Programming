#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans;
    for (int x = 0; x <= 100; x++)
    {
        int current = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] >= x)
                current++;
        }
        if (current >= x)
            ans = x;
    }
    cout << ans << endl;

    return 0;
}
