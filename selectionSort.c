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

void selectionSort(int num)
{
    int i, j, temp;
    for(i=0;i<=num-2;i++)
    {
        for(j=i+1;j<=num-1;j++)
        {
            if(array[i]>array[j])
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

int main()
{
    int num;

    printf("Ingrese la cantidad de elementos para el arreglo: ");
    scanf("%d", &num);

    ingresarArray(num);

    selectionSort(num);

    printArray(num);

    return 0;
}
