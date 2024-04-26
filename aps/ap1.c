#include <stdio.h>
#include <stdlib.h>

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



int main()
{
    int cases;

    scanf("%d", &cases);    

    for(int i = 0; i < cases; i++){
        int array_size;
        scanf("%d", &array_size);
        int array[array_size];
        for(int j = 0; j < array_size; j++){
            scanf("%d", &array[j]);
        }
        mergesort(array, array_size, 0, array_size - 1);
        for(int k = 0; k < array_size; k++){
            printf("%d ", array[k]);
        }
        printf("\n");

        
    }
    

}
