#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, k, answer = 0, aux = 0;
    cin >> n >> k;

    string str[n];

    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; (str[i])[j] != '\0'; j++)
        {
            if ((str[i])[j] == '4' || (str[i])[j] == '7')
            {
                aux++;
            }
        }
        if (aux > k)
        {
            answer++;
        }
        aux = 0;
    }

    cout << (n - answer) << endl;

    return 0;
}