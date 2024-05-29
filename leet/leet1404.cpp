#include <bits/stdc++.h>
using namespace std;

int numSteps(string s)
{
    long long x = 0;
    int n = s.size();

    for (int i = (n - 1); i >= 0; i--)
    {
        x += 1;
    }
}

int main ()
{
    string s = {"1101"};

    cout << numSteps(s) << endl;

    return 0;
}