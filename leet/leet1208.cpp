#include <bits/stdc++.h>
using namespace std;

int equalSubstring(string s, string t, int maxCost)
{
    int n = s.size();

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = abs(s[i] - t[i]);
    }

    
}

int main ()
{
    string s1 = {"abcd"}, s2 = {"bcdf"};

    cout << equalSubstring(s1, s2, 3) << endl;

    return 0;
}