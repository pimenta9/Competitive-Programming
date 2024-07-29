// ACCEPTED!

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;

    while (t--)
    {
        int n, q; cin >> n >> q;

        vector<vector<int>> pre1(26, vector<int>(1, 0));
        vector<vector<int>> pre2(26, vector<int>(1, 0));

        for (int i = 1; i <= n; i++)
        {
            char c; cin >> c;

            for (int j = 'a'; j <= 'z'; j++)
            {
                if (j == c)
                {
                    pre1[c - 'a'].push_back(pre1[c - 'a'][i - 1] + 1);
                }
                else
                {
                    pre1[j - 'a'].push_back(pre1[j - 'a'][i - 1]);
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            char c; cin >> c;

            for (int j = 'a'; j <= 'z'; j++)
            {
                if (j == c)
                {
                    pre2[c - 'a'].push_back(pre2[c - 'a'][i - 1] + 1);
                }
                else
                {
                    pre2[j - 'a'].push_back(pre2[j - 'a'][i - 1]);
                }
            }
        }

        for (int i = 0; i < q; i++)
        {
            int answer = 0;

            int l, r; cin >> l >> r;

            vector<int> letters(26, 0);

            for (int j = 0; j < 26; j++)
                letters[j] = -(pre1[j][r] - pre1[j][l-1]);

            for (int j = 0; j < 26; j++)
                letters[j] += pre2[j][r] - pre2[j][l-1];

            for (int j = 0; j < 26; j++)
                if (letters[j] > 0)
                    answer += letters[j];

            cout << answer << endl;
        }
    }

    return 0;
}
