/*
Enter a number.The program returns the smallest plaindrome which is greater than the give number
*/

#include <stdio.h>

int K = 0;   //MAX 1000000
int T = 1; 
int num = 0;
int found = 0;
int rev = 0;

int palindrome(int n);

int main()
{
    printf("\nenter the no of tests:");
    scanf("%d",&T);

    while(T){
        rev = 0;
        found = -1;
        printf("\nenter a number:");
        scanf("%d",&K);
        
        while(found != 1){
            K++;
            found = palindrome(K);
        }
        printf("\nNext Palindrome: %d",rev);
        --T;
    }
    
    return 0;
}

int palindrome(int n)
{
    rev = 0;
    int num = n;
    int d = 0;
    int digits[10];
    int no_of_digits = 0;

    while(n > 0){
        d = n % 10;
        rev = rev * 10 + d;
        n = n / 10;
    }
    if(rev == num)
        return 1;
    else
        return -1;   //NOT PALINDROME
   
}