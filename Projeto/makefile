# Variáveis
CXX = g++
CXXFLAGS = -std=c++11 -I./include

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Arquivos de origem
SRC = $(SRC_DIR)/main.cpp \
			$(SRC_DIR)/Batalha.cpp \
			$(SRC_DIR)/Campanha.cpp \
			$(SRC_DIR)/Data.cpp \
			$(SRC_DIR)/Exercito.cpp \
			$(SRC_DIR)/Unidade.cpp

# Arquivos objeto
OBJ = $(OBJ_DIR)/main.o \
			$(OBJ_DIR)/Batalha.o \
			$(OBJ_DIR)/Campanha.o \
			$(OBJ_DIR)/Data.o \
			$(OBJ_DIR)/Exercito.o \
			$(OBJ_DIR)/Unidade.o

# Nome do executável
EXEC = $(BIN_DIR)/CampanhaSimulada

# Alvo principal
all: $(BIN_DIR) $(EXEC)
	./$(EXEC) 

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

# Como compilar os arquivos .cpp em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Criar diretórios
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Limpeza
clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
