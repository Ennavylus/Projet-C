#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100
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
description : allows to delete character in the potision to given in array
parameter   : int size : character element in array
            : char str[] : array to work
            : int pos : position to delete character
return      : delete character in the potision to given in array
*/
void deletePosElement(int size, char str[], int pos){
    for(int i = pos-1;i<size; i++){
        str[i] = str[i+1];
    }
}
/*
description : delete all space in array and transfer in new array
parameter   : char str[] : first string to compare
            : char strToTest : second string to compare
return      : the function delete all vowel and transfer in new array
*/
void spaceDelete(char str[]){
    for(int i = 0;i<chainSize(str);i++){
        if(str[i]==' '){
            deletePosElement(chainSize(str),str, i+1);
            i--;
        }
    }
}
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
description : allows to have the opposite of the all number in the array in the same array
             and delete all space character.
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
spaceDelete(str);
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
/*
description : allows to convert decimal number into decimal in a new string
parameter   : int number : number to converse
            : char dec[] : new string to recive convert
return      :
*/
void convertIntToDecimal(int number, char dec[]){
    dec[1]= '\0';
    dec[0]= ' ';
    int maxsize =4;
    while(number>0){
        if(chainSize(dec)== maxsize){
            addFisrt(dec, ' ');
            maxsize+=4;
        }
        int t = number%10;
        number /=10;
        addFisrt(dec, intToChar(t));
    }
}
/*
description : allows to convert decimal into binary  in a new string
parameter   : int number : number to converse
            : char bin[] : new string to recive convert
return      :
*/
void convertIntToBinary(int number, char bin[]){
    bin[1]= '\0';
    bin[0]= ' ';
    int maxsize =5;
    while(number>0){
        if(chainSize(bin)== maxsize){
            addFisrt(bin, ' ');
            maxsize+=5;
        }
        int t = number%2;
        number /=2;
        addFisrt(bin, intToChar(t));
    }
}
/*
description : allows to convert decimal into octal  in a new string
parameter   : int number : number to converse
            : char octa[] : new string to recive convert
return      :
*/
void convertIntToOctal(int number, char octal[]){
    octal[1]= '\0';
    octal[0]= ' ';
    int maxsize =4;
    while(number>0){
        if(chainSize(octal)== maxsize){
            addFisrt(octal, ' ');
            maxsize+=4;
        }
        int t = number%8;
        number /=8;
        addFisrt(octal, intToChar(t));
    }
}
/*
description : allows to convert decimal into hexadecimal  in a new string
parameter   : int number : number to converse
            : char hexa[] : new string to recive convert
return      :
*/
void convertIntToHexa(int number, char hexa[]){
    hexa[1]= '\0';
    hexa[0]= ' ';
    int r =number;
    int maxsize =5;
    while(number>0){
        if(chainSize(hexa)== maxsize){
            addFisrt(hexa, ' ');
            maxsize+=5;
        }
        int t = number%16;
        number /=16;
        addFisrt(hexa, intToChar(t));
    }
}
/*
description : allows to convert decimal number into integer numbers
parameter   : char deci[] : string deci to convert
return      : retruns integer numbers in base 10 of decimal string
*/
int convertDeciToInt(char deci[]){
    digitInverse(deci,chainSize(deci));
    int nbsomme = 0;
    for(int i = 0; i<chainSize(deci);i++){
        nbsomme += charToInt(deci[i])*power(10,i);
    }
    digitInverse(deci,chainSize(deci));
    return nbsomme;
}
/*
description : allows to convert Hexadecimal number into integer numbers
parameter   : char hexa[] : string hexa to convert
return      : retruns integer numbers in base 10 of hexadecimal string
*/
int convertHexaToInt(char hexa[]){
    digitInverse(hexa,chainSize(hexa));
    int nbsomme = 0;
    for(int i = 0; i<chainSize(hexa);i++){
        nbsomme += charToInt(hexa[i])*power(16,i);
    }
    digitInverse(hexa,chainSize(hexa));
    return nbsomme;
}
/*
description : allows to convert octal number into integer numbers
parameter   : char octa[] : string octa to convert
return      : retruns integer numbers in base 10 of octale string
*/
int convertOctalToInt(char octa[]){
    digitInverse(octa,chainSize(octa));
    int nbsomme = 0;
    for(int i = 0; i<chainSize(octa);i++){
        nbsomme += charToInt(octa[i])*power(8,i);
    }
    digitInverse(octa,chainSize(octa));
    return nbsomme;
}
/*
description : allows to convert binary number into integer numbers
parameter   : char bin[] : string bin to convert
return      : retruns integer numbers in base 10 of binary string
*/
int convertBinToInt(char bin[]){
    digitInverse(bin,chainSize(bin));
    int nbsomme = 0;
    int p = 0;
    for(int i = 0; i<chainSize(bin);i++){
        nbsomme += charToInt(bin[i])*power(2,i);
    }
    //digitInverse(bin,chainSize(bin));
    return nbsomme;
}
/*
description : check if string is binary by ignoring the space
parameter   : char str[] : string to check
return      : retruns 1 if check is good
*/
int binaryTest(char str[]){
    for(int i=0; i<chainSize(str); i++){
        if(str[i]==' '){
            for(int j=0;j<chainSize(str);j++){
                i++;
            }
        }
        if(charToInt(str[i])>=2){
            return 0;
        }
    }
    return 1;
}
/*
description : check if string is hexadecimal by ignoring the space
parameter   : char str[] : string to check
return      : retruns 1 if check is good
*/
int hexaTest(char str[]){
    for(int i=0; i<chainSize(str); i++){
        if(str[i]==' '){
            for(int j=0;j<chainSize(str);j++){
                i++;
            }
        }
        if(charToInt(str[i])>=16){
            return 0;
        }
    }
    return 1;
}
/*
description : check if string is octal by ignoring the space
parameter   : char str[] : string to check
return      : retruns 1 if check is good
*/
int octaTest(char str[]){
    for(int i=0; i<chainSize(str); i++){
        if(str[i]==' '){
            for(int j=0;j<chainSize(str);j++){
                i++;
            }
        }
        if(charToInt(str[i])>=8){
            return 0;
        }
    }
    return 1;
}
/*
description : check if string is decimal by ignoring the space
parameter   : char str[] : string to check
return      : retruns 1 if check is good
*/
int deciTest(char str[]){
    for(int i=0; i<chainSize(str); i++){
        if(str[i]==' '){
            for(int j=0;j<chainSize(str);j++){
                i++;
            }
        }
        if(charToInt(str[i])>=10){
            return 0;
        }
    }
    return 1;
}
/*
description : allows to print menu of number base
parameter   :-------
return      : print all the base number possibilities
*/
void whatBaseDoYouWant(){
    printf("1. Base decimale(base 10)\n");
    printf("2. base Binaire (base 2)\n");
    printf("3. Base Octale (base 8)\n");
    printf("4. Base Hexadecimal (base 16)\n");
}
/*
description : allows to print header of programs
parameter   : ----
return      : Print in console header
*/
void header(){
    system("cls");
    printf("       ____________________________\n");
    printf("      /                           / \n");
    printf("     /         Projet C          /\n");
    printf("    /     Le Convertisseur      / \n");
    printf("   /___________________________/ \n\n\n\n");
    printf("\n");
}
/*
description : allows to display according to the chosen base
parameter   : char choice : to define the chosen base
            : char newStrPrint[] : rewrite in the new string the number with the
              right space between the numbers
            : int number : the number given previously convert in interger type
return      : display the number with the chosen base
*/
void viewNumberChoice(char choice, char newStrPrint[],int number){
    printf("Le nombre ");
    switch(choice){
        case '1': printf("decimale");
            convertIntToDecimal(number, newStrPrint);
            break;
        case '2': printf("binaire");
            convertIntToBinary(number, newStrPrint);
            break;
        case '3': printf("octal");
            convertIntToOctal(number, newStrPrint);
            break;
        case '4': printf("Hexadecimal");
            convertIntToHexa(number, newStrPrint);
            break;
    }
    printf(" a convertir est %s\n\n",newStrPrint);
}
/*
description : allows to display according to the chosen base
parameter   : int number : the given number converted to decimal
            : char newStr[]: array destination for conversion
            : char choice : retrieve the previous menu choice
            : char str[] : the number given above
return      : display a sub menu to choose the conversion and display result with newStr
*/
void choiceToConvert( char strPrint[], int number, char newStr[], char choice){
    char choice2 = 'y';
    char t = 'y';
    while(choice2 !='n'){
        t = 'y';
        while((t >'6')||(t<'1')){
            header();
            viewNumberChoice(choice,strPrint,number);
            printf("Dans quelle base souhaitez vous convertir votre nombre? \n");
            whatBaseDoYouWant();
            printf("5. convertir dans toute les base\n\n");
            printf("6. Annuler / Retour\n\n");
            t = getch();
        }
        if(t=='6'){
            break;
        }
        switch (t){
            case '1' : header();
                viewNumberChoice(choice,strPrint, number);
                convertIntToDecimal(number, newStr);
                printf("En nombre decimal il correspond a : %s\n\n",newStr);
                printf("Souhaitez reconvertir le meme nombre de base? y/n\n");
                choice2 = getch();
                break;
            case '2' : header();
                viewNumberChoice(choice,strPrint, number);
                convertIntToBinary(number, newStr);
                printf("En nombre Binaire il correspond a : %s\n\n",newStr);
                printf("Souhaitez reconvertir le meme nombre de base? y/n\n");
                choice2 = getch();
                break;
            case '3' : header();
                viewNumberChoice(choice,strPrint, number);
                convertIntToOctal(number, newStr);
                printf("En nombre Octal il correspond a  : %s\n\n",newStr);
                printf("Souhaitez reconvertir le meme nombre de base? y/n\n");
                choice2 = getch();
                break;
            case '4' : header();
                viewNumberChoice(choice,strPrint, number);
                convertIntToHexa(number, newStr);
                printf("En Nombre Hexadecimal il correspond a : %s\n\n",newStr);
                printf("Souhaitez reconvertir le meme nombre de base? y/n\n");
                choice2 = getch();
                break;
            case '5' : header();
                viewNumberChoice(choice,strPrint, number);
                convertIntToDecimal(number, newStr);
                printf("Nombre decimal : %s\n",newStr);
                convertIntToBinary(number, newStr);
                printf("Nombre Binaire : %s\n",newStr);
                convertIntToOctal(number, newStr);
                printf("Nombre Octal : %s\n",newStr);
                convertIntToHexa(number, newStr);
                printf("Nombre Hexadecimal : %s\n",newStr);
                choice2 = 'n';
                break;
        }
    }
}

