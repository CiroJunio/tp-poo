#ifndef UNIDADE_H
#define UNIDADE_H

#include <string>

class Unidade {
protected:
    int poderAtaque; // Poder de ataque da unidade
    int destruicoes; //Contador de destruições causadas pela unidade

public:
    // Construtor padrão
    Unidade();

    // Destrutor virtual para permitir polimorfismo
    virtual ~Unidade() = default;

    // Metodo virtual para recalcular o poder de ataque 
    virtual void recalcularPoderAtaque() = 0;

    // Metodo virtual para obter o poder de ataque 
    virtual int getPoderAtaque() const = 0;

    // Metodo para incrementar o contador de destruições
    void somaDestruicao();

    // Metodo para obter o número de destruições
    int getDestruicoes() const;
};

// Classe derivada: Infantaria
class Infantaria : public Unidade {
private:
    int forca; // Força da infantaria
    int velocidade; // Velocidade da infantaria

public:
    // Construtor: inicializa a infantaria e recalcula o poder de ataque
    Infantaria();

    // Implementação do método para recalcular o poder de ataque
    void recalcularPoderAtaque() override;

    // Implementação do método para obter o poder de ataque
    int getPoderAtaque() const override;
};

// Classe derivada: Veiculo
class Veiculo : public Unidade {
private:
    int blindagem; // Blindagem do veículo
    int potenciaDeFogo; // Potência de fogo do veículo

public:
    // Construtor: inicializa o veículo e recalcula o poder de ataque
    Veiculo();

    // Implementação do método para recalcular o poder de ataque
    void recalcularPoderAtaque() override;

    // Implementação do método para obter o poder de ataque
    int getPoderAtaque() const override;
};

// Classe derivada: Aeronave
class Aeronave : public Unidade {
private:
    int manobrabilidade; // Manobrabilidade da aeronave
    int alcance; // Alcance da aeronave

public:
    // Construtor: inicializa a aeronave e recalcula o poder de ataque
    Aeronave();

    // Implementação do método para recalcular o poder de ataque
    void recalcularPoderAtaque() override;

    // Implementação do método para obter o poder de ataque
    int getPoderAtaque() const override;
};

#endif