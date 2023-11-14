//
// Created by aluno on 14/11/23.
//



#include "Avaliação1.h"
#include <stdio.h>
#include <string.h>

struct Usuario {
    char login[10];
    char senha[10];
    char nome[30];
};

int main() {
    struct Usuario usuarios[500];
    FILE *Arq;
    char login[10];
    char senha[10];

    Arq = fopen("../database.dat", "rb");
    if (Arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    // Lê as informações dos usuários do arquivo
    fread(usuarios, sizeof(struct Usuario), 500, Arq);
    fclose(Arq);

    // Coleta o login e senha do usuário
    printf("Digite o login: ");
    scanf("%s", login);

    printf("Digite a senha: ");
    scanf("%s", senha);

    // Verifica as credenciais na base de dados
    for (int i = 0; i < 500; i++) {
        if (strcmp(login, usuarios[i].login) == 0 && strcmp(senha, usuarios[i].senha) == 0) {
            printf("Saudacoes, %s!\n", usuarios[i].nome);
            return 0;
        }
    }

    printf("Credenciais inválidas!\n");
    return 0;
}