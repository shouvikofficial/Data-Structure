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

void add_left_node(Node *root,Node*child){
    root->left = child;
}

void add_right_node(Node *root,Node*child){
    root->right = child;
}

void pre_order(Node *node){
    printf("%d",node->data);
    printf("\n");
    if(node->left!=NULL){
        pre_order(node->left);   //recursion
    }
    if(node->right!=NULL){
        pre_order(node->right);
    }
}

void post_order(Node *node){
    if(node!=NULL){
        post_order(node->left);   //recursion
        post_order(node->right);
        printf("%d",node->data);
        printf("\n");
    }
}

void in_order(Node *node){
    if(node->left!=NULL){
        in_order(node->left);   //recursion
    }
    printf("%d",node->data);
    printf("\n");
    if(node->right!=NULL){
        in_order(node->right);
    }
}

Node *tree(){
    Node *eight = create_node(8);
    Node *six = create_node(6);
    Node *seven = create_node(7);
    Node *four = create_node(4);
    Node *five = create_node(5);
    Node *ten = create_node(10);
    Node *nine = create_node(9);


    add_left_node(eight,six);
    add_right_node(eight,nine);
    add_left_node(six,five);
    add_right_node(six,seven);
    add_left_node(nine,four);
    add_right_node(nine,ten);
    return eight;
}


int main(){
    Node *root = tree();
    printf("IN order :\n");
    in_order(root);

return 0;
}
