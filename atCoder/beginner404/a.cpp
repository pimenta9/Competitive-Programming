#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string s;
    cin >> s;

    vector<bool> letter(26, false);

    for (char c : s)
        letter[c - 'a'] = true;

    for (int i = 0; i < 26; i++)
    {
        if (letter[i] == false)
        {
            cout << (char)(i + 'a') << endl;
            return 0;
        }
    }

    return 0;
}
