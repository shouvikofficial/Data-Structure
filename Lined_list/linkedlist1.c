#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;
struct node{
    int data;
    Node *next;
};

//create_node
Node *create_node(int item, Node *next){
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Error!\n");
        exit(1);
    }
    new_node->data = item;
    new_node->next = next;
}

//remove_node
//1st node delete
Node *remove_node(Node *head,Node *node){
    if(node == head){
        head = node->next;
        free(node);
        return head;
    }
//any node delete//
Node *current_node = head;
while(current_node != NULL){
    if(current_node->next == node){
        break;
        return head;
    }
    current_node = current_node->next;
    if(current_node == NULL){
        return head;
    }
}

current_node->next = node->next;
free(node);
return head;

}

//Add_node

Node *prepend_node(Node *head,int item){
    head = prepend_node(head,item);
    Node *new_node = create_node(head,item);
    return new_node;
}

Node *append_node(Node *head,int item){
    Node *new_node = create_node(item,NULL);
    if(head == NULL){
        return new_node;
    }
    Node *current_node = head;
    while(current_node->next!=NULL){
        current_node = current_node->next;
    }
    current_node->next = new_node;
    return head;
}

void insert(int item, Node *node){
    Node *new_node = create_node(item,node->next);
    node->next = new_node;
    return new_node;
}

int main(){
    Node *n;
    n = create_node(10,NULL);
    printf("Data:%d",n->data);

return 0;
}

