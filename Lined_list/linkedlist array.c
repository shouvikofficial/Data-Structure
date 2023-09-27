#include<stdio.h>
struct Node *createLinkedList(int array[],int size);

struct Node{
   int data;
   struct Node *next;
};

int main(){
  int a[] = {5,10,20};
return 0;
}

struct Node *createLinkedList(int array[],int size){
    struct Node *head,*temp, *current = NULL;
    int i;
    for(i=0;i<size;i++){
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = array[i];
        temp->next = NULL;
        if(head == NULL){
            head = NULL;
            current = NULL;
        }else{
            current->next = temp;
            current = current->next;
        }
    }
}
