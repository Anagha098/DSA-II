#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int data;
    struct node *right;
    struct node *left;
};

struct node* createNode(int data){
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->right = NULL;
    n->left = NULL;
    return(n);
}

void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int isBST(struct node *root){
    static struct node *prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

struct node * search_recur(struct node *root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root; 
    }
    else if(root->data>key){
        search_recur(root->left,key);
    }
    else{
        search_recur(root->right,key);
    }
}

int main(){

    struct node *p = createNode(9);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(12);
    struct node *p3 = createNode(2);
    struct node *p4 = createNode(4);
    struct node *p5 = createNode(10);
    struct node *p6 = createNode(1);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p3->left = p6;

   
    if(isBST){
        printf("This is BST.\n");
    }
    else{
        printf("This is not a BST.\n");
    }
    printf("\n");
    struct node *n = search_recur(p,10);
    if(n!=NULL){
        printf("Element found (recursive method) : %d\n",n->data);
    }
    else{
        printf("Element not found\n");
    }
    printf("\n");

}