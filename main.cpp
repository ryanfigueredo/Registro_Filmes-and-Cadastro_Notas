/* Programa para cadastro e avaliação de filmes
   Integrantes do grupo:
    1240108158 - Ryan Figueredo
    1240108101 - Lucas Antunes
    1240108383 - Thiago Gomes
    1240108540 - Vinicius Arruda
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[51];
    int ano;
    float notaMedia;
    int qtdAvaliacoes;
} Filme;

Filme filmes[MAX];
int totalFilmes = 0;

int cadastrarFilme() {
    if (totalFilmes >= MAX) {
        printf("Limite máximo de filmes cadastrados atingido.\n");
        return 0;
    }

    printf("Digite o nome do filme: ");
    getchar();
    fgets(filmes[totalFilmes].nome, 51, stdin);
    filmes[totalFilmes].nome[strcspn(filmes[totalFilmes].nome, "\n")] = '\0'; // Remover o '\n' do fgets

    printf("Digite o ano de lançamento: ");
    scanf("%d", &filmes[totalFilmes].ano);

    filmes[totalFilmes].notaMedia = 0.0;
    filmes[totalFilmes].qtdAvaliacoes = 0;

    totalFilmes++;
    printf("Filme cadastrado com sucesso!\n");
    return 1;
}

int adicionarAvaliacao() {
    char nomeFilme[51];
    float nota;
    int i;

    printf("Digite o nome do filme para avaliar: ");
    getchar();
    fgets(nomeFilme, 51, stdin);
    nomeFilme[strcspn(nomeFilme, "\n")] = '\0';

    for (i = 0; i < totalFilmes; i++) {
        if (strcmp(filmes[i].nome, nomeFilme) == 0) {
            printf("Digite a nota (0 a 5): ");
            scanf("%f", &nota);

            if (nota < 0 || nota > 5) {
                printf("Nota inválida.\n");
                return 0;
            }

            filmes[i].qtdAvaliacoes++;
            filmes[i].notaMedia = ((filmes[i].notaMedia * (filmes[i].qtdAvaliacoes - 1)) + nota) / filmes[i].qtdAvaliacoes;

            printf("Avaliação adicionada com sucesso!\n");
            return 1;
        }
    }

    printf("Filme não encontrado.\n");
    return 0;
}

void exibirFilmes() {
    printf("\nLista de Filmes Cadastrados:\n");
    for (int i = 0; i < totalFilmes; i++) {
        printf("Nome: %s, Ano: %d, Avaliações: %d, Nota Média: %.2f\n",
               filmes[i].nome, filmes[i].ano, filmes[i].qtdAvaliacoes, filmes[i].notaMedia);
    }
}

int main() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Filme\n");
        printf("2. Adicionar Avaliação\n");
        printf("3. Exibir Filmes\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarFilme();
                break;
            case 2:
                adicionarAvaliacao();
                break;
            case 3:
                exibirFilmes();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 4);

    return 0;
}
