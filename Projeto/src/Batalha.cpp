#include "../include/Batalha.h"
#include <iostream>

// Construtor: inicializa a batalha com data e os dois exércitos
Batalha::Batalha(const std::string &data, Exercito *exercitoA, Exercito *exercitoB)
    : data(data), exercitoA(exercitoA), exercitoB(exercitoB), resultadoA(0),
      resultadoB(0) {}

// Método para simular o ataque do exército A
void Batalha::ataqueExercitoA() {
    resultadoA = exercitoA->calcularPoderTotal();
}

// Método para simular o ataque do exército B
void Batalha::ataqueExercitoB() {
    resultadoB = exercitoB->calcularPoderTotal();
}

// Método para obter o resultado do ataque do exército A
int Batalha::getResultadoA() const { return resultadoA; }

// Método para obter o resultado do ataque do exército B
int Batalha::getResultadoB() const { return resultadoB; }

// Método para obter o resultado completo da batalha como string
std::string Batalha::getResultado() const {
    std::string resultado;

    resultado = "Data da Batalha: " + data + "\n";

    if (resultadoA > resultadoB) {
        resultado += exercitoA->getResultados() +
                     " Vencedor: " + exercitoA->getNome() + " " +
                     std::to_string(resultadoA) + " x " +
                     std::to_string(resultadoB) + " " + exercitoB->getResultados();
    } else if (resultadoB > resultadoA) {
        resultado += exercitoB->getResultados() +
                     " Vencedor: " + exercitoB->getNome() + " " +
                     std::to_string(resultadoA) + " x " +
                     std::to_string(resultadoB) + " " + exercitoA->getResultados();
    } else {
        resultado += "Empate: " + exercitoA->getResultados() + " " +
                     std::to_string(resultadoA) + " x " +
                     std::to_string(resultadoB) + " " + exercitoB->getResultados();
    }

    return resultado;
}