#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n, from, to;
    cin >> n;

    vector<int> aux;
    aux.resize(n, 0);

    for (int i = 1; i <= (n-1); i++)
    {
        cin >> from >> to;

        aux[from]++;
        aux[to]++;

        if (aux[from] >= (n-1) || aux[to] >= (n-1))
        {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";

    return 0;
}
