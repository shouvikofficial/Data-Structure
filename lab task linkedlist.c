#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *previous;
    Node *next;
};

//traverse node
Node *print_node(Node *head){
    Node *current_node = head;
    while(current_node!=NULL){
        printf("%d\n",current_node->data);
        current_node = current_node->next;
    }
    return head;
}

//reverse print
Node *reverse_print(Node *last){
    Node *current_node = last;
    while(current_node!=NULL){
        printf("%d\n",current_node->data);
        current_node = current_node->previous;
    }
    return last;
}

int main(){
    Node *head;
    Node *a;
    Node *b;
    Node *c;
    Node *d;

    //memory allocation
    head = (Node*)malloc(sizeof(Node));
    a = (Node*)malloc(sizeof(Node));
    b = (Node*)malloc(sizeof(Node));
    c = (Node*)malloc(sizeof(Node));
    d = (Node*)malloc(sizeof(Node));

    head->data = 70;
    a->data = 50;
    b->data = 20;
    c->data= 30;
    d->data= 60;

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;

    head->previous = NULL;
    a->previous = head;
    b->previous = a;
    c->previous = b;
    d->previous = c;

    print_node(head);
    printf("\n");
    reverse_print(d);

return 0;
}
