#include "stdio.h"
#define MAX 10000

void print_array(int array[], int size){
    for(int i=0; i<size; i++){
        printf("%-4d",array[i]);
    }
    printf("\n");
}

void upHeap(int array[], int k){
    int v;
    v = array[k];
    array[0] = MAX;
    while (array[k/2]<=v) // 부모 <= 자식
    {
        array[k] = array[k/2];
        k/=2;
    }
    array[k] = v;
}

void downHeap(int array[], int n, int k){
    int i;
    int v = array[k];
    while(k<=n/2){
        i = k<<1; // 2*k
        if(i<n && array[i]<array[i+1]) i++; //왼쪽, 오른쪽 노드 비교
        if(v>=array[i]) break;
        array[k] = array[i];
        k=i;
    }
    array[k] = v;
}

void insert(int array[], int *hn, int v){
    array[++(*hn)] = v;
    upHeap(array, *hn);
}

int delete(int array[], int *n){
    // printf("delete v = %d\n",*n);
    int v = array[1];
    array[1] = array[(*n)--];
    downHeap(array, *n, 1);
    return v;
}

void heap_sort(int array[], int n){
    int hn = 0;
    int i= 0;
    for(i=1; i<=n; i++)
        insert(array, &hn, array[i]);
    for(i=hn; i>=1; i--){
        array[i] = delete(array, &hn);
    }
    for(int j=0; j<n; j++){
        array[j] = array[j+1];
    }
}

void main(){
    int array[] = {11,1,83,202,55,4,119,81,15,47,19,28};
    int oldSize = sizeof(array)/sizeof(int);
    int size = sizeof(array)/sizeof(int);
    printf("########### Sorting before ###########\n");
    print_array(array, size);
    heap_sort(array, size);
    printf("########### Sorting after ###########\n");
    print_array(array, oldSize);
}