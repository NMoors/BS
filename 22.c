//Einen einfachen Taschenrechner bauen
//mal schauen wie genau
//erst mal includes
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    int val1, val2, erg;
    char op;

    if(argc !=4){
    printf("Rechnung: %s Wert1 operator Wert2\n", argv[0]); 
    return 1;
    } 
    val1 = atoi(argv[1]);
    val2 = atoi(argv[3]);
    erg = *argv[2];

    switch(erg){
        default:
        case'+': erg = val1 + val2; break;
        case'-': erg = val1 - val2; break;
        case'*': erg = val1 * val2; break;
        case'/': erg = val1 / val2; break;
        case'%': erg = val1 % val2; break;
    }
    return erg;
}