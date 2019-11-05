#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;	
};
struct node* insert(struct node *root , int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	if(root == NULL){
		root = temp;
		root->left = NULL;
		root->left = NULL;
	}
	else if(data <= root->data){
		root->left = insert(root->left,data);		
	}
	else{
		root->right = insert(root->right,data);			
	}
	return root;
}
int max(int l , int r){
    if(l>r)
        return l;
    else
        return r;
}
int findHeight(struct node *root){
	if(root == NULL)
		return -1;
	return max(findHeight(root->left) , findHeight(root->right)) + 1;	
}
int totalleaves(struct node *root){
    if(root == NULL)
        return 0;
    else if(root->left == NULL && root->right == NULL)
        return 1;
    else 
        return totalleaves(root->left) + totalleaves(root->right);
}
int findnodes(struct node *root , int l){
    while(l--){
        if(root == NULL)
            return 0;
        return findnodes(root->left , l) + findnodes(root->right , l);
    }
    if(root!= NULL)
        return 1;
}
int main(){
	struct node *root = NULL;
	int num , c , n = 1 , l;
    while(n){
        printf("1.Insert\n2.Height of the tree\n3.Total number of nodes\n");
        scanf("%d" , &c);
        switch(c){
            case 1:
                printf("Enter a number to be inserted\n");
                scanf("%d",&num);
                root = insert(root,num);
                break;
            case 2:
                printf("The height of the tree is %d\n" , findHeight(root));
                break;
            case 3:
                printf("Enter the level\n");
                scanf("%d" , &l);
                printf("The total number of nodes is %d\n" , findnodes(root , l));
                break;
        }
        printf("Continue?\n");
        scanf("%d" , &n);
    }
}
