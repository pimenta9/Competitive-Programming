#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);

    long long total = 0;

    int v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        total += v[i];
    }

    int maxIndex = 0;
    for (int i = 0; i >= 0 && i < n; )
    {
        if (i > maxIndex) maxIndex = i;

        int right = (v[i] % 2 == 0)? 0 : 1 ;

        if (v[i] > 0)
        {
            v[i]--;
            total--;
        }

        if (right) i++;
        else i--;
    }

    printf("%d %lld\n", maxIndex+1, total);

    return 0;
}
