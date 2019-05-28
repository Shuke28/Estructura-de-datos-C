#include <stdio.h>

void bubbleSort(int array[10])
{
    int i, temp, j;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            if(array[j] > array[j+1])
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                j++;
            }
        }
    }

}

void printArray(int array[10])
{
    int i;
    for(i=0; i<10; i++)
    {
        printf("\nPosicion [%d] con el valor: %d", i+1, array[i]);
    }
}

int main()
{
    int array[10]={1,6,3,9,0,5,7,8,4,2};

    printArray(array);

    bubbleSort(array);
    printf("\n");

    printArray(array);

    return 0;
}
