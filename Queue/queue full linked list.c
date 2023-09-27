#include<stdio.h>
#include<stdlib.h>


struct node *front =NULL;
struct node *end = NULL;

typedef struct node *Node;

struct node{
    int data;
    struct node *next;
};

void linkedListTraversal(struct node *current_node){
    printf("Printing the elements of this linked list\n");
    while (current_node != NULL){
        printf("Element: %d\n", current_node->data);
        current_node = current_node->next;
    }
}

void enQueue(int data){
    struct node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Queue is full!");
    }else{
        new_node->data = data;
        new_node ->next = NULL;
    if(front == NULL){
        front = end = new_node;
    }else{
        end->next = new_node;
        end = new_node;
    }
    }
}

int deQueue(){
    int val = -1;
    struct node  *current_node = front;
    if(front == NULL){
        printf("Queue is empty!");
    }else{
        front = front->next;
        val = current_node->data;
        free(current_node);
    }
    return val;

}

int main(){
    enQueue(10);
    enQueue(20);
    enQueue(30);
    enQueue(40);
    linkedListTraversal(front);
    printf("Dequeue elemet is %d\n",deQueue());
    printf("Dequeue elemet is %d\n",deQueue());
    printf("Dequeue elemet is %d\n",deQueue());
}
