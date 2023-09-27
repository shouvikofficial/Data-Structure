//bfs

#include<stdio.h>
#include<stdlib.h>

struct node *front =NULL;
struct node *end =NULL;

struct node{
    int data;
    struct node *next;
};

void *enQueue(int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("Queue is Full");
    }else{
        new_node->data;
        new_node->next = NULL;

    if(front==NULL){
        front=end=new_node;
    }else{
        end->next =new_node;
        end = new_node;
        }
    }
}

int *deQueue(){
    int val = -1;
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

    int node;
    int i =0;
    int visited[7] = {0,0,0,0,0,0,0};
    int A[7][7] ={
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
    };
    printf("%d",i);
    visited[i] = 1;
    enQueue(i);

    while(!front == NULL){
        int node = deQueue(front);
        for(int j = 0;j<7;j++){
            if(A[node][j]=1 && !visited[j]){
                printf("%d",j);
                visited[j] = 1;
                enQueue(j);
            }
        }
    }


return 0;
}
