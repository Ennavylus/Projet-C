#include <stdio.h>
#include <stdlib.h>

int chainSize(const char str[]){
    int c =0;
    while(str[c]!='\0'){
        c++;
    }
    return c;
}

void digitInverse(char str[], int size){
    int y = size-1;
    int t;
    for(int i = 0; i<y; i++){
        int t = str[i];
        str[i] = str[y];
        str[y] = t;
        y--;
    }
//spaceDelete(str);
}
/*
description : allows transforms number or letter char into number int with ASCII array
parameter   : char c : char to transforms
return      : the equivalent digit
*/
int charToInt(char c){
    if(c>47 && c<58){
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


void binary(char tab[], char tab2[], char result[]) {
    int tailleMax = chainSize(tab);
    if(chainSize(tab)<chainSize(tab2)) {
        tailleMax = chainSize(tab2);
        while(chainSize(tab)==chainSize(tab2)){
            addFisrt(tab,'0');
        }
    }
    else{
        while(chainSize(tab)==chainSize(tab2)){
            addFisrt(tab2,'0');
        }
    }
    digitInverse(tab,chainSize(tab));
    digitInverse(tab2,chainSize(tab2));
    result[1]= '\0';
    result[0]= ' ';
    printf("%d\n",tailleMax);
    int t =0;
    int maxsize =5;
    for(int i = 0;i<tailleMax;i++) {
        if(chainSize(result)== maxsize){
            addFisrt(result, ' ');
            maxsize+=5;
        }
        if (charToInt(tab[i])+charToInt(tab2[i])+t==0) {
            addFisrt(result,'0');
            t=0;
        }
        if (charToInt(tab[i])+charToInt(tab2[i])+t==2) {
            addFisrt(result,'0');
            t=1;
        }
        else if(charToInt(tab[i])+charToInt(tab2[i])+t==1) {
                addFisrt(result,'1');
                t=0;
        }
        else if(charToInt(tab[i])+charToInt(tab2[i])+t==3) {
                addFisrt(result,'1');
                t=1;
        }
    }
    if(t==1){
        addFisrt(result,'1');
    }
}


int main()
{
    char bin1[100] = "1101101";
    char bin2[100] = "1101";
    char result[100] = "";
    binary(bin1,bin2,result);


    printf("%s", result);
    return 0;
}
