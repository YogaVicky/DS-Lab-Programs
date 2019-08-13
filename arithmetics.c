#include<stdio.h>
int main(){
    int i , a , b , q , p , min , gcd;
    printf("Enter the p and q of the rational number\n");
    scanf("%d%d" , &p , &q);
    if(p<q)
        min = p;
    else
        min = q;
    for(i=2;i<=min;i++){
        if(p%i == 0 && q%i == 0)
            gcd = i;
    }
    printf("The rational number is %d/%d\n" , p/gcd , q/gcd);
    return 0;
}