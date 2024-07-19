// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int A, B;

    while (scanf("%d", &A) != EOF)
    {
        cin >> B;

        if (A == B)
        {
            cout << A << endl;
            continue;
        }

        if (A > B)
            cout << A << endl;
        else
            cout << B << endl;
    }

    return 0;
}
