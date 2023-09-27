#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *previous;
    Node *next;
};

//traversal node
Node *print_node(Node *head){
    Node *current_node = head;
    while(current_node!=NULL){
        printf("%d\n",current_node->data);
        current_node = current_node->next;
    }
    return head;
}

//reverse traverse node
Node *reversePrintNode(Node *last){
    Node *current_node = last;
    int i = 4;
    while(current_node!=NULL){
        printf("%d No data is %d\n",i,current_node->data);
        current_node= current_node->previous;
        i--;
    }

    return last;
}

int main(){
    Node *head;
    Node *a;
    Node *b;
    Node *c;

    //memory allocation
    head = (Node*)malloc(sizeof(Node));
    a = (Node*)malloc(sizeof(Node));
    b = (Node*)malloc(sizeof(Node));
    c = (Node*)malloc(sizeof(Node));

    //data
    head->data = 10;
    a->data = 20;
    b->data = 30;
    c->data = 40;

    //next pointer
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = NULL;

    //previous pointer
    head->previous = NULL;
    a->previous = head;
    b->previous = a;
    c->previous = b;

    print_node(head);
    printf("\n");
    reversePrintNode(c);


return 0;
}
