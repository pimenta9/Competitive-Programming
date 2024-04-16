#include <bits/stdc++.h>
using namespace std;

void f(int arr[], int n, int k, int nonZeroes)
{
    if (k == 0) return;

    int y = k / nonZeroes;
    int r = k % nonZeroes;
    int sum = 0;
    int Zeroes = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            if (arr[i] >= y)
            {
                arr[i] -= y;
                if (arr[i] == 0) Zeroes++;
            }
            else
            {
                arr[i] = 0;
                sum += arr[i];
                Zeroes++;
            }
        }
    }

    f(arr, n, sum, (nonZeroes - Zeroes));

    // f(arr, n, r, (nonZeroes - Zeroes));

    int j = 0;
    while (r)
    {
        if (arr[j] > 0)
        {
            arr[j]--;
            r--;
        }
        j++;
    }
    return;
}

int main ()
{
    int n, k, nonZeroes = 0;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] > 0)
            nonZeroes++;
    }

    f(arr, n, k, nonZeroes);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}