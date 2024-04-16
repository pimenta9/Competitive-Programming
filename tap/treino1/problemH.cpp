#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;

    int arr[n], max = 0, maxIndex, secondMax = 0;
    for (int i = 0; i < n; i ++)
    {
        cin >> arr[i];

        if (arr[i] > max)
        {
            max = arr[i];
            maxIndex = i;
        }
    }    

    for (int i = 0; i < n; i ++)
    {
        if (i != maxIndex)
        {
            if (arr[i] > secondMax)
                secondMax = arr[i];
        }
    }

    for (int i = 0; i < n; i ++)
    {
        if (i != maxIndex)
        {
            cout << max << endl;
        }
        else
            cout << secondMax << endl;
    }

    return 0;
}