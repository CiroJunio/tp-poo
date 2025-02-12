#include "../include/Unidade.h"
#include <cstdlib>

// Inicializa poder de ataque e destruições como 0
Unidade::Unidade() : poderAtaque(0), destruicoes(0) {}

// Incrementa o contador de destruições
void Unidade::somaDestruicao() {
    destruicoes++;
}

// Obtém o número de destruições
int Unidade::getDestruicoes() const {
    return destruicoes;
}

// Recalcula o poder de ataque
Infantaria::Infantaria() {
    recalcularPoderAtaque();
}

// Recalcula o poder de ataque da Infantaria
void Infantaria::recalcularPoderAtaque() {
    poderAtaque = rand() % 31 + 30; // 30 a 60
    forca = rand() % 31 + 20;       // 20 a 50
    velocidade = rand() % 31 + 10;  // 10 a 40
}

// Obtém o poder de ataque da Infantaria
int Infantaria::getPoderAtaque() const {
    return ((poderAtaque * 5) + (forca * 3) + (velocidade * 2)) / 10;
}

// Recalcula o poder de ataque
Veiculo::Veiculo() {
    recalcularPoderAtaque();
}

// Recalcula o poder de ataque do Veículo
void Veiculo::recalcularPoderAtaque() {
    poderAtaque = rand() % 41 + 40; // 40 a 80
    blindagem = rand() % 41 + 30;   // 30 a 70
    potenciaDeFogo = rand() % 31 + 20; // 20 a 50
}

// Obtém o poder de ataque do Veículo
int Veiculo::getPoderAtaque() const {
    return ((poderAtaque * 5) + (blindagem * 4) + (potenciaDeFogo * 1)) / 10;
}

// Recalcula o poder de ataque
Aeronave::Aeronave() {
    recalcularPoderAtaque();
}

// Recalcula o poder de ataque da Aeronave
void Aeronave::recalcularPoderAtaque() {
    poderAtaque = rand() % 41 + 50;    // 50 a 90
    manobrabilidade = rand() % 41 + 30; // 30 a 70
    alcance = rand() % 31 + 20;         // 20 a 50
}

// Obtém o poder de ataque da Aeronave
int Aeronave::getPoderAtaque() const {
    return ((poderAtaque * 5) + (manobrabilidade * 3) + (alcance * 2)) / 10;
}