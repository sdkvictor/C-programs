#include <stdio.h>
#include <float.h>

//Definición de la union
union data { 
    int iValue;
    double dValue;
    char string[100];
}u;

//Función principal
int main(){
    //Leer string
    printf ("Enter a string.\n");
    scanf("%s",u.string);
    //Mostrar tamaño del string
    printf ("Your string %s storage size is %lu bytes. \n", u.string, sizeof(u.string));

    //Leer integer
    printf ("Enter an integer.\n");
    scanf("%d",&u.iValue);
    //Mostrar tamaño del integer
    printf ("Your integer %d storage size is %lu bytes.\n", u.iValue, sizeof(u.iValue));

    //Leer double
    printf ("Enter a double.\n");
    scanf("%lf",&u.dValue);
    //Mostrar tamaño del double
    printf ("Your double %lf storage size is %lu bytes, I can read any number from %lf to %lf in this data type. \n", u.dValue, sizeof(u.dValue), DBL_MIN, DBL_MAX);

}
