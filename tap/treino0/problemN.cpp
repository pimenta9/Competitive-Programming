#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string str1, str2;
    cin >> str1 >> str2;

    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] >= 'a') str1[i] -= ('a' - 'A');
        if (str2[i] >= 'a') str2[i] -= ('a' - 'A');

        if (str1[i] > str2[i])
        {
            cout << "1" << endl;
            return 0;
        }
        if (str1[i] < str2[i])
        {
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << "0" << endl;

    return 0;
}