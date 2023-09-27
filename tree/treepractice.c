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

void add_left_child(Node *root,Node*child){
    root->left = child;
}

void add_right_child(Node *root,Node*child){
    root->right = child;
}

void pre_order(Node *node){
    printf("%d",node->data);
    printf("\n");
    if(node->left!=NULL){
        pre_order(node->left);
    }
    if(node->right!=NULL){
        pre_order(node->right);
    }
}

Node *tree(){
    Node *two = create_node(2);
    Node *seven = create_node(7);
    Node *one = create_node(1);
    Node *six = create_node(6);
    Node *five = create_node(5);
    Node *eight = create_node(8);
    Node *three = create_node(3);
    Node *four = create_node(4);
    Node *nine = create_node(9);
    Node *ten = create_node(10);

    add_left_child(two,seven);
    add_right_child(two,nine);
    add_left_child(seven,one);
    add_right_child(seven,six);
    add_left_child(six,five);
    add_right_child(six,ten);
    add_right_child(nine,eight);
    add_left_child(eight,three);
    add_right_child(eight,four);


    return two;
}


int main(){

    Node *root = tree();
    pre_order(root);

return 0;
}
