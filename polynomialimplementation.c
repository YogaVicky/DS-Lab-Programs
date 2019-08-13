#include<stdio.h>
#include<math.h>
struct poly{
    int coeff[100];
    int size;
};
void insert(int temp , struct poly *pointer){
    int size = pointer->size;
    pointer->coeff[size] = temp;
    pointer->size++;    
}
void solve(struct poly *pointer , int x){
    int size = pointer->size;
    int res = 0 , i;
    for(i = 0;i < size;i++){
        res += pointer->coeff[i]*pow(x,size-i-1);
    }
    printf("The result is %d\n" , res);
}
int main(){
    struct poly *pointer , poly;
    pointer = &poly;
    int n , i , temp , x;
    pointer->size = 0;
    printf("Enter the degree of the polynomial\n");
    scanf("%d" , &n);
    n = n+1;
    printf("Enter the polynomial\n");
    while(n--){
        printf("Enter the coeff for degree %d\n" , n);
        scanf("%d" , &temp);
        insert(temp , pointer);
    }
    printf("Enter the value of the variable\n");
    scanf("%d" , &x);
    solve(pointer , x);
    return 0;
}