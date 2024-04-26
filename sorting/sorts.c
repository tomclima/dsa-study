#include <stdio.h>
#include <stdlib.h>

void swap(int* pt1, int* pt2)
{
    int temp = *pt2;
    *pt2 = *pt1;
    *pt1 = temp;
}

void merge(int* array, int array_size, int left, int right){
    
    int middle = (left + right)/2;
    int* temp = (int *)malloc(sizeof(int) * array_size);
    for(int i = left; i <= right; i++){temp[i] = array[i];}

    int i1 = left, i2 = middle + 1;
    for(int curr = left; curr <= right; curr++){
        if (i1 == middle + 1)
        {
            array[curr] = temp[i2++];
        }
        else if (i2 > right)
        {
            array[curr] = temp[i1++];
        }
        else if (temp[i1] <= temp[i2])
        {
            array[curr] = temp[i1++];
        }
        else
        {
            array[curr] = temp[i2++];
        }
    }
}

void mergesort(int* array, int array_size, int left, int right)
{
    if(left < right){
        int middle = (left + right)/2;
        mergesort(array, array_size, left, middle);
        mergesort(array, array_size, middle + 1, right);
        merge(array, array_size, left, right);
    }
}


int partition(int * array, int left, int right)
{
    int partition = array[left];
    int i1 = left, i2 = right + 1;

    do{
        do{
            i1++;
        }while(!(array[i1] >= partition || i1 >= right));

        do{
            i2--;
        }while(!(array[i2] <= partition));

        swap(&array[i1], &array[i2]);

   }while(!(i1 >= i2));

   swap(&array[i1], &array[i2]);
   swap(&array[left], &array[i2]);
   return(i2);
}
void quicksort(int* array, int left, int right)
{
    if(left < right){
       int median = partition(array, left, right);
        quicksort(array, left, median - 1);
        quicksort(array, median + 1, right); 
    } 
}


int main()
{
    int size;
    scanf("%d", &size);

    int* array = (int *)malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
    quicksort(array, 0, size - 1);
    
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    free(array);
}


