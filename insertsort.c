#include <stdio.h>
#include <conio.h>
#include <time.h>

int array[100];

void insertSort(int num)
{
    int j, i, temp;

    for(i=0; i<num; i++)
    {
        j=i;
        while(j > 0 && array[j] < array[j-1])
        {
            temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
            j--;
        }
    }
}

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
int main()
{
    int num;

    printf("Ingrese el numero de elementos: ");
    scanf("%d", &num);

    ingresarArray(num);

    insertSort(num);

    printArray(num);

    return 0;
}
