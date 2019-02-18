#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int signo, exponente[8], mantisa[23], num, mantisanueva[23], k=1, punto;
float numDecimal=0, numEntero=0;

int expAdec(int exponente[8])
{
    int i, temp=0, p=0;
    for(i=0;i<8;i++)
    {
        p=pow(2,i);
        temp=exponente[i]*p;
        num=num+temp;
    }
}

int mantisaFunc(int mantisa[23])
{
    int i, j;
    for(i=23;i>0;i--)
    {
        if(mantisa[i]==1)
        {
            for(j=0;j<i+1;j++)
            {
                mantisanueva[k]=mantisa[j];
                k++;
            }
            mantisanueva[0]=1;
            break;
        }
    }
}

int enterobin[8], decimalbin[12];
int separar(int mantisanueva[23])
{
    int i, k=0;
    for(i=0;i<punto+1;i++)
    {
        enterobin[k]=mantisanueva[i];
        k++;
    }
    k=0;
    for(i=punto+1;i<12;i++)
    {
        decimalbin[k]=mantisanueva[i];
        k++;
    }
}

int enterobinAentero(int enterobin[8])
{
    int i, p=0, temp1=0, k=0;
    for(i=7;i>0;i--)
    {
        p=pow(2,i);
        temp1=enterobin[k]*p;
        numEntero=numEntero+temp1;
        k++;
    }
}

int decimalbinAdecimal(int decimalbin[12])
{
    int i, p=0, k=0;
    float temp1=0, p1;
    for(i=1;i<12;i++)
    {
        p=pow(2,i);
        p1=1.0/p;
        temp1=decimalbin[k]*p1;
        numDecimal=numDecimal+temp1;
        k++;
    }
}

int main()
{
    int i;
    float numerofinal;

    printf("######### PROGRAMA QUE CONVIERTE DEL ESTANDAR IEEE-754 A NUMERO DECIMAL #########\n");

    printf("\nIngrese signo 0/1: ");
    scanf("%d", &signo);
    printf("\nPara obtener el exponente...(De derecha a izquierda)\n");
    for(i=0;i<8;i++)
    {
        printf("Ingrese el numero de la casilla [%d] : ", i+1);
        scanf("%d", &exponente[i]);
    }
    printf("\nPara obtener la mantisa...(De izquierda a derecha)\n");
    for(i=0;i<23;i++)
    {
        printf("Ingrese el numero de la casilla [%d] : ", i+1);
        scanf("%d", &mantisa[i]);
    }

    expAdec(exponente);
    punto=num-127;

    mantisaFunc(mantisa);

    separar(mantisanueva);

    enterobinAentero(enterobin);
    decimalbinAdecimal(decimalbin);

    numerofinal=numEntero + numDecimal;

    if(signo==1)
    {
        numerofinal=(numerofinal*-1);
    }

    printf("\nEl numero es: %f", numerofinal);

    return 0;
}
