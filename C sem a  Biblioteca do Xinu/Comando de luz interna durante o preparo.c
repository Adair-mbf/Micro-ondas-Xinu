#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){
    bool Porta=false,Luz=false;
    char acao[7];
    scanf("%6s", acao);
    if (strcmp(acao, "abrir")==0)
    {
        Porta=true;
    }
    else{
        Porta=false;
    }
    if (Porta==true){
        Luz=true;
    }
    else{
        Luz=false;
    }
}