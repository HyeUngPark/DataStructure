/*
ㅇ 연결리스트
    장점 : 재배열이 쉬움

1. 단순 연결리스트
    - 정보를 저장하는 노드와 바로 다음 노드를 가리키는 링크 하나로 구성
    - head와 tail(null로 표현하는 경우도 있음)이 필요

*/
#include "stdio.h"
#include "stdlib.h"

    typedef struct _node
    {
        int key;            // key
        char *value;        // value
        struct _node *next; // 다음 노드의 위치
    } node;
    
    node *head, *tail;

    void init_list(void){
        head = (node*)malloc(sizeof(node));
        tail = (node*)malloc(sizeof(node));
        head -> next = tail;
        tail -> next = tail;
    }

    node *insert_list(int key, char *value, node *t){
        node *s;
        s = (node*)malloc(sizeof(node));
        s->key = key;
        s->value = value;
        s->next = t->next;
        t->next = s;
        return s;
    }

    int delete_list(node *t){
        node *s;
        if(t->next == tail){
            return 0;
        }else{
            s = t->next;
            t->next = t->next->next;
            free(s);
            return 1;
        }
    }

    node *find_node(int key){
        node *s;
        s=head->next;
        while(s->key != key && s->key != tail->key){
            s = s->next;
        }
        return s;
    }

    void main(){
        init_list();
        insert_list(0,"apple",head);
        insert_list(2,"banana",find_node(0));
        insert_list(1,"grape",find_node(2));
        
        printf("findAll \n");
        node * t = head->next;
       
        while(t->key != tail->key){
            printf("find(%d) = %s , address = %d\n",t->key,find_node(t->key)->value,&t->next);
            t = t->next;
        }
        
        // printf("find_node(%d)",);
    }

