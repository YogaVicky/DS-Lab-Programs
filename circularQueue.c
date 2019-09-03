#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(){
    int data;
    printf("Enter the data\n");
    scanf("%d" , &data);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    if(front==NULL){
        front = temp;
        rear = temp;
        temp->next = front;
    }    
    else{
        rear->next = temp;
        rear = temp;
        temp->next = front;
    }
}
void dequeue(){
    if(front == NULL)
        printf("Queue is empty\n");
    else if(front == rear){
        front = NULL;
        rear = NULL;
    }
    else{
        rear->next = front->next;
        front = front->next;
    }
    printf("\n");
}
void printqueue(){
    struct node *tfront = front;
    if(tfront == NULL)
        printf("Queue is empty\n");
    else{
        while(tfront != rear){
            printf("%d " , tfront->data);
            tfront = tfront->next;
        }
        printf("%d\n" , tfront->data);     
    }
}
int main(){
    int n  , c = 1;
    while(c)
    {
        printf("Enter your choice\n1.Enqueue\n2.Dequeue\n3.PrintQueue\n");
        scanf("%d" , &n);
        switch(n){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printqueue();
        }
    printf("Do u want to continue\n");
    scanf("%d" , &c);
    }
    return 0;
}