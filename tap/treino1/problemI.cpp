#include <bits/stdc++.h>
using namespace std;

int main ()
{
    long long n;
    cin >> n;

    long long extra = (n + 1), out = 0, answer = n;

    int i = 1;
    while (extra > 0)
    {
        if (extra >= i)
        {
            extra -= i;
            out++;
        }
        else
        {
            break;
        }

        i++;
    }

    answer = answer + 1 - out;

    cout << answer << endl;

    return 0;
}