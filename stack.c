#include<stdio.h>
#define CAPACITY 3

int stack[CAPACITY];
int top = -1;

void push(int x){
    if(top<CAPACITY-1){
        top = top + 1;
        stack[top] = x;
        printf("Successfully Added: %d\n",x);
    }else{
        printf("No Spaces!\n");
    }
}

int pop(){
    if(top>=0){
       int val = stack[top];
       top = top-1;
       return val;
    }else{
       printf("Empty!");
    }
return -1;
}

int peek(){
    if(top>=0){
        return stack[top];
    }else{
        printf("Empty!\n");
    }
return -1;
}

int main(){

peek();
push(10);
push(20);
push(30);
printf("Pop item is: %d\n",pop());
push(40);
printf("Peek item is: %d\n",peek());

return 0;
}
