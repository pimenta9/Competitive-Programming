// ACCEPTED!

#include <stdio.h>
int main(){
    int n, tam, vet, sumA=0, sumB=0, sumC=0, sumD=0, sumT=0;
    scanf("%d", &n);
    for (int i=0;i<n;i++)
    {
        scanf("%d", &tam);
        vet = tam*4;
        char c;
        for(int j=0; j<vet;j++)
        {
            scanf(" %c", &c);
            if(c=='A'){sumA++;}
            else if(c=='B'){sumB++;}
            else if(c=='C'){sumC++;}
            else if(c=='D'){sumD++;}
        }
        
        if(sumA<tam){sumT=sumT+sumA;}
        else {sumT=sumT+tam;}

        if(sumB<tam){sumT=sumT+sumB;}
        else {sumT=sumT+tam;}

        if(sumC<tam){sumT=sumT+sumC;}
        else {sumT=sumT+tam;}

        if(sumD<tam){sumT=sumT+sumD;}
        else {sumT=sumT+tam;}

        printf("%d\n", sumT);

        sumA=0, sumB=0, sumC=0, sumD=0, sumT=0;
    }
}
