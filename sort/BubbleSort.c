#include "stdio.h"

void bubble_sort(int array[], int size){
    int t;
    for(int i=0; i<size-1; i++){
        for(int j=1; j<size; j++){
            if(array[j-1]>array[j]){
                t = array[j-1];
                array[j-1] = array[j];
                array[j] = t;
            }
        }
    }
}

void main(){
    int array[] = {11,10,33,22,55,9};
    int size = sizeof(array)/sizeof(int);
    printf("########### Sorting before ###########\n");
    for(int i=0; i<size; i++){
        printf("%-4d",array[i]);
    }
    bubble_sort(array,size);
    printf("\n########### Sorting after ###########\n");
    for(int i=0; i<size; i++){
        printf("%-4d",array[i]);
    }
}