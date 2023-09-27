#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;


struct node{
    int data;
    Node *left;
    Node *right;
};

int create_node(int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void add_left_child(Node *root,Node *child){
    root->left = child;
}

void add_right_child(Node *root,Node *child){
    root->right = child;
}

Node *tree(){
    Node *ten = create_node(10);
    Node *twenty = create_node(20);
    Node *thirty = create_node(30);
    add_left_child(ten,twenty);
    add_right_child(ten,thirty);

    Node *fourty = create_node(40);
    add_left_child(thirty,fourty);

    return ten;
}

int main(){
    Node *root = tree();
    printf("%d\n",root->data);

    return 0;

}