int main()
{
    char choice = 'y';
    char menu = 'n';
    char strBase[N] = "";
    char strResult[N]= "";
    char strPrint[N]= "";


    while(choice !='n'){
        menu = 'n';
        choice = 'y';
        while((choice >'4')||(choice<'0')){
            header();
            printf("Bienvenue dans le menu principale du convertisseur.\n\n");
            printf("Sur quelle base numerique souhaitez vous effectuer une convertion?\n");
            whatBaseDoYouWant();
            printf("0. Quitter le programme\n");
            choice = getch();
        }
        switch(choice){
            case '1': do{
                        header();
                        printf("----------- Nombre Decimale ---------\n\n");
                        printf("Veuillez entrer le nombre decimale : ");
                        scanf(" %[^\n]s ",strBase);
                        if(!deciTest(strBase)){
                            printf("\nLe nombre saisie n'est pas un nombre decimal.\n");
                            printf("Souhaitez vous changer de base numerique? y/n \n");
                            menu = getch();
                            if(menu== 'y'){
                                break;
                            }
                        }
                    }while(!deciTest(strBase));
                    if(menu== 'y'){
                        break;
                    }
                    choiceToConvert(strPrint,convertDeciToInt(strBase),strResult,choice);
                break;
            case '2': do{
                        header();
                        printf("----------- Nombre Binaire ---------\n\n");
                        printf("Veuillez entrer le nombre Binaire : ");
                        scanf(" %[^\n]s ",strBase);
                        if(!binaryTest(strBase)){
                            printf("\nLe nombre saisie n'est pas un nombre binaire.\n");
                            printf("Souhaitez vous changer de base numerique? y/n \n");
                            menu = getch();
                            if(menu== 'y'){
                                break;
                            }
                        }
                    }while(!binaryTest(strBase));
                    if(menu== 'y'){
                        break;
                    }
                    choiceToConvert(strPrint,convertBinToInt(strBase),strResult,choice);
                break;
            case '3': do{
                        header();
                        printf("----------- Nombre Octal ---------\n\n");
                        printf("Veuillez entrer le nombre Octal : ");
                        scanf(" %[^\n]s",strBase);
                        if(!octaTest(strBase)){
                            printf("\nLe nombre saisie n'est pas un nombre octal.\n");
                            printf("Souhaitez vous changer de base numerique? y/n \n");
                            menu = getch();
                            if(menu== 'y'){
                                break;
                            }
                        }
                    }while(!octaTest(strBase));
                    if(menu== 'y'){
                        break;
                    }
                    choiceToConvert(strPrint,convertOctalToInt(strBase),strResult,choice);
                break;
            case '4': do{
                        header();
                        printf("----------- Nombre Hexadecimal ---------\n\n");
                        printf("Veuillez entrer le nombre Hexadecimal : ");
                        scanf(" %[^\n]s",strBase);
                        if(!hexaTest(strBase)){
                            printf("\nLe nombre saisie n'est pas un nombre hexadecimal.\n");
                            printf("Souhaitez vous changer de base numerique? y/n \n");
                            menu = getch();
                            if(menu== 'y'){
                                break;
                            }
                        }
                    }while(!hexaTest(strBase));
                    if(menu== 'y'){
                        break;
                    }
                    choiceToConvert(strPrint,convertHexaToInt(strBase),strResult,choice);
                break;
            case '0': printf("\n\nMerci d'avoir utiliser mon convertisseur\n\n");
            system("pause");
                     return 0;
        }
        printf("\n\n");
        if(menu != 'y'){
            printf("Souhaitez vous retourner au menu principal y/n \n");
            choice = getch();
            //if(choice== 'n'){
            //    break;
            //}
        }


    }
    printf("\n\nMerci d'avoir utiliser mon convertisseur\n\n");
    system("pause");
    return 0;
}


