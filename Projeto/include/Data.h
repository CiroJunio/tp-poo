#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>

class Data {
private:
  int dia; // Dia do mês (1-31)
  int mes; // Mês do ano (1-12)
  int ano; // Ano (ex: 2023)

public:
  // Construtor: inicializa a data com dia, mês e ano
  Data(int dia, int mes, int ano);

  // Retorna a data formatada como string no formato "dd/mm/aaaa"
  std::string formatarData() const;

  // Métodos para obter dia, mês e ano
  int getDia() const;
  int getMes() const;
  int getAno() const;

  // Exibe a data no formato "dd/mm/aaaa" no console
  void exibirData() const;

  // Retorna um objeto Data com a data atual do sistema
  static Data dataAtual();
};

#endif