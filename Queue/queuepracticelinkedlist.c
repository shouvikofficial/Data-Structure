#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    Node *left;
    Node *right;
    int data;
};

Node *create_node(int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data =data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_at_left(Node *root,Node *child){
    root->left = child;
}

void insert_at_right(Node *root,Node *child){
    root->right = child;
}

void pre_order(Node *root){
    printf("%d\n",root->data);
    if(root->left!=NULL){
        pre_order(root->left);
    }

    if(root->right!=NULL){
        pre_order(root->right);
    }
}

void in_order(Node *root){
    if(root->left!=NULL){
        in_order(root->left);
    }
    printf("%d\n",root->data);
    if(root->right!=NULL){
        in_order(root->right);
    }
}

void post_order(Node *root){
    if(root!=NULL){
        post_order(root->left);
        post_order(root->right);
        printf("%d\n",root->data);
    }
}

Node *tree(){
    Node *six = create_node(6);
    Node *four = create_node(4);
    Node *one = create_node(1);
    Node *five = create_node(5);
    Node *seven = create_node(7);

    insert_at_left(six,four);
    insert_at_right(six,seven);
    insert_at_left(four,one);
    insert_at_right(four,five);
    return six;
}


int main(){
    Node *root = tree();

    post_order(root);
    printf("\n");
    in_order(root);
    printf("\n");
    pre_order(root);



return 0;
}
