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

    

/*

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	char val;
	struct node* left;
	struct node* right;
}node;

void countFrequencyOfLeafNodes(int freq[], node* root, int step);

int main(){
	
	node* root1 = malloc(sizeof(node));
	root1->val = '+';
	root1->left = malloc(sizeof(node));
	root1->right = malloc(sizeof(node));

	root1->left->val = 'a';
	root1->left->left = NULL;
	root1->left->right = NULL;

	root1->right->val = '+';

	root1->right->left = malloc(sizeof(node));
	root1->right->right = malloc(sizeof(node));

	root1->right->left->val = 'e';
	root1->right->right->val = 'd';

	node* root2 = malloc(sizeof(node));
	root2->val = '+';
	root2->left = malloc(sizeof(node));
	root2->right = malloc(sizeof(node));

	root2->right->val = 'a';
	root2->right->left = NULL;
	root2->right->right = NULL;

	root2->left->val = '+';

	root2->left->left = malloc(sizeof(node));
	root2->left->right = malloc(sizeof(node));

	root2->left->left->val = 'd';
	root2->left->right->val = 'e';
	int freq[150];

	for(int i = 0; i<150;i++){
		freq[i] = 0;
	}

	countFrequencyOfLeafNodes(freq, root1, 1);
//	for(int i = 0; i<150;i++){
//		printf("%d ", freq[i]);
//	}
//	printf("\n");
	countFrequencyOfLeafNodes(freq, root2, -1);
//	for(int i = 0; i<150;i++){
//		printf("%d ", freq[i]);
//	}
	int flag = 0;
	for(int i = 0; i<150;i++){
		if(freq[i] != 0){
			flag = 1;
			break;
		}
	}
	if(flag == 1){
		printf("The trees are not equivalent");
	}else{
		printf("The trees are equivalent");
	}
	return 0;
}

void countFrequencyOfLeafNodes(int freq[], node* root, int step){
	if(root == NULL){
		return;	
	}
	if(root->left == NULL && root->right == NULL){
		freq[root->val]+=step;
		return;
	}
	countFrequencyOfLeafNodes(freq, root->left, step);
	countFrequencyOfLeafNodes(freq, root->right, step);
}



*/


/*
#include<stdio.h>
#include<stdlib.h>

struct node{
	char key;
	struct node* left;
	struct node* right;
};

void frequencyOfLeafNodes(int freq[], struct node* root, int step){
	if(root == NULL){
		return;	
	}
	if(root->left == NULL && root->right == NULL){
		freq[root->key]+=step;
		return;
	}
	frequencyOfLeafNodes(freq, root->left, step);
	frequencyOfLeafNodes(freq, root->right, step);
}

int main(){
	
	struct node* root1 = malloc(sizeof(struct node));
	root1->key = '+';
	root1->left = malloc(sizeof(struct node));
	root1->right = malloc(sizeof(struct node));

	root1->left->key = 'a';
	root1->left->left = NULL;
	root1->left->right = NULL;

	root1->right->key = '+';

	root1->right->left = malloc(sizeof(struct node));
	root1->right->right = malloc(sizeof(struct node));

	root1->right->left->key = 'e';
	root1->right->right->key = 'd';

	struct node* root2 = malloc(sizeof(struct node));
	root2->key = '+';
	root2->left = malloc(sizeof(struct node));
	root2->right = malloc(sizeof(struct node));

	root2->right->key = 'a';
	root2->right->left = NULL;
	root2->right->right = NULL;

	root2->left->key = '+';

	root2->left->left = malloc(sizeof(struct node));
	root2->left->right = malloc(sizeof(struct node));

	root2->left->left->key = 'd';
	root2->left->right->key = 'e';
	
    
    int freq[150];

	for(int i = 0; i<150;i++){
		freq[i] = 0;
	}

	frequencyOfLeafNodes(freq, root1, 1);
//	for(int i = 0; i<150;i++){
//		printf("%d ", freq[i]);
//	}
//	printf("\n");
	frequencyOfLeafNodes(freq, root2, -1);
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
	return 0;
}

*/
