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
parameter   : int str[]: point on the Array to work
            : int size : to define size of Array
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
/*
description : allows transforms number or letter char into number int with ASCII array
parameter   : char c : char to transforms
return      : the equivalent digit
*/
int charToInt(char c){
    if(c>47 && c<57){
        return c-= 48;
    }
    else if(c>64 && c<71){
        return c-= 55;
    }
    else if(c>96 && c<103){
        return c-= 87;
    }
}
/*
description : allows transforms number int into letter or number char with ASCII array
parameter   : int c : int to transforms
return      : the equivalent char type
*/
char intToChar(int c){
    if(c>=0 && c<10){
        return c+= 48;
    }
    else if(c>9 && c<16){
        return c+= 55;
    }
}
/*
description : allows  to add Element in first place in array
parameter   : char tab[] : array to work
            : int nbToAdd : number to add
return      : add nbToAdd in first place in array
*/
void addFisrt(char str[], char Add){
    char t=str[0];
    for(int i = 0;i<=chainSize(str); i++){
        char f = str[i+1];
        str[i+1] = t;
        t = f;
    }
    str[0] = Add;
}
/*
description : allows to convert decimal into binary  in a new string
parameter   : int number : number to converse
return      :
*/
void convertDicimalToBinary(int number, char bin[]){
      int r =number;
        while(r>0){
        int t = r%2;
        r /=2;
        addFisrt(bin, intToChar(t));
 }
}
/*
description : allows to convert decimal into octal  in a new string
parameter   : int number : number to converse
return      :
*/
void convertDicimalToOctal(int number, char octal[]){
      int r =number;
        while(r>0){
        int t = r%8;
        r /=8;
        addFisrt(octal, intToChar(t));
 }
}
/*
description : allows to convert decimal into hexadecimal  in a new string
parameter   : int number : number to converse
return      :
*/
void convertDicimalToHexa(int number, char hexa[]){
      int r =number;
        while(r>0){
        int t = r%16;
        r /=16;
        addFisrt(hexa, intToChar(t));
 }
}


int main()
{
    char test[] = "";
    int test1= 19358;
    //digitInverse(test, chainSize(test));
   // printf(" %d est egale a %c", test1, intToChar(test1));
   convertDicimalToBinary(test1,test);
   printf("%s\n",test);
//    for(int i=0;i<chainSize(test);i++){
//
//        printf("%d   ", charToInt(test[i]));
//    }

    return 0;
}
