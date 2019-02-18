#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int enteroBin[8], decimalBin[8], j=0, v=0, cont=-1, mantisa[23];
int numeroBin[16], nuevonum[16], numConNueve[16], exponente[8], exponentefinal[8];

int DecAbin(int num)
{
    int i, temp=0;
    for(i=1;i<9;i++)
    {
        if(num%2 == 0 )
        {
            enteroBin[i]=0;
        }
        else
        {
            enteroBin[i]=1;
        }
        temp=num/2;
        num=temp;

    }
    for(i=8;i>0;i--)
    {
        numeroBin[j]=enteroBin[i];
        numConNueve[v]=enteroBin[i];
        j++;
        v++;
    }
}

int floatAbin(float num)
{
    int i, entero;
    float temp;
    for(i=0;i<8;i++)
    {
        temp=num*2;
        if(temp >= 1)
        {
            decimalBin[i]=1;
        }
        else
        {
            decimalBin[i]=0;
        }
        num=temp-floor(temp);
    }
    for(i=0;i<8;i++)
    {
        if(i==0)
        {
            numConNueve[v]=9;
            v++;
        }
        numeroBin[j]=decimalBin[i];
        numConNueve[v]=decimalBin[i];
        j++;
        v++;
    }
}

int nuevoNumero()
{
    int i, l, k=0, v=0;
    for(i=0;i<16;i++)
    {
        if(numeroBin[i]==1)
        {
            for(l=i;l<16;l++)
            {
                nuevonum[k]=numeroBin[l];
                numConNueve[v]=numConNueve[l];
                k++;
                v++;
            }
            break;
        }
    }
}

int recorerPunto()
{
    int i;
    for(i=0;i<16;i++)
    {
        if(numConNueve[i]!=9)
        {
            cont++;
        }
        else
            break;
    }
}

int exponenteFunc(int num)
{
    int i, temp=0;
    for(i=1;i<9;i++)
    {
        if(num%2 == 0 )
        {
            exponente[i]=0;
        }
        else
        {
            exponente[i]=1;
        }
        temp=num/2;
        num=temp;

    }
    j=0;
    for(i=8;i>0;i--)
    {
        exponentefinal[j]=exponente[i];
        j++;
    }
}

int mantisaFunc()
{
    int i;
    for(i=0;i<23;i++)
    {
        mantisa[i]=nuevonum[i+1];
    }
}

int main()
{
    float num;
    int i, entero, temp, signo=1;
    float decimal;

    printf("######### PROGRAMA QUE CONVIERTE DE UN NUMERO DECIMAL AL ESTANDAR IEEE-754 #########\n");
    getch();
    printf("\nIntroduce un n%cmero: ", 163);
    scanf("%f", &num);

    if(num>=0)
        signo=0;

    entero=floor(num);
    decimal=num-floor(num);

    DecAbin(entero);
    floatAbin(decimal);
    nuevoNumero();
    recorerPunto();

    cont = cont + 127;

    exponenteFunc(cont);
    mantisaFunc();

    printf("\n Signo     Exponente              Mantisa\n");
    printf("   %d", signo);
    printf("       ");
    for(i=0;i<8;i++)
    {
        printf("%d", exponentefinal[i]);
    }
    printf("        ");
    for(i=0;i<23;i++)
    {
        printf("%d", mantisa[i]);
    }
    printf("\n");

    return 0;
}
