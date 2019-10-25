#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
description :
parameter   :
return      :
*/
/*
description : Calculate the number with the power to give
parameter   : int a : number to calculate
            : int b : power to affect
retour      : Return result of 'a' power 'b'
*/
int power(int a, int b){
    int r = 1;
    for(int i = 0;i<b;i++){
        r *=a;
    }
    return r;
}

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
            : char bin[] : new string to recive convert
return      :
*/
void convertDecimalToBinary(int number, char bin[]){
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
            : char octa[] : new string to recive convert
return      :
*/
void convertDecimalToOctal(int number, char octal[]){
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
            : char hexa[] : new string to recive convert
return      :
*/
void convertDecimalToHexa(int number, char hexa[]){
    int r =number;
    while(r>0){
        int t = r%16;
        r /=16;
        addFisrt(hexa, intToChar(t));
    }
}
/*
description : allows to convert Hexadecimal number into Decimal
parameter   : char hexa[] : string hexa to convert
return      : retruns decimal number in base 10 of hexadecimal string
*/
int convertHexaToDecimal(char hexa[]){
    digitInverse(hexa,chainSize(hexa));
    int nbsomme = 0;
    for(int i = 0; i<chainSize(hexa);i++){
        nbsomme += charToInt(hexa[i])*(int)pow(16,i);
    }
    digitInverse(hexa,chainSize(hexa));
    return nbsomme;
}
/*
description : allows to convert octal number into Decimal
parameter   : char octa[] : string octa to convert
return      : retruns decimal number in base 10 of octale string
*/
int convertOctalToDecimal(char octa[]){
    digitInverse(octa,chainSize(octa));
    int nbsomme = 0;
    for(int i = 0; i<chainSize(octa);i++){
        nbsomme += charToInt(octa[i])*(int)pow(8,i);
    }
    digitInverse(octa,chainSize(octa));
    return nbsomme;
}
/*
description : allows to convert binary number into Decimal
parameter   : char bin[] : string bin to convert
return      : retruns decimal number in base 10 of binary string
*/
int convertBinToDecimal(char bin[]){
    digitInverse(bin,chainSize(bin));
    int nbsomme = 0;
    for(int i = 0; i<chainSize(bin);i++){
        nbsomme += charToInt(bin[i])*(int)pow(2,i);
    }
    digitInverse(bin,chainSize(bin));
    return nbsomme;
}


int main()
{
    char test[] = "10011011";
    char test2[]= "";
    //digitInverse(test, chainSize(test));
   // printf(" %d est egale a %c", test1, intToChar(test1));
   convertDecimalToHexa(convertBinToDecimal(test),test2);
  //  printf("%d\n",convertHexaToDecimal(test));

//    for(int i=0;i<chainSize(test);i++){
//
//        printf("%d   ", charToInt(test[i]));
//    }
   // printf("%s\n",test );
    printf("%s\n", test2);

    return 0;
}
