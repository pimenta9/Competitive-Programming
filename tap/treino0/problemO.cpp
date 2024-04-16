#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string str;
    cin >> str;

    int n1 = 0, n2 = 0, n3 = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '1') n1++;
        else if (str[i] == '2') n2++;
        else if (str[i] == '3') n3++;
    }

    for (int i = 1; i <= n1; i++)
    {
        if (i >= 2) cout << "+";

        cout << "1";
    }
    for (int i = 1; i <= n2; i++)
    {
        if (i >= 2 || n1 > 0) cout << "+";

        cout << "2";
    }
    for (int i = 1; i <= n3; i++)
    {
        if (i >= 2 || (n1 > 0 || n2 > 0)) cout << "+";

        cout << "3";
    }

    cout << endl;

    return 0;
}