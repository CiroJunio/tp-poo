#include "../include/Campanha.h"
#include <algorithm>
#include <iostream>

// Construtor: inicializa a campanha com dois exércitos
Campanha::Campanha(Exercito *exercitoA, Exercito *exercitoB)
    : exercitoA(exercitoA), exercitoB(exercitoB) {}

// Destrutor: libera a memória alocada para as batalhas
Campanha::~Campanha() {
    for (Batalha *batalha : batalhas) {
        delete batalha;
    }
}

// Método para simular uma quantidade específica de batalhas
void Campanha::simularBatalhas(int quantidade) {
    for (int i = 0; i < quantidade; ++i) {
        // Recalcular o poder de ataque das unidades antes de cada batalha
        exercitoA->recalcularPoderUnidades();
        exercitoB->recalcularPoderUnidades();

        // Criar uma nova batalha
        Batalha *batalha = new Batalha("1", exercitoA, exercitoB);

        // Simular os ataques dos exércitos
        batalha->ataqueExercitoA();
        batalha->ataqueExercitoB();

        // Adicionar a batalha ao vetor de batalhas
        batalhas.push_back(batalha);

        // Comparar unidades equivalentes e contabilizar destruições
        const std::vector<Unidade*>& unidadesA = exercitoA->getUnidades();
        const std::vector<Unidade*>& unidadesB = exercitoB->getUnidades();

        std::cout << "\nBatalha entre " << exercitoA->getNome() << " e " << exercitoB->getNome() << ":\n";

        // Garantir que apenas 5 unidades sejam comparadas
        for (size_t j = 0; j < 5; ++j) {
            std::string tipoA, tipoB;
            if (dynamic_cast<Infantaria*>(unidadesA[j])) tipoA = "Infantaria";
            else if (dynamic_cast<Veiculo*>(unidadesA[j])) tipoA = "Veiculo";
            else if (dynamic_cast<Aeronave*>(unidadesA[j])) tipoA = "Aeronave";

            if (dynamic_cast<Infantaria*>(unidadesB[j])) tipoB = "Infantaria";
            else if (dynamic_cast<Veiculo*>(unidadesB[j])) tipoB = "Veiculo";
            else if (dynamic_cast<Aeronave*>(unidadesB[j])) tipoB = "Aeronave";

            // Exibir o número da unidade corretamente
             std::cout << "Unidade " << j + 1 << " (" << tipoA << ") de " << exercitoA->getNome()
                      << " vs Unidade " << j + 1 << " (" << tipoB << ") de " << exercitoB->getNome() << ":\n";

            if (unidadesA[j]->getPoderAtaque() > unidadesB[j]->getPoderAtaque()) {
                std::cout << "  Vitória da unidade de " << exercitoA->getNome() << "!\n";
                unidadesA[j]->somaDestruicao();
            } else if (unidadesA[j]->getPoderAtaque() < unidadesB[j]->getPoderAtaque()) {
                std::cout << "  Vitória da unidade de " << exercitoB->getNome() << "!\n";
                unidadesB[j]->somaDestruicao();
            } else {
                std::cout << "  Empate entre as unidades!\n";
            }
        }

        // Atualizar resultados da batalha (vitórias, empates, derrotas)
        if (batalha->getResultadoA() > batalha->getResultadoB()) {
            exercitoA->atualizarResultados(1);
            exercitoB->atualizarResultados(-1);
        } else if (batalha->getResultadoA() < batalha->getResultadoB()) {
            exercitoA->atualizarResultados(-1);
            exercitoB->atualizarResultados(1);
        } else {
            exercitoA->atualizarResultados(0);
            exercitoB->atualizarResultados(0);
        }
    }
}