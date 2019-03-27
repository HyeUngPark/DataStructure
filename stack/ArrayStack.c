#include "stdio.h"
#define MAX 10

int stack[MAX];
int top;

void init_stack(void){
    top = -1;
}

int push(int t){
    if(top >=MAX-1){
        printf("########### STACK OVER FLOW ###########\n");
        return -1;
    }else{
        stack[++top] = t;
        return t;
    }
}

int pop(void){
    if(top<0){
        printf("########### STACK UNDER FLOW ###########\n");
        return -1;
    }
    return stack[top--];
}

void print_stack(void){
    printf("PRINT STACK \n");
    for(int i=top; i>=0; i--){
        printf("%-6d",stack[i]);
    }
    printf("\n");
}

void main(){
    init_stack();
    printf("########### PUSH ###########\n");
    for(int i=0; i<11; i++){
        push(i);
    }
    print_stack();
    printf("########### POP ###########\n");
    for(int i=0; i<5; i++){
        pop();
    }
    print_stack();
    for(int i=0; i<6; i++){
        pop();
    }
}