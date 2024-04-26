void swap(int* pt1, int* pt2)
{
    int temp = *pt2;
    *pt2 = *pt1;
    *pt1 = temp;
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

