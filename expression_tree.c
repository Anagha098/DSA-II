#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node {
    char data;
    struct node *left;
    struct node *right;
};

struct node *createNode(char data){
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return(n);
}



void frequencyOfLeafNodes(int freq[], struct node* root, int step){
	if(root == NULL){
		return;	
	}
	if(root->left == NULL && root->right == NULL){
		freq[root->data]+=step;
		return;
	}
	frequencyOfLeafNodes(freq, root->left, step);
	frequencyOfLeafNodes(freq, root->right, step);
}


int main(){

    struct node *p = createNode('+');
    struct node *p1 = createNode('a');
    struct node *p2 = createNode('b');

    struct node *q = createNode('+');
    struct node *q1 = createNode('b');
    struct node *q2 = createNode('a');

    struct node *s = createNode('+');
    struct node *s1 = createNode('a');
    struct node *s2 = createNode('+');
    struct node *s3 = createNode('c');
    struct node *s4 = createNode('e');

    struct node *t = createNode('+');
    struct node *t1 = createNode('+');
    struct node *t2 = createNode('e');
    struct node *t3 = createNode('a');
    struct node *t4 = createNode('c');

    p->left = p1;
    p->right = p2;
    q->left = q1;
    q->right = q2;

    s->left = s1;
    s->right = s2;
    s2->left = s3;
    s2->right = s4;

    t->left = t1;
    t->right = t2;
    t1->left = t3;
    t1->right = t4;


     int freq[150];

	for(int i = 0; i<150;i++){
		freq[i] = 0;
	}

	frequencyOfLeafNodes(freq, p, 1);
//	for(int i = 0; i<150;i++){
//		printf("%d ", freq[i]);
//	}
//	printf("\n");
	frequencyOfLeafNodes(freq, q, -1);
//	for(int i = 0; i<150;i++){
//		printf("%d ", freq[i]);
//	}

    
	int x = 0;
	for(int i = 0; i<150;i++){
		if(freq[i] != 0){
			x = 1;
			break;
		}
	}
	if(x == 1){
		printf("The trees are not equivalent");
	}else{
		printf("The trees are equivalent");
	}

    frequencyOfLeafNodes(freq, s, 1);
    frequencyOfLeafNodes(freq, t, -1);

    printf("\n");

	int y = 0;
	for(int i = 0; i<150;i++){
		if(freq[i] != 0){
			y = 1;
			break;
		}
	}
	if(y == 1){
		printf("The trees are not equivalent");
	}else{
		printf("The trees are equivalent");
	}

    return 0;
}

    

