#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int pokemon[123];

    for (int i = 'A'; i <= 'Z'; i++)
    {
        pokemon[i] = 0;
    }
    for (int i = 'a'; i <= 'z'; i++)
    {
        pokemon[i] = 0;
    }

    int n;
    cin >> n;

    char house[n];
    for (int i = 0; i < n; i++)
    {
        cin >> house[i];

        pokemon[house[i]]++;
    }
    
    int i = 0, j = (n - 1), answer = n;
    while (true)
    {
        cout << ".";
        if (pokemon[house[i]] > 1)
        {
            answer--;
            pokemon[house[i]]--;
            i++;
        }
        else if (pokemon[house[j]] > 1)
        {
            answer--;
            pokemon[house[j]]--;
            j--;
        }
        else
            break;
    }

    cout << answer << endl;

    return 0;
}