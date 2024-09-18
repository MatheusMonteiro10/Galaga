/*
#include <iostream>
#include <fstream>  // Necessário para manipulação de arquivos
#include <random>

int main() {
    const int width = 200;
    const int height = 55;

    // Inicializa o motor com uma semente de alta qualidade
    std::random_device rd;
    std::mt19937 gen(rd());

    // Distribuição uniforme para escolher entre 0 e 99 (mais valores para espaços)
    std::uniform_int_distribution<> distrib(0, 99);

    // Cria e abre o arquivo de saída
    std::ofstream outfile("background.txt");

    // Verifica se o arquivo foi aberto corretamente
    if (!outfile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!" << std::endl;
        return 1;
    }

    // Gera e escreve no arquivo a "tela" de altura x largura
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int random_value = distrib(gen);  // Gera um número aleatório entre 0 e 99

            if (random_value == 0) {
                outfile << '+';
            } else if (random_value == 10) {
                outfile << '.';
            } else {
                outfile << ' ';  // Espaço em branco (8 em 10 chances)
            }
        }
        outfile << '\n'; 
    }

    // Fecha o arquivo
    outfile.close();

    return 0;
}
*/