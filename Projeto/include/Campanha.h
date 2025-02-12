#ifndef CAMPANHA_H
#define CAMPANHA_H

#include <vector>
#include "Batalha.h"

class Campanha {
private:
    std::vector<Batalha*> batalhas; // Lista de batalhas da campanha
    Exercito* exercitoA; // Ponteiro para o primeiro exército
    Exercito* exercitoB; // Ponteiro para o segundo exército

public:
    // Construtor: inicializa a campanha com dois exércitos
    Campanha(Exercito* exercitoA, Exercito* exercitoB);

    // Destrutor: libera a memória alocada para as batalhas
    ~Campanha();

    // Método para simular uma quantidade específica de batalhas
    void simularBatalhas(int quantidade);

    // Método para gerar uma tabela de posições (não implementado)
    void gerarTabelaPosicoes() const;

    // Método para mostrar a unidade mais destrutiva (não implementado)
    void mostrarUnidadeMaisDestrutiva() const;
};

#endif