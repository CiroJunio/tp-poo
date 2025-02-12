#ifndef BATALHA_H
#define BATALHA_H

#include "Exercito.h"
#include <string>

class Batalha {
private:
    std::string data; // Data da batalha
    Exercito* exercitoA; // Ponteiro para o primeiro exército
    Exercito* exercitoB; // Ponteiro para o segundo exército
    int resultadoA; // Resultado do ataque do exército A
    int resultadoB; // Resultado do ataque do exército B

public:
    // Construtor: inicializa a batalha com data e os dois exércitos
    Batalha(const std::string &data, Exercito *exercitoA, Exercito *exercitoB);

    // Métodos para simular os ataques dos exércitos
    void ataqueExercitoA();
    void ataqueExercitoB();

    // Métodos para obter os resultados dos ataques
    int getResultadoA() const;
    int getResultadoB() const;

    // Método para obter o resultado completo da batalha como string
    std::string getResultado() const;

    // Método para obter a data da batalha
    std::string getData() const;
};

#endif