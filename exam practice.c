#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

void traverse_node(Node *head){
    Node *current_node = head;
    while(current_node!=NULL){
        printf("%d\n",current_node->data);
        current_node = current_node->next;
    }
}

//insertion node

Node *insert_at_first(int data,Node *head){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return new_node;
}

Node *insert_at_end(Node *head,int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    Node *current_node = head;
    while(current_node->next != NULL){
        current_node = current_node->next;
    }
    new_node->data = data;
    current_node->next = new_node;
    new_node->next = NULL;
    return head;
}

Node *insert_at_index(Node *head,int data,int node){
    Node *new_node = (Node*)malloc(sizeof(node));
    Node *current_node = head;
    int i = 0;
    while(i<node-1){
        current_node = current_node->next;
        i++;
    }
    new_node->data = data;
    new_node->next = current_node->next;
    current_node->next = new_node;
    return head;
}

Node *insert_after_node(Node *head,Node *pre_node,int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = pre_node->next;
    pre_node->next = new_node;
    return head;
}

//deletion

Node *delete_at_first(Node *head){
    Node *current_node = head;
    head = head->next;
    free(current_node);
    return head;
}

Node *delete_at_end(Node *head){
    Node *p = head;
    Node *q = head->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

Node *delete_index_node(Node *head,int node){
    Node *p = head;
    Node *q = head->next;
    for(int i = 0;i<node-1;i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

Node *delete_data_node(Node *head,int data){
    Node *p = head;
    Node *q = head->next;
    while(q->data != data && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

int main(){
    Node *head;
    Node *a;
    Node *b;
    Node *c;

    head = (Node*)malloc(sizeof(Node));
    a = (Node*)malloc(sizeof(Node));
    b = (Node*)malloc(sizeof(Node));
    c = (Node*)malloc(sizeof(Node));

    head->data = 10;
    a->data = 20;
    b->data = 30;
    c->data = 40;

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = NULL;

    traverse_node(head);
    printf("\n");
    //head = insert_at_first(5,head);
    //traverse_node(head);
    ///head = insert_at_end(head,45);
    //traverse_node(head);
    //head = insert_at_index(head,25,2);
    //traverse_node(head);
    //head = insert_after_node(head,a,35);
    //traverse_node(head);
    //head = delete_at_first(head);
    //traverse_node(head);
    //head = delete_at_end(head);
    //traverse_node(head);
    //head = delete_index_node(head,2);
    //traverse_node(head);
    head = delete_data_node(head,20);
    traverse_node(head);


return 0;
}
