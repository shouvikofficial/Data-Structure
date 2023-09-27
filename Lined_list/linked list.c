#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;
struct node{
int data;
struct node *next;
};

//traverse node

void print_linkedList(Node *head){
    Node *current_node = head;
    while(current_node != NULL){
        printf("%d\n",current_node->data);
        current_node = current_node->next;
    }
}

//insert node first

Node *prepend(int data, Node *head){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node ->next = head;
    new_node ->data = data;
    return new_node;
}

//insert node any position
Node *insertAtnode(Node *head, int data, int node){
    Node * new_node = (Node*) malloc(sizeof(Node));
    Node * current_node = head;
    int i = 0;

    while (i!=node-1)
    {
        current_node = current_node->next;
        i++;
    }
    new_node->data = data;
    new_node->next = current_node->next;
    current_node->next = new_node;
    return head;
}

// insertAtEnd
    Node *insertAtEnd(Node *head, int data){
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    Node *current_node = head;

    while(current_node->next != NULL){
        current_node = current_node->next;
    }
    current_node->next = new_node;
    new_node->next = NULL;
    return head;
}

int main(){

struct node *head;
struct node *a;
struct node *b;
struct node *c;


head = (struct node*)malloc(sizeof(struct node));
a = (struct node*)malloc(sizeof(struct node));
b = (struct node*)malloc(sizeof(struct node));
c = (struct node*)malloc(sizeof(struct node));

head->data = 5;
a->data = 10;
b->data = 20;
c->data = 30;

head->next = a;
a->next = b;
b->next = c;
c->next = NULL;

print_linkedList(head);

return 0;

}
