// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int t; cin >> t;

    while (t--)
    {
        int n; cin >> n;

        int answer = n / 4;
        if (n % 4) answer++;

        cout << answer << endl;
    }

    return 0;
}
