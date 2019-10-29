#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
node *front = NULL;
node *rear = NULL;
void enqueue(int data){
	node *temp = (node*)malloc(sizeof(struct node));
	temp->data = data;
	if(front == NULL){
		rear = temp;
		front = temp;
	}
	else{
		temp->next = NULL;
		rear->next = temp;
		rear = temp;
	}
}
int dequeue(){
	int x = front->data;
	if(rear == front)
		rear = front = NULL;
	else
		front = front->next;
	return x;
}
int visit[100] = {0} , n;
void bfs(int a[][100] , int v){
	cout<<"Inside bfs\n";
	int u , i;
	visit[1] = 1;
	cout<<"1"<<endl;
	enqueue(v);
	while(front!=NULL){
		u = dequeue();
		for(i=1;i<=n;i++){
			if(visit[i]==0 && a[u][i] == 1){
				cout<<i<<endl;
				visit[i] = 1;
				enqueue(i);
			}
		}
	}
	for(i=1;i<=n;i++)
		cout<<visit[i]<<" ";
	cout<<endl;
}
int main(){
	int g[100][100] = {0},ch,i,j;
	cout<<"Enter the number of elements of the graph\n";
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			cout<<"Are "<<i<<" and "<<j<<" connected?\n";
			cin>>ch;
			if(ch)
				g[i][j] = 1;
		}
	bfs(g , 1);
	return 0;
}
