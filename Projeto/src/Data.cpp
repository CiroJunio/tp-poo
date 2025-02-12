#include "../include/Data.h"
#include <ctime>
#include <iomanip>
#include <sstream>

// Construtor: inicializa a data com dia, mês e ano
Data::Data(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano) {}

// Retorna a data formatada como string
std::string Data::formatarData() const {
  std::ostringstream oss;
  oss << std::setw(2) << std::setfill('0') << dia << "/" << std::setw(2)
      << std::setfill('0') << mes << "/" << ano;
  return oss.str();
}

// Retorna o dia
int Data::getDia() const { return dia; }

// Retorna o mês
int Data::getMes() const { return mes; }

// Retorna o ano
int Data::getAno() const { return ano; }

// Exibe a data formatada
void Data::exibirData() const { std::cout << formatarData() << std::endl; }

// Retorna um objeto Data com a data atual
Data Data::dataAtual() {
  time_t t = time(nullptr);
  tm now{};
  localtime_r(&t, &now);
  return Data(now.tm_mday, now.tm_mon + 1, now.tm_year + 1900);
}