#ifndef ARQUIVODECOMANDOS_HPP
#define ARQUIVODECOMANDOS_HPP

#include <fstream>

using namespace std;

class ArquivoDeComandos {
    public:
        ArquivoDeComandos(string nomeDoArquivo);
        
        void ler();

    private:
        ifstream arquivoDeComandos;

        string lerMensagem(ifstream &arquivoDeComandos);

        bool isStringUmNumero(string string);
        
};

#endif