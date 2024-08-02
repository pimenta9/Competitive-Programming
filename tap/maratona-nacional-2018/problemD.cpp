#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n; cin >> n;

    int answer = n;

    map<string, int> m;

    for (int i = 0; i < n; i++)
    {
        string temp; cin >> temp;

        string aux;

        int j;
        for (j = 0; temp[j] != '@'; j++)
        {
            if (temp[j] != '.' && temp[j] != '+')
                aux.push_back(temp[j]);

            if (temp[j] == '.') continue;

            if (temp[j] == '+')
            {
                while (temp[j+1] != '@')
                {
                    j++;
                }
            }
        }
        for (j++; temp[j] != '\0'; j++)
        {
            aux.push_back(temp[j]);
        }

        if (m[aux]) answer--;

        m[aux]++;
    }

    cout << answer << endl;

    return 0;
}
