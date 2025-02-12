#include "../include/Batalha.h"
#include "../include/Campanha.h"
#include "../include/Data.h"
#include "../include/Exercito.h"
#include "../include/Unidade.h"
#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include <limits>

// Função para comparar unidades por destruições 
bool compararUnidadesPorDestruicoes(const Unidade *a, const Unidade *b) {
  return a->getDestruicoes() > b->getDestruicoes();
}

// Função para comparar exércitos por vitórias e empates 
bool compararExercitosPorVitorias(const Exercito *a, const Exercito *b) {
  if (a->getVitorias() != b->getVitorias()) {
    return a->getVitorias() > b->getVitorias();
  } else {
    return a->getEmpates() > b->getEmpates();
  }
}

// Função para verificar se o arquivo está vazio
bool arquivoVazio(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    return arquivo.peek() == std::ifstream::traits_type::eof();
}

// Função para contar campeonatos existentes no arquivo de resultados
int contarCampeonatos(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    std::string linha;
    int contador = 0;

    while (std::getline(arquivo, linha)) {
        if (linha.find("=== CAMPEONATO") != std::string::npos) {
            contador++;
        }
    }

    arquivo.close();
    return contador;
}

int main() {
  srand(time(0)); // Inicializa a semente do gerador de números aleatórios
  std::vector<Exercito *> exercitos; // Lista de exércitos
  std::vector<std::string> nomesExercitos; // Lista de nomes dos exércitos
  std::string nome;
  int numExercitos;
  Data dataAtual = Data::dataAtual(); // Obtém a data atual

  std::cout << "Digite o número de exércitos: ";
  std::cin >> numExercitos;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer corretamente

  for (int i = 0; i < numExercitos; ++i) {
      std::cout << "Digite o nome do " << i + 1 << "º exército: ";
      std::getline(std::cin, nome); // Agora funciona sem comer a primeira letra
      nomesExercitos.push_back(nome);
      Exercito *exercito = new Exercito(nome);

    // Adiciona unidades ao exército
    for (int j = 0; j < 2; ++j) {
      exercito->adicionarUnidade(new Infantaria());
    }
    for (int j = 0; j < 2; ++j) {
      exercito->adicionarUnidade(new Veiculo());
    }
    exercito->adicionarUnidade(new Aeronave());

    exercitos.push_back(exercito);
  }

  // Abre o arquivo para salvar os resultados do campeonato
  std::ofstream arquivo("resultados_campeonato.txt", std::ios::app);
  if (arquivo.is_open()) {
      int numCampeonato;
      if (arquivoVazio("resultados_campeonato.txt")) {
          numCampeonato = 1;
      } else {
          numCampeonato = contarCampeonatos("resultados_campeonato.txt") + 1;
      }

      arquivo << "\n=== CAMPEONATO " << numCampeonato << " ===\n\n";

    // Simula e registra as batalhas entre os exércitos
    for (size_t i = 0; i < exercitos.size(); ++i) {
      for (size_t j = i + 1; j < exercitos.size(); ++j) {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char dataBatalha[20];
        strftime(dataBatalha, sizeof(dataBatalha), "%d/%m/%Y", ltm);

        Campanha *campanhaIda = new Campanha(exercitos[i], exercitos[j]);
        campanhaIda->simularBatalhas(1);

        Campanha *campanhaVolta = new Campanha(exercitos[j], exercitos[i]);
        campanhaVolta->simularBatalhas(1);

        arquivo << "Batalhas entre " << exercitos[i]->getNome() << " e "
                << exercitos[j]->getNome() << " em " << dataBatalha << "\n";

        delete campanhaIda;
        delete campanhaVolta;
      }
    }

    // Ordena os exércitos por vitórias e empates
    std::sort(exercitos.begin(), exercitos.end(), compararExercitosPorVitorias);

    // Exibe a classificação final no console
    std::cout << "\nClassificação Final:\n";
    for (size_t i = 0; i < exercitos.size(); ++i) {
      std::cout << i + 1 << "º Lugar: " << exercitos[i]->getNome() << " - "
              << exercitos[i]->getResultados() << "\n";
    }

    // Exibe a classificação final no arquivo
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char dataClassificacao[20];
    strftime(dataClassificacao, sizeof(dataClassificacao), "%d/%m/%Y", ltm);

    arquivo << "\nClassificação Final em " << dataClassificacao << ":\n";
    for (size_t i = 0; i < exercitos.size(); ++i) {
      arquivo << i + 1 << "º Lugar: " << exercitos[i]->getNome() << " - "
              << exercitos[i]->getResultados() << "\n";
    }

    // Processa e exibe o top 3 unidades mais destrutivas
    std::vector<Unidade *> todasUnidades;
    for (Exercito *exercito : exercitos) {
      for (Unidade *unidade : exercito->getUnidades()) {
        todasUnidades.push_back(unidade);
      }
    }

    std::sort(todasUnidades.begin(), todasUnidades.end(),
              compararUnidadesPorDestruicoes);

    std::cout << "\nTop 3 Unidades Mais Destrutivas:\n";
    arquivo << "\nTop 3 Unidades Mais Destrutivas:\n";
    for (int i = 0; i < 3 && i < todasUnidades.size(); ++i) {
      std::string nomeExercito;
      for (Exercito *exercito : exercitos) {
        for (Unidade *unidade : exercito->getUnidades()) {
          if (unidade == todasUnidades[i]) {
            nomeExercito = exercito->getNome();
            break;
          }
        }
      }

      int numeroUnidade = 0;
      for (Exercito *exercito : exercitos) {
        const std::vector<Unidade *> &unidades = exercito->getUnidades();
        for (size_t j = 0; j < unidades.size(); ++j) {
          if (unidades[j] == todasUnidades[i]) {
            numeroUnidade = j + 1;
            break;
          }
        }
      }

      std::string tipoUnidade;
      if (dynamic_cast<Infantaria *>(todasUnidades[i])) {
        tipoUnidade = "Infantaria";
      } else if (dynamic_cast<Veiculo *>(todasUnidades[i])) {
        tipoUnidade = "Veiculo";
      } else if (dynamic_cast<Aeronave *>(todasUnidades[i])) {
        tipoUnidade = "Aeronave";
      }

      std::cout << i + 1 << "º Lugar: Unidade " << numeroUnidade << " ("
                << tipoUnidade << ") do exército " << nomeExercito
                << " (Destruições = " << todasUnidades[i]->getDestruicoes()
                << ")\n";

      arquivo << i + 1 << "º Lugar: Unidade " << numeroUnidade << " ("
              << tipoUnidade << ") do exército " << nomeExercito
              << " (Destruições = " << todasUnidades[i]->getDestruicoes()
              << ")\n";
    }
  }
  arquivo.close();

  // Libera os exércitos alocados
  for (Exercito *exercito : exercitos) {
    delete exercito;
  }

  return 0;
}