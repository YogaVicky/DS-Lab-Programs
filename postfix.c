#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int s[50] = {0};
int l = -1;
void push(int a){
    l++;
    s[l] = a;
}
int pop(){
    int a = s[l];
    l--;
    return a;
}
int main(){
    char a[50];
    int i = 0 , res = 0 , n1 , n2;
    printf("Enter the expression\n");
    gets(a);
    while(a[i]!='\0'){
        if(a[i] > 47 && a[i] < 58){
            push(a[i] - 48);
        }
        else{
            switch(a[i]){
                case '+':
                    n1 = pop();
                    n2 = pop();
                    res = n1 + n2;
                    push(res);
                    break;
                case '-':
                    n1 = pop();
                    n2 = pop();
                    res = n2-n1;
                    push(res);
                    break;
                case '*':
                    n1 = pop();
                    n2 = pop();
                    res = n1*n2;
                    push(res);
                    break;
                case '/':
                    n1 = pop();
                    n2 = pop();
                    res = n2/n1;
                    push(res);
                    break;
            }
        }
        i++;
    }
    printf("The result is %d \n" , res);
    return 0;
}