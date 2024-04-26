#include <stdio.h>
#include <stdlib.h>

int sequential(int* array, int size, int value)
{
    int return_value;
    int i = 0;
    while(i < size && array[i] != value)
    {
        i++;
    }
    if(i < size)
    {
        return_value = i;   
    }
    else{
        return_value = -1;
    }
    return return_value;
}

int binary(int * array, int left, int right, int key)
{
    int position;

    if(left < right)
    {
        int middle = (left + right)/2;
        if (array[middle] > key)
        {
            position = binary(array, left, middle, key);
        }
    }

}