#include <bits/stdc++.h>
using namespace std;

int n;
vector<int > vec;

void inputRead()
{
    cin >> n;

    vec.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];

        vec[i]--;
    }
}

int findDistance(int i)
{
    if (vec[i] < 0) return 1;

    return (findDistance(vec[i]) + 1);
}

int main ()
{
    inputRead();

    int max = findDistance(0), x;

    for (int i = 1; i < n; i++)
    {
        x = findDistance(i);

        if (x > max) max = x;
    }

    cout << max << endl;

    return 0;
}
