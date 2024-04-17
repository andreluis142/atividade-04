#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Carta {
    char *valor;
    char *naipe;
};


void inicializar_deck(struct Carta *deck) {
    char *valores[] = {"As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete",
                       "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};
    char *naipes[] = {"Paus", "Ouros", "Copas", "Espadas"};
    
    int index = 0;
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            deck[index].valor = valores[i];
            deck[index].naipe = naipes[j];
            index++;
        }
    }
}


void embaralhar_deck(struct Carta *deck) {
    srand(time(NULL)); 
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        struct Carta temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}


void exibir_deck(struct Carta *deck, int tipo_exibicao) {
    for (int i = 0; i < 52; i++) {
        if (tipo_exibicao == 0) { 
            printf("%s de %s\n", deck[i].valor, deck[i].naipe);

        } else { 
            printf("%s de %s\n", deck[i].valor, deck[i].naipe);
            if ((i + 1) % 13 == 0 && i != 51) {
                printf("\n");
            }
        }
    }
}

int main() {
    struct Carta deck[52];
    
    
    inicializar_deck(deck);
    
    int tipo_exibicao;
    scanf("%d", &tipo_exibicao);
    
    if (tipo_exibicao == 0) {
       
        embaralhar_deck(deck);
    }
    
    
    exibir_deck(deck, tipo_exibicao);
    
    printf("\n"); 
    
    return 0;
}