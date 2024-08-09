// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int T; cin >> T;

    while (T--)
    {
        string s; cin >> s;
        string t; cin >> t;
        bool possible = false;

        int i, j;
        for (i = 0, j = 0; s[i] != '\0'; i++)
        {
            if (s[i] == t[j])
            {
                j++;
            }

            if (s[i] == '?')
            {
                s[i] = t[j];
                j++;
            }

            if (t[j] == '\0')
            {
                i++;
                possible = true;
                break;
            }
        }

        if (!possible)
        {
            cout << "No\n";
            continue;
        }

        for (int k = i; s[k] != '\0'; k++)
        {
            if (s[k] == '?') s[k] = 'a';
        }

        cout << "Yes\n";
        cout << s << endl;
    }

    return 0;
}
