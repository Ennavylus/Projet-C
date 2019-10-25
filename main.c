#include <stdio.h>
#include <stdlib.h>
/*
description :
parameter   :
return      :
*/
/*
description : determinate size of character chain
parameter   : cont char str[] : chain of character
return      : number of character in this chain
*/
int chainSize(const char str[]){
    int c =0;
    while(str[c]!='\0'){
        c++;
    }
    return c;
}
/*
description : allows to have the opposite of the all number in the array in the same array
parameter   : int size : to define size of Array
            : int str[]: point on the Array to work
return      : return opposite of all the numbers in the array in the same array
*/
void digitInverse(char str[], int size){
    int y = size-1;
    int t;
    for(int i = 0; i<y; i++){
            int t = str[i];
            str[i] = str[y];
            str[y] = t;
            y--;
    }
}


int main()
{
    char test[] = "12345";
    digitInverse(test, chainSize(test));
    printf("%s\n", test);
    return 0;
}
