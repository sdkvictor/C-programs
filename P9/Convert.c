#include <stdio.h>
#include <float.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>

int asciiBinaryToInt(char *s);
int asciiHEXToInt(char *s);
double asciiToDouble(char *s);
int hexCharValue(char c);

int main(){
    char binary[33];
    char hex[33];
    char floatNum[33];

    printf ("Enter a binary number.\n");
    scanf("%s", binary);
    printf("Binary number has the decimal value of %d \n \n", asciiBinaryToInt(binary));

    printf ("Enter a hexadecimal number.\n");
    scanf("%s", hex);
    printf("Hexadecimal number has the decimal value of %d \n \n", asciiHEXToInt(hex));

    printf ("Enter a float number.\n");
    scanf("%s", floatNum);
    printf("Float number has the value of %lf \n \n", asciiToDouble(floatNum));
}

double asciiToDouble(char *s){
    int c = 0;
    double sign = 1.0;
    double res = 0.0;
    //lee el primer caracter en caso de que sea + o - y modifica el signo
    if(s[c]=='+'||s[c]=='-'){
        if(s[c]=='+'){
            c++;
        }
        else{
            sign = -1.0;
            c++;
        }
    }

    //leer los numeros antes del punto decimal
    while(s[c]>='0' && s[c]<='9'){
        res = res*10.0 + (s[c]-'0');
        c++;
    }

    //saltar el punto decimal
    if(s[c]=='.'){
        c++;
    }

    //agregar los decimales
    double pow = 1.0;
    while(s[c]>='0' && s[c]<='9'){
        res = res + (s[c]-'0')/(10.0*pow);
        pow = pow * 10.0;
        c++;
    }

    return res * sign;
}


int asciiBinaryToInt(char *s){
    int res = 0;
    for(int i=0; i<strlen(s); i++){
        long unsigned int exp = strlen(s)-i-1;
        if(s[i]!='0' && s[i]!='1'){
            return res;
        }
        res = res + pow(2,exp) * (int)(s[i]-'0');
    }
    return res;
}

int asciiHEXToInt(char *s){
    int res = 0;
    for(int i=0; i<strlen(s); i++){
        long unsigned int exp = strlen(s)-i-1;
        if((s[i]>='0' && s[i]<='9') || (s[i]>='a'&&s[i]<='f') || (s[i]>='A' && s[i]<='F')){
             res = res + pow(16,exp) * hexCharValue(s[i]);
        }
       else{
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


