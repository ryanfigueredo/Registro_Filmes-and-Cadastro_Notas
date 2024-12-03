/* Programa para cadastro e avaliação de filmes
Integrantes do grupo:
    1240108158 - Ryan Figueredo
    1240108101 - Lucas Antunes
    1240108383 - Thiago Gomes
    1240108540 - Vinicius Arruda
*/

#include <iostream>
#include <string>
#include <vector>

struct Aluno {
    std::string nome;
    std::vector<float> notas;
};

void inserirDados(std::vector<Aluno> &alunos) {
    int qtdAlunos;
    std::cout << "Digite a quantidade de alunos: ";
    std::cin >> qtdAlunos;

    alunos.resize(alunos.size() + qtdAlunos);

    for (int i = alunos.size() - qtdAlunos; i < alunos.size(); i++) {
        std::cout << "Digite o nome do aluno " << i + 1 << ": ";
        std::cin.ignore();
        std::getline(std::cin, alunos[i].nome);

        int qtdNotas;
        std::cout << "Digite a quantidade de notas do aluno " << alunos[i].nome << ": ";
        std::cin >> qtdNotas;

        alunos[i].notas.resize(qtdNotas);

        for (int j = 0; j < qtdNotas; j++) {
            std::cout << "Digite a nota " << j + 1 << " do aluno " << alunos[i].nome << ": ";
            std::cin >> alunos[i].notas[j];
        }
    }
}

void calcularMedias(const std::vector<Aluno> &alunos) {
    if (alunos.empty()) {
        std::cout << "\nNenhum aluno cadastrado para calcular médias.\n";
        return;
    }

    float somaGlobal = 0.0f;
    int totalNotas = 0;

    std::cout << "\nMédias dos Alunos:\n";
    for (const auto &aluno : alunos) {
        float soma = 0.0f;
        for (float nota : aluno.notas) {
            soma += nota;
        }

        float media = soma / aluno.notas.size();
        std::cout << "Aluno: " << aluno.nome << ", Média: " << media << "\n";

        somaGlobal += soma;
        totalNotas += aluno.notas.size();
    }

    if (totalNotas > 0) {
        float mediaGlobal = somaGlobal / totalNotas;
        std::cout << "Média Global: " << mediaGlobal << "\n";
    }
}

int main() {
    std::vector<Aluno> alunos;
    int opcao;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Inserir dados de alunos\n";
        std::cout << "2. Calcular e exibir médias\n";
        std::cout << "3. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                inserirDados(alunos);
                break;
            case 2:
                calcularMedias(alunos);
                break;
            case 3:
                std::cout << "Encerrando o programa...\n";
                break;
            default:
                std::cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 3);

    return 0;
}
