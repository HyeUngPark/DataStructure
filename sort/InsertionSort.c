#include "stdio.h"

void insertion_sort(int array[], int size){
    int j,temp;
    for(int i=1; i<size; i++){
        j=i;
        temp = array[i];
        while(j>0 && array[j-1]>temp){
            array[j] = array[j-1];
            j--;
        }
        array[j]= temp;
    }
}

void main(){
    int array[] = {11,10,33,22,55,9};
    int size = sizeof(array)/sizeof(int);
    printf("########### Sorting before ###########\n");
    for(int i=0; i<size; i++){
        printf("%-4d",array[i]);
    }
    insertion_sort(array,size);
    printf("\n########### Sorting after ###########\n");
    for(int i=0; i<size; i++){
        printf("%-4d",array[i]);
    }
}