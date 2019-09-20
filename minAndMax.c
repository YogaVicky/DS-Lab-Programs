#include<stdio.h>
#include<stdlib.h>
struct node
{
struct node* lptr;
struct node* rptr;
int  data;
};
int a[100];int i=0;
struct node *tptr=NULL;

void insert(int x)
{
struct node* temp=(struct node*)malloc(sizeof(struct node));
temp->data=x;
temp->lptr=temp->rptr=NULL;
if(tptr==NULL)
tptr=temp;
else
{
struct node* ptr=tptr;
struct node* pptr=NULL;
while(ptr!=NULL)
{
pptr=ptr;
if(x<ptr->data)
ptr=ptr->lptr;
else
ptr=ptr->rptr;
}
if(x<pptr->data)
pptr->lptr=temp;
else
pptr->rptr=temp;
}
}
void display(struct node* ptr)
{
if(ptr!=NULL)
{
display(ptr->lptr);
printf("%d    ",ptr->data);
display(ptr->rptr);
}}
void displa(struct node* ptr)
{
if(ptr!=NULL)
{
displa(ptr->lptr);
a[i]=ptr->data;i++;
displa(ptr->rptr);
}
}
int main()
{int c=1;int p;
while(c)
{
printf("Enter the value to be inserted\n");
scanf("%d",&p);
insert(p);
printf("Continue\n");
scanf("%d",&c);
}
// display(tptr);
// displa(tptr);
printf("\nMin= %d\n",a[0]);
printf("Second min= %d\n",a[1]);
printf("Max= %d\n",a[i-1]);
printf("Second Max= %d\n",a[i-2]);
return 0;
}

