#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string s;
    cin >> s;

    string t;
    cin >> t;

    int position = 0;

    for (int i = 0; t[i] != '\0'; i++)
    {
        if (t[i] == s[position])
        {
            position++;
        }
    }

    cout << (position + 1) << endl;

    return 0;
}