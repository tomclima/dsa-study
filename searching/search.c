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

int binary_recursive(int * array, int left, int right, int key)
{
    int position;

    if(left < right)
    {
        int middle = (left + right)/2;
        if (array[middle] > key)
        {
            return binary_recursive(array, left, middle, key);
        }
        else if (array[middle] < key){
            return binary_recursive(array, middle + 1, right, key);
        }
        else{
            return middle;
        }
    }
    else{
        return -1;
    }
}




int binary_iterative(int * arr, int left, int right, int key)
{   
    int answer = -1;
    int middle;

    while(left <= right){
        middle = left + (right - left)/2;
    
        if(arr[middle] <= key){
            answer = middle;
            left = middle + 1;
        }
        else{
            right = middle -1;
        }
    }
    return answer;
}

int main(){
    int n, k;   
    scanf("%d %d", &n, &k);
    int array[n];
    for(int i = 0; i < n; i ++){
        scanf("%d", &array[i]);
    }
    int iter = binary_iterative(array, 0, n-1, k);
    printf("%d", iter);

}
