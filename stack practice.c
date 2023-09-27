#include<stdio.h>
#include<stdlib.h>

typedef struct node *Node;

struct node{
    int data;
    Node *next;
};

void traverse(Node *head){
    struct node *current_node = head;
    while(current_node!=NULL){
        printf("%d\n",current_node->data);
        current_node = current_node->next;
    }
}

int is_full(top){
    Node *new_node = (Node)malloc(sizeof(Node));
    if(new_node==NULL){
        return 1;
    }else{
        return 0;
    }
}

int is_empty(top){
    if(top == NULL){
        return 1;
    }else{
        return 0;
    }
}

Node *push(Node *top,int x){
    if(is_full(top)){
        printf("Overflow!");
    }else{
        struct node *new_node = (Node*)malloc(sizeof(Node));
        new_node->data = x;
        new_node->next = top;
        top = new_node;
        return top;
    }
}

int *pop(struct node** top){
    if(is_empty(*top)){
        printf("Stack underflow!");
    }else{
        struct node *current_node = *top;
        *top = (*top)->next;
        int x = current_node->data;
        free(current_node);
        return x;
    }
}

int main(){
    struct node *top = NULL;
    top = push(top,5);
    top = push(top,10);
    top = push(top,20);
    top = push(top,30);
    int element = pop(&top);
    printf("Pop element is %d\n",element);
    traverse(top);

return 0;
}
