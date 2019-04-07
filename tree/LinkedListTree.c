#include "stdio.h"
#include "stdlib.h"

typedef struct _tree
{
    char value;         
    struct _tree *left;  
    struct _tree *right;
    struct _tree *next;
} tree;

tree *root, *parent;

void init_tree(void){
    root = (tree*)malloc(sizeof(tree));
    root->left = NULL;
    root->right = NULL;
    root->value = '\0';
    parent = root;
}

tree *addVaule(char value){
    tree *new;
    new = (tree*)malloc(sizeof(tree));
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    if(parent->value != '\0' && parent->left != NULL && parent->right != NULL){
        if(!parent->right->next)parent->right->next = new;
        parent = parent->next;
    }
    if(parent->value=='\0'){ // root
        parent->value = new->value;
    }else if(parent->left == NULL){ // left
        parent->left = new;
        if(!parent->next)parent->next = new;
    }else{ // right
        parent->right = new;
        if(!parent->left->next)parent->left->next = new;
    }
}

void printPreorder(tree *t){
    printf("%-2c",t->value);
    if(t->left)printPreorder(t->left);
    if(t->right)printPreorder(t->right);
}
void printInorder(tree *t){
    if(t->left)printInorder(t->left);
    printf("%-2c",t->value);
    if(t->right)printInorder(t->right);
}
void printPostorder(tree *t){
    if(t->left)printPostorder(t->left);
    if(t->right)printPostorder(t->right);
    printf("%-2c",t->value);
}

void main(){
    init_tree();
    
    char treeValue[] = {'A','B','C','D','E','F','G'};
    for(int i=0; i<sizeof(treeValue); i++){
        addVaule(treeValue[i]);
    }
    printf("PreOrder : "); 
    printPreorder(root);
    printf("\nInOrder : "); 
    printInorder(root); 
    printf("\nPostOrder : "); 
    printPostorder(root); 

}
