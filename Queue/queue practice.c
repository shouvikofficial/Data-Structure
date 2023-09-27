#include<stdio.h>
#include<stdlib.h>

struct node *front = NULL;
struct node *end =NULL;

struct node{
    int data;
    struct node *next;
};

void traverse_node(struct node *front){
    while(front!=NULL){
        printf("%d\n",front->data);
        front= front->next;
    }
}

void enqueue(int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node==NULL){
        printf("Queue is full!");
    }else{
        new_node->data = data;
        new_node->next = NULL;
        if(front == NULL){
            front= end = new_node;
        }else{
            end->next = new_node;
            end = new_node;
        }
    }
}

int dequeue(){
    int val=-1;
    struct node *current_node = front;
    if(front==NULL){
         printf("Queue is empty!");
    }else{
         front = front->next;
         val = current_node->data;
         free(current_node);
    }
    return val;
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    /*traverse_node(front);*/
    printf("Dequeue element is: %d\n",dequeue());
    printf("Dequeue element is: %d\n",dequeue());
    traverse_node(front);

return 0;
}
