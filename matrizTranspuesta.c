#include <stdlib.h>
#include <time.h>

void generaMatriz(int A[][4]);
void imprimeMatriz(int A[][4]);
void matrizMenorMayor(int A[][4]);
void matrizTraspuesta(int A[][4]);
int i, j, menor, mayor, posicionMi, posicionmi, posicionMj, posicionmj;

int main()
{
    int x, y, A[4][4];

    generaMatriz(A);

    imprimeMatriz(A);

    matrizTraspuesta(A);

    matrizMenorMayor(A);
    printf("Mayor: %d\nMenor: %d\n", mayor, menor);
    printf("Pocision del Mayor: %d-%d", posicionMi+1,posicionMj+1);
    printf("\nPocision del Menor: %d-%d", posicionmi+1,posicionmj+1);

    return 0;
}

void generaMatriz(int A[][4])
{
    srand(time(NULL));

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            A[i][j]=rand() % 201;
        }
    }
}

void imprimeMatriz(int A[][4])
{
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf(" %d  ", A[i][j]);
        }
        printf("\n");
    }
}

void matrizTraspuesta(int A[][4])
{
    printf("\Su traspuesta seria...\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf(" %d  ", A[j][i]);
        }
        printf("\n");
    }
}

void matrizMenorMayor(int A[][4])
{
    int *pA = A, temp;
    mayor = *pA;
    menor = *pA;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if( *pA > mayor )
            {
                posicionMi = i;
                posicionMj = j;
                mayor = *pA;
            }
            if( *pA < menor )
            {
                posicionmi = i;
                posicionmj = j;
                menor = *pA;
            }
            *pA++;
        }
    }
}
