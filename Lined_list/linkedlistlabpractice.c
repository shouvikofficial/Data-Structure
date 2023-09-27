#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    Node *next;
    int data;
};

Node *create_node(int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->data = data;
    return new_node;
}

Node *traverse_node(Node *head){
    Node *current_node = head;
    while(current_node!=NULL){
        printf("%d",current_node->data);
        printf("\n");
        current_node = current_node->next;
    }
}

Node *insert_at_end(Node *head,int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data= data;
    Node *current_node = head;
    while(current_node->next != NULL){
        current_node = current_node->next;
    }
    current_node->next = new_node;
    new_node->next = NULL;
    return head;
}

Node *insert_at_first(Node *head,int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

Node *insert_after_node(Node *head,Node *pre_node,int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data =data;
    new_node->next = pre_node->next;
    pre_node->next = new_node;
    return head;
}

Node *insert_at_index(Node *head,int index,int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    Node *current_node = head;
    int i = 0;
    while(i != index -1){
        current_node = current_node->next;
        i++;
    }
    new_node->data = data;
    new_node->next = current_node->next;
    current_node->next = new_node;
    return head;
}

Node *deleteFirstNode(Node *head){
     Node *current_node = head;
     head =head->next;
     free(current_node);
     return head;
}

Node *delete_lastNode(Node *head){
    Node *p = head;
    Node *q = head->next;
    while(q->next !=NULL){
        p = p->next;
        q = q->next;
    }
    p->next =NULL;
    free(q);
    return head;
}

Node *deleteBetween(Node *head,int index){
    Node *p = head;
    Node *q = head->next;
    for(int i =0;i<index-1;i++){
        p = p->next;
        q =  q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

Node *deleteValue_index(Node *head,int value){
    Node *p = head;
    Node *q = head->next;
    while(q->data !=value && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;

}
int main(){

    Node *head = create_node(10);
    Node *a = create_node(20);
    Node *b = create_node(30);
    Node *c = create_node(40);

    //head = (Node*)malloc(sizeof(Node));
    //a = (Node*)malloc(sizeof(Node));
    //b = (Node*)malloc(sizeof(Node));
    //c = (Node*)malloc(sizeof(Node));

    head->data = 10;
    a->data = 20;
    b->data = 30;
    c->data = 40;

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = NULL;

    //insert_at_end(head,50);
    //traverse_node(head);
    //insert_at_first(head,100);
    //traverse_node(head);
   // insert_after_node(head,a,25);
    //traverse_node(head);
    //insert_at_index(head,1,35);
    //delete_lastNode(head);
    //deleteBetween(head,2);
    deleteValue_index(head,20);
    traverse_node(head);

return 0;
}
