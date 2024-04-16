#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string str;
    getline(cin, str);

    bool alphabet[26];
    for (int i = 0; i < 26; i++)
    {
        alphabet[i] = false;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            alphabet[str[i] - 97] = true;
        }
    }

    int ans = 0;

    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] == true)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}