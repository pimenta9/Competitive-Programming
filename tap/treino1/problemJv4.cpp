#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    long long k;
    cin >> n >> k;

    long long arr[n];
    int nonZeroes = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        if (arr[i] > 0) nonZeroes++;
    }

    long long aux, resto, sum, j = 0;
    while (k > 0)
    {
        if (k < nonZeroes)
        {
            while (k)
            {
                if (arr[j] > 0)
                {
                    arr[j]--;
                    k--;
                }
                j++;
            }
            break;
        }

        sum = 0;
        aux = k / nonZeroes;

        k -= aux*nonZeroes;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                if (arr[i] >= aux)
                {
                    arr[i] -= aux;
                    if (arr[i] == 0) nonZeroes--;
                }
                else
                {
                    sum += arr[i];
                    arr[i] = 0;
                    nonZeroes--;
                }
            }
        }
        k += sum;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}