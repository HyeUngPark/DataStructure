#include <stdio.h>
#define MAX 20
// QUEUE

int queue[MAX];
int front, rear = 0;

int put(int k){
    if((rear+1) % MAX == front){
        printf("QUEUE OVER FLOW!\n\n");
        return -1;
    }else{
        queue[rear] = k;
        rear = ++rear % MAX;
        return 1;
    }
}

int get(){
    int k;
    if(front == rear){
        printf("QUEUE UNDER FLOW!\n\n");
        return -1;
    }else{
        k = queue[front];
        front = ++front % MAX;
        return k;
    }
}

// ARRAY
void print_array(int array[], int size){
    for(int i=0; i<size; i++){
        printf("%-4d",array[i]);
    }
    printf("\n");
}

void radix_sort(int array[], int size){
    int max = array[0];
    int digit = 0;
    int factor = 1;
    for(int i=1; i<size; i++){
        if(max<array[i]) max = array[i];
    }
    for(int i=max; i>0;i/=10){
        digit++;
    }

    for(int i =0; i<digit; i++){ 
        for(int j=0; j<10; j++){ // 0~9 
            for(int k=0; k<size; k++){
                if((array[k]/factor)%10==j){
                    put(array[k]);
                }
            }
        }
        factor *=10;
        for(int i=front; i!=rear; i++){
            array[i] =get();
        }
        printf("########### %d ROUND ###########\n",i+1);
        print_array(array,size);
        front=rear=0;
    }
}


void main(){
    int array[] = {11,1,83,202,55,4,119,81,15,47,19,28};
    int size = sizeof(array)/sizeof(int);
    printf("########### Sorting before ###########\n");
    print_array(array, size);
    radix_sort(array, size);
}