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
        node *s = head;
        while(s->next != tail){
            if(s->next==t){
                s->next = t->next;
                free(t);
                break;
            }else{
                s = s->next;
            } 
        }
    }

    node *find_node(int key){
        node *s = head->next;
        while(s != tail->next){
            if(key == s->key){
                break;
            }else{
                s = s->next;
            }
        }
        return s;
    }

    void findAll(){
        node * t = head->next;
        printf("#########findAll()########\n");
        while(t != tail){
            printf("find(%d) = %s , address = %d\n",t->key,find_node(t->key)->value,&t->next);
            t = t->next;
        }
        printf("##########################\n");
    }

    void main(){
        init_list();
        insert_list(0,"apple",head);
        insert_list(1,"banana",find_node(0));
        insert_list(2,"melon",find_node(1));
        insert_list(3,"grape",find_node(2));
        insert_list(4,"pineapple",find_node(3));

        delete_list(find_node(2));
        delete_list(find_node(1));
        
        findAll();
    }

