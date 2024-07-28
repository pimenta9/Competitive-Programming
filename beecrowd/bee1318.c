// ACCEPTED!

#include <stdio.h>

#define MAX 10000

int ingressos[MAX];

int main ()
{
    int n, m;
    scanf("%d%d", &n, &m);

    while (n != 0 || m != 0)
    {
        int answer = 0;

        for (int i = 0; i < n; i++)
        {
            ingressos[i] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            int x;
            scanf("%d", &x);
            x--;
            
            if (ingressos[x] == 1)
            {
                answer++;
            }

            ingressos[x]++;
        }

        printf("%d\n", answer);

        scanf("%d%d", &n, &m);
    }

    return 0;
}
