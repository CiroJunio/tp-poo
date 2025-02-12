#ifndef EXERCITO_H
#define EXERCITO_H

#include "Unidade.h"
#include <string>
#include <vector>

class Exercito {
private:
    std::string nome; // Nome do exército
    std::vector<Unidade*> unidades; // Lista de unidades do exército
    int vitorias; // Contador de vitórias
    int empates; // Contador de empates
    int derrotas; // Contador de derrotas

public:
    // Construtor: inicializa o exército com um nome e adiciona unidades padrão
    Exercito(const std::string &nome);

    // Destrutor: libera a memória alocada para as unidades
    ~Exercito();

    // Método para adicionar uma unidade ao exército
    void adicionarUnidade(Unidade *unidade);

    // Método para recalcular o poder de ataque de todas as unidades
    void recalcularPoderUnidades();

    // Método para obter os resultados do exército (vitórias, empates, derrotas)
    std::string getResultados() const;

    // Método para imprimir as unidades do exército
    void imprimeUnidades() const;

    // Método para atualizar os resultados do exército após uma batalha
    void atualizarResultados(int resultado);

    // Método para calcular o poder total do exército
    int calcularPoderTotal() const;

    // Método para registrar destruições nas unidades (não implementado)
    void registrarDestruicoes();

    // Métodos para obter unidades, nome, vitórias e empates
    const std::vector<Unidade*> &getUnidades() const { return unidades; };
    std::string getNome() const { return nome; }
    int getVitorias() const { return vitorias; }
    int getEmpates() const { return empates; }
};

#endif