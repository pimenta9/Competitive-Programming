// ACCEPTED!! (daily - May 28th, 2024)

#include <bits/stdc++.h>
using namespace std;

int equalSubstring(string s, string t, int maxCost)
{
    int n = s.size();

    int arr[n + 1];

    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = abs(s[i - 1] - t[i - 1]) + arr[i - 1];
    }

    int l = 0, r = 1, maxLength = 0, length, count;
    while (r <= n)
    {
        count = arr[r] - arr[l];

        if (count <= maxCost)
        {
            length = r - l;

            if (length > maxLength) maxLength = length;

            r++;
        }
        else
        {
            l++;
        }
    }

    return maxLength;
}

int main ()
{
    string s1 = {"abcde"}, s2 = {"beeei"};

    cout << equalSubstring(s1, s2, 3) << endl;

    return 0;
}
