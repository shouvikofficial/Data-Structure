#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *left;
    Node *right;
};

Node *create_node(int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right =NULL;
    return new_node;
}

void in_order(Node *root){
    if(root->left!=NULL){
        in_order(root->left);
    }
    printf("%d",root->data);
    if(root->right!=NULL){
        in_order(root->right);
    }
}

void add_leftChild(Node *root,Node *child){
    root->left = child;
}

void add_rightChild(Node *root,Node *child){
    root->right = child;
}

Node *tree(){
    Node *one = create_node(1);
    Node *two = create_node(2);
    Node *three = create_node(3);
    Node *four = create_node(4);
    Node *five = create_node(5);

    add_leftChild(four,two);
    add_rightChild(four,five);
    add_leftChild(two,one);
    add_rightChild(two,three);
    return four;

}

void insertBST(Node *root,int data){
    Node *prev =NULL;
    while(root!=NULL){
        prev = root;
        if(data==root->data){
            return;
        }elseif(data<root->data){
            root= root->left;
        }else{
            root = root->right;
        }
    }
    struct node *new_node = create_node(data);
    if(data<pre->data){
        prev->left = new_node;
    }else{
    pre->right = new_node;
    }
}

int main(){
    Node *root = tree();

    in_order(root);


return 0;
}
