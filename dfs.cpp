#include<iostream>
using namespace std;
int visit[100] = {0} , n;
void bfs(int a[][100] , int v){
	int i;
	visit[v] = 1;
	cout<<v<<endl;
		for(i=1;i<=n;i++){
			if(visit[i]==0 && a[v][i] == 1)
				bfs(a , i);
		}
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
