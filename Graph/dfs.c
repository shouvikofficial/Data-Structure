#include<stdio.h>
#include<stdlib.h>

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


void Dfs(int i){
    printf("%d",i);
    visited[i] = 1;
    for(int j = 0;j<7;j++){
        if(A[i][j]==1 && !visited[j]){
            Dfs(j);
        }
    }
}

int main(){
    Dfs(0);
return 0;
}
