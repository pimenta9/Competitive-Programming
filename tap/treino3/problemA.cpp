#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int from, to;
    vector<int> aux;
    aux.resize(5, 0);

    for (int i = 0; i < 3; i++)
    {
        cin >> from >> to;

        aux[from]++;
        aux[to]++;

        if (aux[from] >= 3 || aux[to] >= 3)
        {
            cout << "NO\n";
            return 0;
        }
    }

    for (int i = 1; i <= 4; i++)
    {
        if (!aux[i])
        {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}
