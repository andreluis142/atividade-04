#include <stdio.h>
#include <string.h>

struct Estudante {
    char nome[21];
    float altura;
    float peso;
    float IRA;
};

int main() {
   
    struct Estudante estudantes[5];
    
    
    float soma_altura = 0, soma_peso = 0, soma_IRA = 0;
    
    
    for (int i = 0; i < 5; i++) {
        scanf("%s%f%f%f", estudantes[i].nome, &estudantes[i].altura, &estudantes[i].peso, &estudantes[i].IRA);
        
        
        soma_altura += estudantes[i].altura;
        soma_peso += estudantes[i].peso;
        soma_IRA += estudantes[i].IRA;
    }
    
    
    float media_altura = soma_altura / 5;
    float media_peso = soma_peso / 5;
    float media_IRA = soma_IRA / 5;
    
    
    float maior_altura = estudantes[0].altura, maior_peso = estudantes[0].peso, maior_IRA = estudantes[0].IRA;
    char nome_maior_altura[21], nome_maior_peso[21], nome_maior_IRA[21];
    
    for (int i = 1; i < 5; i++) {
        if (estudantes[i].altura > maior_altura) {
            maior_altura = estudantes[i].altura;
            strcpy(nome_maior_altura, estudantes[i].nome);
        }
        
        if (estudantes[i].peso > maior_peso) {
            maior_peso = estudantes[i].peso;
            strcpy(nome_maior_peso, estudantes[i].nome);
        }
        
        if (estudantes[i].IRA > maior_IRA) {
            maior_IRA = estudantes[i].IRA;
            strcpy(nome_maior_IRA, estudantes[i].nome);
        }
    }
    
    // Imprimir as médias
    printf("Media de peso: %.3f\n", media_peso);
    printf("Media de altura: %.3f\n", media_altura);
    printf("Media de IRA: %.2f\n\n", media_IRA);
    
    // Imprimir o nome e medida para os alunos com as maiores medidas
    printf("Maior peso: %s (%.3f)\n", nome_maior_peso, maior_peso);
    printf("Maior altura: %s (%.3f)\n", nome_maior_altura, maior_altura);
    printf("Maior CRA: %s (%.2f)\n", nome_maior_IRA, maior_IRA);
    
    return 0;
}
