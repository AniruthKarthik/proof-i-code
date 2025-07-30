#include <ctype.h>
#include <stdio.h>
#include <string.h>

int factorial(int n){
    if (n==1 || n==0) return 1;
    return (n*factorial(n-1));
}

int main(){

    printf("enter a word\n");
    char str[100]="";
    scanf("%s",str);
    char* stptr=str;
    char* endptr=&str[strlen(str)-1];
    while (stptr<endptr) {
        if(tolower(*stptr)!=tolower(*endptr)){
            printf("not a palindrome");
            return 0;
        }
            stptr++;
            endptr--;
    
    }
    printf("palindrome");





    return 0;
}
