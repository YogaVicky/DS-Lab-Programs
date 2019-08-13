#include<stdio.h>
void bubblesort( char a[] , int n)
{
	int i , j;
	char temp;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;	
			}
		}
	printf("The sorted elements\n");
	for(i=0;i<n;i++)
		printf("%c ", a[i]);
	printf("\n");
}

void binarysearch( char a[100] , int n , char s)
{
	int beg = 0 , end = n-1 , check = 0 , mid;
	while(beg<=end)
	{
		mid = (beg + end)/2;
		if(a[mid] == s)
		{
			check = 1;
			break;
		}
		else if(a[mid] < s)
			beg = mid + 1;
		else
			end = mid - 1;
	}
	if(check ==1)
		printf("The searched element is present at %d\n" , mid + 1);
	else
		printf("The searched element is not present anywhere\n");
}

int main()
{
	char a[100] , b , s;
	int n , i;
	printf("Enter the number of elements\n");
	scanf("%d" , &n);
	getchar();
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
		scanf(" %c" , &a[i]);
	bubblesort(a , n);
	printf("Enter the element to be searched\n");
	scanf(" %c" , &s);
	binarysearch(a , n , s); 	
	return 0;
}

