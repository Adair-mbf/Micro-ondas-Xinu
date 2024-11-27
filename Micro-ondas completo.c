#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
int main() {
    bool Porta = false, Luz = false;
    bool Girardisco = false, Respiracao = true;
    char acao[7];
    scanf("%6s", acao);
    if (strcmp(acao, "abrir") == 0) {
        Porta = true;
    } else {
        Porta = false;
        char digitacao[20];
        int minuto = 0, segundo = 0, horaagendada = -1, minutoagendado = -1;
        int ciclos = 1, ciclo_atual = 0;
        bool curvadeaquecimento = false; 
        while (1) {
            scanf("%19s", digitacao);
            if (strcmp(digitacao, "Carne") == 0) {
                printf("Bip\n");
                minuto += 10;
            } else if (strcmp(digitacao, "Lasanha") == 0) {
                printf("Bip\n");
                minuto += 5;
            } else if (strcmp(digitacao, "Peixe") == 0) {
                printf("Bip\n");
                minuto += 4;
            } else if (strcmp(digitacao, "Frango") == 0) {
                printf("Bip\n");
                minuto += 8;
            } else if (strcmp(digitacao, "Pipoca") == 0) {
                printf("Bip\n");
                minuto += 2;
            }
            if (strcmp(digitacao, "ciclos") == 0) {
                printf("Quantos ciclos deseja especificar?\n");
                scanf("%d", &ciclos);
                if (ciclos <= 0) ciclos = 1; 
                printf("Ciclos definidos: %d\n", ciclos);
            }
            if (strcmp(digitacao, "curvas") == 0) {
                curvadeaquecimento = true;
                printf("Curvas de aquecimento ativadas.\n");
            }
            if (strcmp(digitacao, "1") == 0) {
                printf("Bip\n");
                scanf("%s", digitacao);
                if (strcmp(digitacao, "seg") == 0) {
                    segundo += 1;
                } else if (strcmp(digitacao, "min") == 0) {
                    minuto += 1;
                }
            } else if (strcmp(digitacao, "5") == 0) {
                printf("Bip\n");
                scanf("%s", digitacao);
                if (strcmp(digitacao, "seg") == 0) {
                    segundo += 5;
                } else if (strcmp(digitacao, "min") == 0) {
                    minuto += 5;
                }
            }
            if (strcmp(digitacao, "agendar") == 0) {
                scanf("%d %d", &horaagendada, &minutoagendado);
            }
            if (horaagendada != -1 && minutoagendado != -1) {
                time_t t;
                struct tm *horario_atual;
                do {
                    t = time(NULL);
                    horario_atual = localtime(&t);
                } while (horario_atual->tm_hour != horaagendada || horario_atual->tm_min != minutoagendado);
                horaagendada = -1;
                minutoagendado = -1;
            }
            if (strcmp(digitacao, "ligar") == 0) {
                printf("Bip\n");
                Respiracao = false;
                Girardisco = true;
                for (ciclo_atual = 1; ciclo_atual <= ciclos; ciclo_atual++) {
                    printf("Iniciando ciclo %d de %d\n", ciclo_atual, ciclos);
                    while (minuto > 0 || segundo > 0) {
                        printf("%02d:%02d\n", minuto, segundo);
                        sleep(1);
                        segundo--;
                        if (segundo < 0 && minuto > 0) {
                            segundo = 59;
                            minuto--;
                        }
                        if (curvadeaquecimento && segundo % 10 == 0) {
                            printf("Curva de aquecimento: reduzindo intensidade.\n");
                            sleep(2);
                        }
                    }
                    printf("Ciclo %d concluído.\n", ciclo_atual);
                    if (ciclo_atual < ciclos) {
                        minuto = 5;
                        segundo = 0;
                    }
                }
                Respiracao = true;
                Girardisco = false;
                printf("Bip Bip Bip\n");
                printf("00:00\n");
            } else if (strcmp(digitacao, "cancelar") == 0) {
                printf("Bip\n");
                minuto = 0;
                segundo = 0;
                printf("%02d:%02d\n", minuto, segundo);
            } else if (strcmp(digitacao, "desligar") == 0) {
                while (1) {
                    time_t t = time(NULL);
                    struct tm *horario_atual = localtime(&t);
                    int horas = horario_atual->tm_hour;
                    int minutos = horario_atual->tm_min;
                    printf("\r%02d:%02d", horas, minutos);
                    fflush(stdout);
                    sleep(60 - horario_atual->tm_sec);
                }
            } else {
                printf("%02d:%02d\n", minuto, segundo);
            }
        }
    }
    if (Porta == true) {
        Luz = true;
    } else {
        Luz = false;
    }
    return 0;
}