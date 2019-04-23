#include <stdio.h>

void print_array(int array[], int size){
    for(int i=0; i<size; i++){
        printf("%-4d",array[i]);
    }
    printf("\n");
}

void quick_sort(int array[], int size){
    int pivot, temp;
    if(size>1){
        pivot = array[size-1];
        int left = -1;
        int right = size-1;
        while(1){
            while(array[++left]<pivot);
            while(array[--right]>pivot);
            if(left>=right) break;
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
        temp = array[left];
        array[left] = array[size-1];
        array[size-1] = temp;
        quick_sort(array, left);
        quick_sort(array+left+1, size-left-1);
    }
}


void main(){
    int array[] = {2,7,1,3,4,0,8,5,9,6};
    int size = sizeof(array)/sizeof(int);
    printf("########### Sorting before ###########\n");
    print_array(array, size);
    quick_sort(array, size);
    printf("########### Sorting after ###########\n");
    print_array(array, size);
}