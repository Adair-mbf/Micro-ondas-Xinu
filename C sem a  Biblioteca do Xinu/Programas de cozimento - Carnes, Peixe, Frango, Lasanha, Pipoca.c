#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
    char digitacao[10];
    int minuto=0, segundo=0;
    while (1) {
    scanf("%9s", digitacao);
    if (strcmp(digitacao, "Carne")==0) {
        minuto+=10;
        }
    else if (strcmp(digitacao, "Lasanha")==0) {
        minuto+=5;
        }
    else if (strcmp(digitacao, "Peixe")==0) {
        minuto+=4;
        }
    else if (strcmp(digitacao, "Frango")==0) {
        minuto+=8;
        }
    else if (strcmp(digitacao, "Pipoca")==0) {
        minuto+=2;
        }
    }
}