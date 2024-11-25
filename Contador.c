#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    char digitacao[10];
    int minuto=0, segundo=0;
    while (1) {
    scanf("%9s", digitacao);
    if (strcmp(digitacao, "1")==0) {
            scanf("%s", digitacao);
            if (strcmp(digitacao, "seg")==0) {
                segundo+=1;
            }
            else if (strcmp(digitacao, "min")==0) {
                minuto+=1;
            }
        } else if (strcmp(digitacao, "5")==0) {
            scanf("%s", digitacao);
            if (strcmp(digitacao, "seg")==0) {
                segundo+=5;
            } else if (strcmp(digitacao, "min")==0) {
                minuto+=5;
            }
        } else if (strcmp(digitacao, "10")==0) {
            scanf("%s", digitacao);
            if (strcmp(digitacao, "seg")==0) {
                segundo+=10;
            } else if (strcmp(digitacao, "min")==0) {
                minuto+=10;
            }
        } else if (strcmp(digitacao, "30")==0) {
            scanf("%s", digitacao);
            if (strcmp(digitacao, "seg")==0) {
                segundo+=30;
            } else if (strcmp(digitacao, "min")==0) {
                minuto+=30;
            }
        }
    minuto+=segundo/60;
    segundo%=60;
    if (strcmp(digitacao, "ligar")==0) {
        while (minuto>0 || segundo>0) {
            printf("%02d:%02d\n", minuto, segundo);
            segundo--;
                if (segundo<0 && minuto>0) {
                    segundo=59;
                    minuto--;
                }
                sleep(1);
        }
        printf("00:00\n");
    }
    else if (strcmp(digitacao, "cancelar")==0) {
        minuto=0;
        segundo=0;
        printf("%02d:%02d\n", minuto, segundo);
    }
    else if (strcmp(digitacao, "desligar")==0) {
        break;
        }
        else {
            printf("%02d:%02d\n", minuto, segundo);
        }
    }
    return 0;
}