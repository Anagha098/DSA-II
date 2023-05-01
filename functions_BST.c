#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int val){
    struct node *n = (struct node *)malloc(sizeof(struct node ));
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return(n);
}

void insert(struct node *root, int key){
    struct node *prev = NULL;
    while(root!=NULL){
        prev = root;
        if(root->data==key){
            printf("%d is already present. Cannot be added.\n",key);
        }
        else if(root->data<key){
            root = root->right;
        }
        else{
            root = root->left;
        }
        struct node *new = createNode(key);
        if(prev->data<key){
            prev->right = new;
        }
        else{
            prev->left = new;
        }
    }

}

void search(struct node *root, int key){
    if(root==NULL) {
        printf("%d is not present in the BST.\n",key);
        return ;
    }
     if(root->data == key){
            printf("%d is present in the BST.\n",key);
	    return ;
      }
      if(root->data<key){
            search(root->right,key);
        }
       if(root->data>key){
            search(root->left,key);
        }
        
}

struct node *inOrderPredecessor(struct node *root){
    root = root->left;
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
} 

struct node *delete(struct node *root, int key){
    struct node *iPre;
    if(root==NULL){
        return NULL;
    }
    if (root->left==NULL && root->right==NULL){
        free(root);
    }
    if(key<root->data){
        root->left = delete(root->left,key);
    }
    else if(key>root->data){
        root->right = delete(root->right,key);
    }
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = delete(root->left,iPre->data);
    }
    return root;
}

/*
void removeNode(struct node *root, int val){
	if(root == NULL || root->root == NULL) return;
	node* tempRoot = rem(tree->root, val);
	tree->root = tempRoot;	
}

node* rem(node* root, int val){
	if(root->data == val){
		if(root->left == NULL){
			node* temp = root;
			root = root->right;
			free(temp);
			return root;
		}
		
		if(root->right == NULL){
			node* temp = root;
			root = root->left;
			free(temp);
			return root;
		}		
		int temp = replacement(root);
		root = rem(root, temp);
		root->data = temp;	
	}else if(root->data < val){
		root->right = rem(root->right, val);
	}else{
		root->left = rem(root->left,val);
	}
	return root;
}
*/

int descendants(struct node *root, int key){
    if(root==NULL){
        return 0;
    }
    int count = 0;
    if(root->data==key){
        if(root->left!=NULL){
            count++;
            root= root->left;
        }
        if(root->right!=NULL){
            count++;
            root= root->right;
        }
        //return count;
      
      printf("No of descendants are %d\n",count);
    }
    if(root->data<key){
        descendants(root->right,key);
    }
    if(root->data>key){
        descendants(root->left,key);
    }
}

void inOrder(struct node *root){
    if(root == NULL) return ;
     inOrder(root->left);
     printf("%d ",root->data);
     inOrder(root->right);
   
}

int main(){
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(9);
    struct node *p3 = createNode(2);
    struct node *p4 = createNode(4);
    struct node *p5 = createNode(6);
    struct node *p6 = createNode(1);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p3->left = p6;

    search(p,6);
    printf("\n");
    search(p,12);
    insert(p,8);
    inOrder(p);
    printf("\n");
    insert(p,10);
    printf("\n");
    inOrder(p);
   
    printf("\n");
    inOrder(p);
    printf("\n");
    descendants(p,4);
    //descendants(p,3);
    descendants(p,2);
    //descendants(p,1);
    //descendants(p,9);
    //descendants(p,6);
    //printf("%d\n",count);
    printf("\n");
    //descendants(p,5);
    printf("\n");
   // inOrder(p);
   // printf("\n");}
   delete(p,2);
   printf("/n");
   return 0;
   }
