#include<stdio.h>
#include<stdlib.h>

int fact(int n){
    int i;
    int fact = 1;
    for(i=1;i<=n;i++){
        fact = fact * i;
    }
    return fact;
}

int numOfBST(int node){
  return (fact(2*node))/((node + 1)*fact(node)*fact(2*node-node));
}


int main(){
    int node, a;
    printf("Enter key value : \n");
    scanf("%d",&node);
    a = numOfBST(node);
    printf("Number of BST's = %d\n",a);
    return 0;
}
