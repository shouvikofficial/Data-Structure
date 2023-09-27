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
    printf("%d",root->data);
    printf("\n");
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
    printf("%d",root->data);
    printf("\n");
    if(root->right!=NULL){
        in_order(root->right);
    }
}

void post_order(Node *root){
    if(root!=NULL){
        post_order(root->left);
        post_order(root->right);
        printf("%d",root->data);
        printf("\n");
    }
}

//expected tree

  /*   5
      / \
     3   7
    / \
   1   4
   */

Node *tree(){
    Node *one = create_node(1);
    Node *five = create_node(5);
    Node *three = create_node(3);
    Node *four = create_node(4);
    Node *seven = create_node(7);
    insert_at_left(five,three);
    insert_at_right(five,seven);
    insert_at_left(three,one);
    insert_at_right(three,four);
    return five;
}

int main(){

    Node *root = tree();
    printf("Pre Order :\n");
    pre_order(root);
    printf("\n");
    printf("In Order :\n");
    in_order(root);
    printf("\n");
    printf("Post order :\n");
    post_order(root);


}
