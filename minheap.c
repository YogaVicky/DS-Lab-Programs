#include<stdio.h>
#include<stdlib.h>
struct heap{
    int arr[50];
    int pro[50];
    int last1;
    int last2;
};
struct heap H;
void insert(int p,int pro);
int delete_arr();
int delete_pro(); 
int main(){
    int n , x , i;
    H.last1 = 0;
    H.last2 = 0;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Enter execution time for process %d\n",i);
        scanf("%d",&x);
        insert(x,i);
    }
    for(i=1;i<=H.last1;i++)
        printf("%d\n",H.arr[i]);
        printf("Minimum execution time = %d , process id = %d\n",delete_arr(),delete_pro());
        printf("Execution time in ascending order\n");
        while(H.last1!=0){
            printf("Execution time = %d\n",delete_arr());
        }
    return 0;
}
void insert(int p , int pro)
{
	H.last1++;
    H.last2++;
	H.arr[H.last1] = p;
    H.pro[H.last2] = pro;
	int t = H.last1;
	while((t/2 >= 1) && (H.arr[t] <= H.arr[t / 2]))
	{
		H.arr[t] = H.arr[t] ^ H.arr[t/2];
		H.arr[t/2] = H.arr[t] ^ H.arr[t/2];
		H.arr[t] = H.arr[t] ^ H.arr[t/2];
        H.pro[t] = H.pro[t] ^ H.pro[t/2];
		H.pro[t/2] = H.pro[t] ^ H.pro[t/2];
		H.pro[t] = H.pro[t] ^ H.pro[t/2];
		t /= 2;
	}
}
int delete_arr()
{
	int x = H.arr[1];
	H.arr[1] = H.arr[H.last1];
	H.last1--;
	int t = 1;
	int mi;
	while(2*t  <= H.last1)
	{
		if(H.last1 >= 2*t+1)
		{
			if(H.arr[2*t] < H.arr[2*t+1])
				mi = 2*t;
			else 
				mi = 2*t+1;
		}
		else 
			mi = 2*t;
		if(H.arr[t] > H.arr[mi])
		{
			H.arr[t] = H.arr[t] ^ H.arr[mi];
			H.arr[mi] = H.arr[t] ^ H.arr[mi];
			H.arr[t] = H.arr[t] ^ H.arr[mi];
			t = mi;
		}
		else break;
	}
	return x;
}
int delete_pro()
{
	int x = H.pro[1];
	H.pro[1] = H.pro[H.last2];
	H.last2--;
	int t = 1;
	int mi;
	while(2*t  <= H.last2)
	{
		if(H.last2 >= 2*t+1)
		{
			if(H.pro[2*t] < H.pro[2*t+1])
				mi = 2*t;
			else 
				mi = 2*t+1;
		}
		else 
			mi = 2*t;
		if(H.pro[t] > H.pro[mi])
		{
			H.pro[t] = H.pro[t] ^ H.pro[mi];
			H.pro[mi] = H.pro[t] ^ H.pro[mi];
			H.pro[t] = H.pro[t] ^ H.pro[mi];
			t = mi;
		}
		else break;
	}
	return x;
}
