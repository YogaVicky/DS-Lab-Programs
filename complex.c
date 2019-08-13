#include<stdio.h>
struct complex
{
    int a , b;
}x,y;
void add(){
    printf("The sum is %d + i%d\n" , x.a + y.a , x.b + y.b);
}
void subtract(){
    printf("The diff is %d + i%d\n" , x.a - y.a , x.b - y.b);
}
void multiply(){
    struct complex m;
    m.a = (x.a*y.a) - (x.b*y.b);
    m.b = (x.a*y.b) + (x.b*y.a);
    printf("The product is %d + i%d\n" , m.a , m.b);
}
void divide(){
    struct complex d;
    d.a = (x.a*y.a) - (x.b*y.b*-1);
    d.b = (x.a*y.b) + (x.a*y.b*-1);
    int den    = y.a*y.a + y.b*y.b;
    printf("The quotient is %d/%d + i%d/%d\n " , d.a , den , d.b , den);
}
int main(){
    int i;
    printf("Enter the real and imaginary part of the first complex number\n");
    scanf("%d%d" , &x.a , &x.b);
    printf("Enter the real and imaginary part of the second complex number\n");
    scanf("%d%d" , &y.a , &y.b);
    add();
    subtract();
    multiply();
    divide();
    return 0;
}