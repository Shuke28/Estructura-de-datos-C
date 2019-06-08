#include <stdio.h>
#include <conio.h>
#include <time.h>

int array[100], arrayR[100], bubbleCont=0, insertCont=0, selectionCont=0, shellCont=0;

void ingresarArray(int num)
{
    int i;
    srand(time(NULL));
    for(i=0; i<num; i++)
    {
        arrayR[i]=rand()%10;
        printf("%d\n", arrayR[i]);
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

void arrayReset(int num)
{
    int i;
    for(i=0;i<num;i++)
    {
        array[i]=arrayR[i];
    }
}

void bubbleSort(int num)
{
    int i, temp, j;
    for(i=0; i<num-1; i++)
    {
        for(j=0; j<num-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                bubbleCont++;
            }
        }
    }

}

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
            insertCont++;
        }
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
                selectionCont++;
            }
        }
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
                shellCont++;
            }
            array[j]=temp;
        }
        saltos = saltos / 2;
    }
}

int main()
{
    int num;

    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &num);

    ingresarArray(num);

    arrayReset(num);
    bubbleSort(num);
    printArray(num);

    arrayReset(num);
    insertSort(num);
    printArray(num);

    arrayReset(num);
    selectionSort(num);
    printArray(num);

    arrayReset(num);
    shellSort(num);
    printArray(num);

    printf("\nBubble Sort realizo %d el procedimiento.", bubbleCont);
    printf("\nInsert Sort realizo %d el procedimiento.", insertCont);
    printf("\nSelection Sort realizo %d el procedimiento.", selectionCont);
    printf("\nShell Sort realizo %d el procedimiento.\n", shellCont);

    return 0;
}
