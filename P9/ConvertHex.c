#include <stdio.h>
#include <float.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>

int asciiHEXToInt(char *s);
int hexCharValue(char c);

int main(){
    char hex[33];
    while(1==1){
        printf ("Enter a hexadecimal number.\n");
        scanf("%s", hex);
        printf("Hexadecimal number has the decimal value of %d \n \n", asciiHEXToInt(hex));

    }
}

int asciiHEXToInt(char *s){
    int res = 0;
    for(int i=0; i<strlen(s); i++){
        long unsigned int exp = strlen(s)-i-1;
        if((s[i]>='0' && s[i]<='9') || (s[i]>='a'&&s[i]<='f') || (s[i]>='A' && s[i]<='F')){
             res = res + pow(16,exp) * hexCharValue(s[i]);
        }
       else{
           printf("Error: Invalid number \n");
           return res;
       }
    }
    return res;
}

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


