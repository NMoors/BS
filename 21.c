//Uebung 2 
//Loesung like Nauka

//Uebung 21
//Paramter der Komandozeile ausgeben

//includes
#include<stdio.h>
//main
int main(int argc[], char *argv []){

    int i;
    for (i =0; i < argc; i++ ){
        printf("%3d %s\n", i, argv[i]);
    }
return 0;
}