#include <avr/io.h>
#include <xinu.h>
#include <uart.h>
#include <stdbool.h>
int main(void) {
    uart_init();
    bool Porta = false, Luz = false;
    bool Girardisco = false, Respiracao = true;
    int minuto = 0, segundo = 0, ciclos = 1, ciclo_atual = 0;
    bool curvadeaquecimento = false;
    char comando[20];
    while (1) {
        uart_read(comando, sizeof(comando));  
        if (strcmp(comando, "abrir") == 0) {
            Porta = true;
            Luz = true;
        } else if (strcmp(comando, "fechar") == 0) {
            Porta = false;
            Luz = false;
        } else if (strcmp(comando, "Carne") == 0) {
            kprintf("Bip\n");
            minuto += 10;
        } else if (strcmp(comando, "Lasanha") == 0) {
            kprintf("Bip\n");
            minuto += 5;
        } else if (strcmp(comando, "Peixe") == 0) {
            kprintf("Bip\n");
            minuto += 4;
        } else if (strcmp(comando, "Frango") == 0) {
            kprintf("Bip\n");
            minuto += 8;
        } else if (strcmp(comando, "Pipoca") == 0) {
            kprintf("Bip\n");
            minuto += 2;
        } else if (strcmp(comando, "ciclos") == 0) {
            kprintf("Quantos ciclos deseja especificar?\n");
            uart_read(comando, sizeof(comando));
            ciclos = atoi(comando);
            if (ciclos <= 0) ciclos = 1;
            kprintf("Ciclos definidos: %d\n", ciclos);
        } else if (strcmp(comando, "curvas") == 0) {
            curvadeaquecimento = true;
            kprintf("Curvas de aquecimento ativadas.\n");
        } else if (strcmp(comando, "ligar") == 0) {
            Girardisco = true;
            Respiracao = false;
            for (ciclo_atual = 1; ciclo_atual <= ciclos; ciclo_atual++) {
                kprintf("Iniciando ciclo %d de %d\n", ciclo_atual, ciclos);

                while (minuto > 0 || segundo > 0) {
                    kprintf("%02d:%02d\n", minuto, segundo);
                    sleep(1);
                    segundo--;

                    if (segundo < 0 && minuto > 0) {
                        segundo = 59;
                        minuto--;
                    }
                    if (curvadeaquecimento && segundo % 10 == 0) {
                        kprintf("Curva de aquecimento: reduzindo intensidade.\n");
                        sleep(2);
                    }
                }
                kprintf("Ciclo %d concluído.\n", ciclo_atual);
                if (ciclo_atual < ciclos) {
                    minuto = 5;
                    segundo = 0;
                }
            }
            Girardisco = false;
            Respiracao = true;
            kprintf("Bip Bip Bip\n");
            kprintf("00:00\n");
        } else if (strcmp(comando, "cancelar") == 0) {
            minuto = 0;
            segundo = 0;
            kprintf("00:00\n");
        } else {
            kprintf("Comando não reconhecido: %s\n", comando);
        }
    }
    return 0;
}
