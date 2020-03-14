/*
    Victor Andres Villarreal
    A01039863
    13/03/2020

    Convert the sequence of hexadecimal numbers that the user inputs using the command line to the 
    corresponding decimals. User may input as many numbers as desired and any invalid number is 
    not converted and outputs an error message.

*/

#include <stdio.h>
#include <stdbool.h>
#include <float.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>

void asciiHEXToInt(char *s);
int hexCharValue(char c);

//main function
//inputs a string contianing an hexadecimal number to convert
int main(){
    char hex[33];
    while(1==1){
        printf ("Enter a hexadecimal number.\n");
        scanf("%s", hex);
        asciiHEXToInt(hex);
    }
}

//Function that receives a string representing an hexadecimal number and prints the decimal equivalent value
void asciiHEXToInt(char *s){
    bool valid = true;
    int res = 0;
    for(int i=0; i<strlen(s); i++){
        long unsigned int exp = strlen(s)-i-1;
        //while it is receiving a valid character
        if((s[i]>='0' && s[i]<='9') || (s[i]>='a'&&s[i]<='f') || (s[i]>='A' && s[i]<='F')){
             res = res + pow(16,exp) * hexCharValue(s[i]);
        }
       else{
           //if invalid character is received
           printf("Error: Invalid number \n \n");
           valid = false;
           return;
       }
    }
    //print converted value if the string was valid
    if(valid){
        printf("Hexadecimal number has the decimal value of %d \n \n", res);
    }
}


//converts a single char to its equivalent value from hexadecimal to decimal number
int hexCharValue(char c){
    if(c>'9'){
        if(c>='a'){
            return (int)(c - 'a' + 10);
        }
        else{
            return (int)(c - 'A' + 10);
        }
    }
    else{
        return (int)(c - '0');
    }
}


