#include <stdio.h>


int map[50];
int ch = 0;
char string[10];
int i = 0;
int j = 0;
int k = 0;
int temp = 0;
int count[10];

int main()
{
    printf("\nenter a string:");
    scanf("%s",string);

    for(i = 0; string[i] != '\0'; i++){
        ch = string[i] - 'a';
        map[ch]++;
    }
    
    int j = 0;
    for(i = 0; i < 26; i++){
       printf("\ncount of %c :%d",i+'a',map[i]);
        if(map[i] != 0){
            count[j] = map[i];
            j++;
        }
    }

    //sort using bubble
    for(i = 0; i < j; i++){
        for(k = 0; k < j-i-1; k++){
            if (count[k] > count[k+1]){
                temp = count[k];
                count[k] = count[k+1];
                count[k+1] = temp;
            }
        }
    }
    
    printf("\n");
    //print the sorted count;
    for(i = 0; i < j; i++){
        printf("%d ",count[i]);
    }

    //check fibonacci
    for(i = 0; i < j-2; i++){
        if(count[i] + count[i+1] != count[i+2]){
            printf("\nNOT\n");
            return 0;
        }
    }

    printf("\nDynamic\n");

    return 0;
}