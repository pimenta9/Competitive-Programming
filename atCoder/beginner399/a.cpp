#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n; cin >> n;
    string s, t; cin >> s >> t;

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
            answer++;
    }

    cout << answer << endl;

    return 0;
}
