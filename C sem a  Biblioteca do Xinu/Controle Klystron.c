#include <stdio.h>
#include <stdbool.h>

int main(){
    bool tomada=false, botaoligar=false;
    int conectartomada, ligarmicroondas;
    scanf("%d", &conectartomada);
    if(conectartomada==1){
        tomada=true;
    }
    else{
        tomada=false;
    }
    if(tomada==true){
        scanf("%d", &ligarmicroondas);
        if (ligarmicroondas==1)
        {
            botaoligar=true;
        }
    }
}