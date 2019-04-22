#include <stdio.h>

void print_array(int array[], int size){
    for(int i=0; i<size; i++){
        printf("%-4d",array[i]);
    }
    printf("\n");
}

void shell_sort(int array[], int size){
    for(int i=size/2; i>0; i /=2){
        for(int j=0; j<i; j++){
            for(int k=i+j; k<size; k+=i){
                int l = array[k];
                int m = k;
                while(m>i-1 && array[m-i] > l){
                    array[m]=array[m-i];
                    m -= i;
                }
                array[m] = l;
            }
        }
        printf("i=%d || ",i);
        print_array(array,size);   
    }
}


void main(){
    int array[] = {11,10,33,22,55,9,99,81,15,27};
    int size = sizeof(array)/sizeof(int);
    printf("########### Sorting before ###########\n");
    print_array(array, size);
    printf("######################################\n");
    shell_sort(array, size);
}