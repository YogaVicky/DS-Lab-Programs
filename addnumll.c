#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node *next;
}; 
struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *head3 = NULL;
void insert(int x , struct node *h){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(h == NULL){
        temp->data = x;
        temp->next = h;
        h = temp;
    }
    else{
        struct node *last = h;
        while(last->next!=NULL){
            last = last->next;
        }
        temp->data = x;
        temp->next = last->next;
        last->next = temp;
    }
}
void add(struct node *h1 , struct node *h2){
    
}
void printlist(struct node *h){
    struct node *temp = h;
    while(temp!=NULL){
        printf("%d -- " , temp->data);
        temp = temp->next;
    }
}
int main(){
    int i , l1 , l2;
    char a[100];
    printf("Enter the first number\n");
    gets(a);
    for(l1=0;a[l]!='\0';l1++);
    for(i=l1-1;l1>=0;l1--){
        insert(a[i] - 48 , head1);
    }
    printf("Enter the second number\n");
    gets(a);
    for(l2=0;a[l2]!='\0';l2++);
    for(i=l2-1;l2>=0;l--){
        insert(a[i] - 48 , head2);
    }    
    printf("\n");
    if(l1>l2)
        add(head1 , head2);
    else
        add(head2 , head1);
    printlist(head3);
    return 0;
}