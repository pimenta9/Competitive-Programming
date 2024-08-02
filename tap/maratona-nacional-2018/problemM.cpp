#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n; cin >> n;
    int current, previous, answer = 1;
    cin >> current;
    previous = current;
    for (int i = 1; i < n; i++)
    {
        cin >> current;

        if (current > previous)
            answer++;

        previous = current;
    }

    cout << answer << endl;

    return 0;
}
