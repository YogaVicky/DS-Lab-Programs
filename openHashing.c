#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *h[10] = {NULL};
void insert(int x , int b){
    struct node *head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(h[b] == NULL){
        temp->data = x;
        temp->next = h[b];
        h[b] = temp;
        printf("Inserted1\n");
    }
    else{
        struct node *last = h[b];
        while(last->next!=NULL){
            last = last->next;
        }
        temp->data = x;
        temp->next = last->next;
        last->next = temp;
        printf("Inserted2\n");
    }
}
void deletenode(int x , int b){
    int ch = 0;
    if(h[b]==NULL)
        printf("The key is empty\n");
    else{    
        struct node *last = h[b];
        if(h[b]->data == x){
            h[b] = h[b]->next;
            printf("Deleted\n");
            ch++;    
        }
        else{
            while(last->next!=NULL){
                if((last->next)->data == x){
                    last->next = (last->next)->next;
                    ch++;
                    break;
                }
                last = last->next;
            }
        }
        if(ch==0)
            printf("Data not found\n");
    }
}
void search(int x , struct node *h){
    int ch = 0,  ch1 = 0;
    if(h==NULL)
        printf("The key is empty\n");
    else{    
        struct node *last = h;
        if(last->data == x){
            printf("The data is found at pos 0\n");
            ch++;
        }
        else{
            while(last->next!=NULL){
                ch1++;
                if((last->next)->data == x){
                    printf("The data is found at pos %d\n" , ch1);
                    ch++;
                    break;
                }
                last = last->next;
            }
        }
        if(ch==0)
            printf("Data not found\n");
    }
}
void printlist(struct node *h){
    struct node *temp = h;
    if(temp == NULL)
        printf("NULL");
    while(temp!=NULL){
        printf("%d -- " , temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void inserthash(int a){
    int b = a%10;
    printf("Key - %d ",b);
    insert(a , b);
}
void deletehash(int a){
    int b = a%10;
    deletenode(a , b);   
}
void searchhash(int a){
    int b = a%10;
    search(a , h[b]);
}
int main(){
    int ch = 1 , a , i;
    while(ch){
        printf("Enter your choice\n");
        printf("1.Insert\n2.Delete\n3.Search\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the number\n");
            scanf("%d",&a);
            inserthash(a);
            for(i=0;i<10;i++)
               printlist(h[i]); 
            break;
        case 2:
            printf("Enter the number\n");
            scanf("%d",&a);
            deletehash(a);
            for(i=0;i<10;i++)
               printlist(h[i]);
            break;
        case 3:
            printf("Enter the number\n");
            scanf("%d",&a);
            searchhash(a);
            break;
        }
    }
    return 0;
}
