#include<stdio.h>

int main(){
int array[] = {12,54,3,2,45,23,67,35};
int i, j, size = 8;

for(i=0;i<size-1;i++){
    for(j=0;j<size-1-i;j++){
        //swap
        if(array[j]>array[j+1]){
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        }
    }
}
    for(int i=0;i<size;i++){
        printf("%d\n",array[i]);
    }
    printf("\n");

return 0;
}
