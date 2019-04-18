#include "stdio.h"

void selection_sort(int array[], int size){
    int min, minIndex;
    for(int i=0; i<size-1; i++){
        int min = array[i];
        int minIndex = i;
        for(int j=i+1; j<size; j++){
            if(min>array[j]){
                min = array[j];
                minIndex = j;
            }
        }
        array[minIndex] = array[i];
        array[i] = min;
    }
}

void main (){
    int array[] = {11,10,33,22,55,9};
    int size = sizeof(array)/sizeof(int);
    printf("########### Sorting before ###########\n");
    for(int i=0; i<size; i++){
        printf("%-4d",array[i]);
    }
    printf("\n########### Sorting after ###########\n");
    selection_sort(array, size);
    for(int i=0; i<size; i++){
        printf("%-4d",array[i]);
    }
}