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
    int i = 0; //start from 0 index
    int visited[7] = {0,0,0,0,0,0,0};
    int A[7][7] = {
        //      0 1 2 3 4 5 6
   /*      0 */{0,1,1,1,0,0,0},
  /*       1 */{1,0,1,0,0,0,0},
  /*       2 */{1,1,0,1,1,0,0},
    /*     3 */{1,0,1,0,1,0,0},
   /*      4 */{0,0,1,1,0,1,1},
    /*     5 */{0,0,0,0,1,0,0},
    /*     6 */{0,0,0,0,1,0,0},
    };

    printf("%d",i);
    visited[i] = 1;
    enqueue(i); //enqueue for exploration
    while(!front==NULL){
        int node = dequeue(front);
        for(int j = 0;j<7;j++){
            if(A[node][j]==1 && visited[j]==0){
                printf("%d",j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
return 0;
}
