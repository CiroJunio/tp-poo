#include "../include/Exercito.h"
#include <iostream>
#include <string>

// Construtor: inicializa o exército com um nome e adiciona unidades padrão
Exercito::Exercito(const std::string &nome)
    : nome(nome), vitorias(0), empates(0), derrotas(0) {
    // Adicionar 2 Infantaria, 2 Veículos e 1 Aeronave ao exército
    adicionarUnidade(new Infantaria());
    adicionarUnidade(new Infantaria());
    adicionarUnidade(new Veiculo());
    adicionarUnidade(new Veiculo());
    adicionarUnidade(new Aeronave());
}

// Destrutor: libera a memória alocada para as unidades
Exercito::~Exercito() {
    for (Unidade *unidade : unidades) {
        delete unidade;
    }
}

// Método para adicionar uma unidade ao exército
void Exercito::adicionarUnidade(Unidade *unidade) {
    unidades.push_back(unidade);
}

// Método para recalcular o poder de ataque de todas as unidades
void Exercito::recalcularPoderUnidades() {
    for (Unidade *unidade : unidades) {
        unidade->recalcularPoderAtaque(); // Randomiza o poder de ataque da unidade
    }
}

// Método para obter os resultados do exército (vitórias, empates, derrotas)
std::string Exercito::getResultados() const {
    return "Vitórias: " + std::to_string(vitorias) +
           ", Empates: " + std::to_string(empates) +
           ", Derrotas: " + std::to_string(derrotas);
}

// Método para imprimir as unidades do exército
void Exercito::imprimeUnidades() const {
    for (size_t i = 0; i < unidades.size(); ++i) {
        std::cout << "Unidade " << i + 1 << ": "
                  << "Poder de ataque = " << unidades[i]->getPoderAtaque()
                  << ", Destruicoes = " << unidades[i]->getDestruicoes()
                  << ", Tipo = ";

        if (dynamic_cast<Infantaria*>(unidades[i])) {
            std::cout << "Infantaria";
        } else if (dynamic_cast<Veiculo*>(unidades[i])) {
            std::cout << "Veiculo";
        } else if (dynamic_cast<Aeronave*>(unidades[i])) {
            std::cout << "Aeronave";
        }
        std::cout << std::endl;
    }
}

// Método para atualizar os resultados do exército após uma batalha
void Exercito::atualizarResultados(int resultado) {
    if (resultado > 0)
        vitorias++;
    else if (resultado == 0)
        empates++;
    else
        derrotas++;
}

// Método para calcular o poder total do exército
int Exercito::calcularPoderTotal() const {
    int total = 0;
    for (const Unidade *unidade : unidades) {
        total += unidade->getPoderAtaque();
    }
    return total;
}

// Método para registrar destruições nas unidades (não implementado)
void Exercito::registrarDestruicoes() {
    for (Unidade *unidade : unidades) {
        unidade->somaDestruicao();
    }
}