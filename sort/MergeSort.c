#include "stdio.h"
#include "stdlib.h"

void print_array(int array[], int size){
    for(int i=0; i<size; i++){
        printf("%-4d",array[i]);
    }
    printf("\n");
}

void merge_sort(int a[], int n){
    int i, j, k;
    int first, second, size;
    int *b;
    b = (int*)malloc(sizeof(int)*n);
    for(size = 1; size<n; size *=2){
        first = -2 * size; // 초기 값
        second = first + size;
        while(second + size*2 < n){
            first = second + size;
            second = first + size;

            i = k = first;
            j = second;
            while(i<first+size || (j<second+size && j<n)){
                if(a[i]<=a[j]){
                    if(i<first + size)
                        b[k++] = a[i++];
                    else
                        b[k++] = a[j++];
                }else{
                    if(j<second+size && j<n)
                        b[k++] = a[j++];
                    else
                        b[k++] = a[i++];
                }
                printf(" b[%d]=%d\t",k-1,b[k-1]);
            }
            printf("\n############################\n");
        }
        for(i=0; i<n; i++)
            a[i] = b[i];
    }
    free(b);
}

void main(){
    int array[] = {6,8,5,2,7,3,1,4};
    int size = sizeof(array)/sizeof(int);
    printf("########### Sorting before ###########\n");
    print_array(array, size);
    printf("######################################\n");
    merge_sort(array, size);
    printf("########### Sorting after ###########\n");
    print_array(array, size);
}