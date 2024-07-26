// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string s, s1;
    cin >> s;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            s1.push_back(s[i]);
        }
    }

    for(int i = (s.size()-1), j = 0; i >= 0; i--)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            if (s[i] != s1[j])
            {
                cout << "N\n";

                return 0;
            }

            j++;
        }
    }

    cout << "S\n";

    return 0;
}
