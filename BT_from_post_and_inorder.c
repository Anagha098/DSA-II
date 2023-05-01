#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return(n);
}

int linearSearch(int in[], int strt, int target, int size){
	int i;
    for(i=0;i<size;i++){
        if(i==target);
        return i;
    }
}


int search(int in[], int root, int size){
    int i;
    for(i=0;i<size;i++){
        if(in[i]==root){
            return i;
        }
    }
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
struct node* constrct(int in[], int post[], int instrt, int inend, int postend, int n);


struct node* constructTree(int in[], int post[], int size){
	return constrct(in, post, 0, size-1, size-1, size);
}

struct node* constrct(int in[], int post[], int instrt, int inend, int postend, int n){
    if(instrt>inend){
        return NULL;
    }
    else{
        struct node *root = createNode(post[postend]);
        int index = search(in,root->data,n);
        root->left = constrct(in, post, instrt, index-1, postend-(inend-index)-1, n);
	    root->right = constrct(in, post, index+1, inend, postend-1, n);
	    return root;
    }
}



int main(){
    int post[] = {9,15,7,20,3};
    int in[] = {9,3,15,20,7};
 /*   int post[100], in[100], n, i;
    printf("Enter the number of elements : \n");
    scanf("%d",&n);
    printf("Enter postorder elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&post[i]);
    }
    printf("Enter inorder elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&in[i]);
    }
*/
    int size = sizeof(post)/sizeof(post[0]);
	struct node* root = constructTree(in, post, size);
    constructTree(in, post, size);
	inorder(root);
	printf("\n");
	postorder(root);
	return 0;

}
