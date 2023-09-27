#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

void print_node(Node *head){
    Node *current_node = head;
    while(current_node!=NULL){
        printf("%d\n",current_node->data);
        current_node = current_node->next;
    }
}

//insert_node

int insert_At_first(Node *head,int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->next = head;
    new_node->data = data;
    return new_node;
}

int insert_at_end(Node *head,int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    Node *current_node = head;
    while(current_node->next!=NULL){
        current_node = current_node->next;
    }
    current_node->next = new_node;
    new_node->next = NULL;
    new_node->data = data;
    return head;
}

int insert_at_index(Node *head, int index, int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    Node *current_node  = head;
    int i = 0;
    while(i!=index-1){
        current_node= current_node->next;
        i++;
    }
    new_node->data = data;
    new_node->next = current_node->next;
    current_node->next = new_node;
    return head;

}

//delete node

int rmvfirst_node(Node *head){
    Node *current_node = head;
    head = head->next;
    free(current_node);
    return head;
}

int rmvlast_node(Node *head){
    Node *p = head;
    Node *q = head->next;
    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }
        p->next = NULL;
        free(q);
        return head;
 }

 int rmv_At_index(Node *head,int index){
     Node *p = head;
     Node*q = head->next;
     for(int i = 0;i<index-1;i++){
        p = p->next;
        q = q->next;
     }
     p->next = q->next;
     free(q);
     return head;
 }

 int rmv_At_Value(Node *head,int value){
     Node *p = head;
     Node *q = head->next;
     while(q->data!=value&&q->next!=NULL){
        p = p->next;
        q = q->next;
     }
     if(q->data == value){
        p->next = q->next;
        free(q);
        return head;
     }
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

    print_node(head);
    printf("\n");
    //head = rmvfirst_node(head);
    //print_node(head);
    //head = rmvlast_node(head);
    //print_node(head);
    //head = rmv_At_index(head,2);
    //print_node(head);
    //head = rmv_At_Value(head,20);
    //print_node(head);
    //head = insert_At_first(head,5);
    //print_node(head);
    //head = insert_at_end(head,50);
    //print_node(head);
    head = insert_at_index(head,2,25);
    print_node(head);

}
