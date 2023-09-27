#include<stdio.h>
#include<stdlib.h>

int comparefunc(const void *a,const void *b){
    return ( *(int*)a - *(int*)b );
}

int main(){
    int i,n=5;
    int values[] = {65,6,100,1,250};
    qsort(values,5,sizeof(int),comparefunc);

    for(int i =0;i<n;i++){
        printf("%d\n",values[i]);
    }
    printf("\n");

return 0;
}
