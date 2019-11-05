#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char a[50];
    char b[50];
    struct node *left;
    struct node *right;
    int height;
};
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
struct node *RotateRight(struct node *root)
{
	struct node *xroot = root;
	struct node *yroot = root->left;
	xroot->left = yroot->right;
	yroot->right = xroot;
    xroot->height=findHeight(xroot);
    yroot->height=findHeight(yroot);
	return yroot;
}
struct node *RotateLeft(struct node *root) 
{
	struct node *xroot = root;
	struct node *yroot = root->right;
	xroot->right = yroot->left;
	yroot->left = xroot;
    xroot->height=findHeight(xroot);
    yroot->height=findHeight(yroot);
	return yroot;
}
struct node *RotateRightLeft(struct node *root)
{
	root->right = RotateRight(root->right);
	return RotateLeft(root);
}
struct node *RotateLeftRight(struct node *root)
{
	root->left = RotateLeft(root->left);
	return RotateRight(root);
}
struct node *search(struct node *root , char a[50]){
    if(root==NULL)
        printf("The  word is not found\n");
    else if(strcmp(root->a,a)==0)
        printf("The meaning is %s\n" , root->b);
    else if(strcmp(a,root->a)<0){
        root = search(root->left,a);          
    }
    else{
        root = search(root->right,a);
    }
    return root;    
}
struct node *insert(struct node *root , char a[50] , char b[50]){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->a,a);
    strcpy(temp->b,b);
    temp->height = 0;
    if(root == NULL)
        root = temp;
    else if(strcmp(a,root->a)<0){
		root->left = insert(root->left,a,b);		
	}
	else{
		root->right = insert(root->right,a,b);			
	}
    root->height = findHeight(root);
    if((findHeight(root->left) - findHeight(root->right) == 2)||(findHeight(root->left) - findHeight(root->right) == -2 )){
        if(strcmp(a,root->a)<0){
				if(strcmp(a,root->left->a)<0)
					root = RotateRight(root);
                else
                    root = RotateLeftRight(root); 
			}
			else{
                if(strcmp(a,root->right->a)<0)
					root = RotateRightLeft(root);
                else
                    root = RotateLeft(root);
			}
    }
	return root;
}
struct node *root = NULL;
int main(){
    int i = 1 , n;
    char a[50] , b[50];
    while(i){
        printf("Enter your choice\n1.Insert\n2.Search\n");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("Enter the word to inserted\n");
                scanf("%s",a);
                printf("Enter the meaning\n");
                scanf("%s",b);
                root = insert(root,a,b);
            break;
            case 2:
                printf("Enter the word to be searched\n");
                scanf("%s",a);
                root = search(root,a);
            break;
        }
    }
    return 0;
}
