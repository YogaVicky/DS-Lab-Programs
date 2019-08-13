#include<stdio.h>
int main(){
	int n , i , t , k , a[1000] , j , m;
    printf("Enter the number of elements\n");
	scanf("%d" , &n);
    printf("Enter the elements\n");
	for(i=0;i<n;i++){
		scanf("%d" , &a[i]);
	}
    for(i=1;i<n;i++){
        t = a[i];
        // for(j=i-1;j>=0;j--){
        //     if(t<a[j]){
        //         a[j+1]=a[j];
        //     }
        //     else
        //         break;
        // }
        // a[j+1] = t;
        int s , e , m;
        s = 0;
        e = i;
        while(s<e){
            m = (s+e)/2;
            if(t>a[m]){
                s = m + 1;
            }
            else{
                e = m - 1;
            }
        }
        printf("%d " , s);
        for(j=i;j>s;j--)
            a[j] = a[j-1];
        a[j] = t;
    }
    for(i=0;i<n;i++){
		printf("%d " , a[i]);
	}
    printf("\n");
	return 0;
}

// 1 4 7 8 5 2