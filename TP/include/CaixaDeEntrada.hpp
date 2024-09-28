#ifndef CAIXADEENTRADA_HPP
#define CAIXADEENTRADA_HPP

#include "Entrada.hpp"

class CaixaDeEntrada {
    public:
        CaixaDeEntrada();
        ~CaixaDeEntrada();

        void adicionarEmail(int prioridadeDoEmail_, string mensagemDoEmail_);
        bool removerEmail();

        void limpar();

        string getPrimeiroEmail();

        bool isVazia();

    private:
        Entrada* primeiraEntrada;
        Entrada* ultimaEntrada;

        void inserirEmailNoInicio(Entrada* entradaASerInserida);
        void inserirEmailNoFinal(Entrada* entradaASerInserida);
        void inserirEmailNoMeio(Entrada* entradaASerInserida);
        void inserirEmailEmCaixaVazia(Entrada* entradaASerInserida);


};

#endif
