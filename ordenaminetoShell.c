#include <stdio.h>
#include <conio.h>
#include <time.h>

int array[10], cont;

void ingresarArray(int num)
{
    int i;
    srand(time(NULL));
    for(i=0; i<num; i++)
    {
        array[i]=rand()%10;
        printf("%d\n", array[i]);
    }
}

void printArray(int num)
{
    int i;
    printf("Numeros ordenados:\n");
    for(i=0; i<num; i++)
    {
        printf("Celda [%d]: %d\n", i+1, array[i]);
    }
}

void shellSort(int num)
{
    int i, j, temp, saltos;
    saltos = num / 2;
    while(saltos > 0)
    {
        for(i=saltos; i < num ; i++)
        {
            j= i;
            temp=array[i];
            while((j >= saltos)&&(array[j-saltos] > temp))
            {
                array[j] = array[j-saltos];
                j = j - saltos;
            }
            array[j]=temp;
        }
        saltos = saltos / 2;
    }
}

int main()
{
    int num;

    printf("Ingrese el numero de elementos: ");
    scanf("%d", &num);

    ingresarArray(num);

    shellSort(num);

    printArray(num);

    return 0;
}
