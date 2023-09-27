#include<stdio.h>

int binary_search(int A[],int n,int data){
    int left,right,mid;
    left = 0;
    right = n-1;
    mid = (left+right)/2;
    while(left<=right){
        if(data == A[mid]){
            return mid;
        }else if(data>A[mid]){
            left = mid+1;
        }else{
            right = mid-1;
        }
        return -1;
    }
}

int main(){

return 0;
}
