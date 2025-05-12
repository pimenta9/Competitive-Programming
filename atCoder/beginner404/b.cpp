#include <bits/stdc++.h>
using namespace std;

int n;
char s[100][100];
char t[100][100];

int diffs()
{
    int num_diffs = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (s[i][j] != t[i][j])
                num_diffs++;
    return num_diffs;
}

void rotate()
{
    char aux[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            aux[i][j] = s[(n-1)-j][i];
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            s[i][j] = aux[i][j];
}

int main ()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> s[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> t[i][j];

    int answer = 10000;
    answer = min(answer, diffs());
    rotate();
    answer = min(answer, diffs() + 1);
    rotate();
    answer = min(answer, diffs() + 2);
    rotate();
    answer = min(answer, diffs() + 3);

    cout << answer << endl;

    return 0;
}
