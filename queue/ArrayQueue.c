#include "stdio.h"
#define MAX 10

int queue[MAX];
int front, rear;

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

void init_queue(){
    front = rear = 0;
}

void clear_queue(){
    front = rear;
}

void print_queue(){
    printf("\n");
    for(int i=front; i!=rear; ++i % MAX){
        printf("queue[%d]=%d\n",i,queue[i]);
    }
    if((front+1) % MAX == 0){
        printf("queque is empty!!! \n");
    }
    printf("\n");
}

void main(){
    init_queue();
    put(1);
    put(3);
    put(6);
    put(9);
    put(7);
    put(2);
    put(0);
    put(0);
    put(10);
    put(20);
    printf("####################################################################################################################################\n");
    print_queue();
    for(int i=0; i<3; i++){
        get();
    }
    printf("####################################################################################################################################\n");
    print_queue();
    for(int i=0; i<7; i++){
        get();
    }
    printf("####################################################################################################################################\n");
    clear_queue();
    print_queue();
}
