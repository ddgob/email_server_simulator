#ifndef ENTRADA_HPP
#define ENTRADA_HPP

#include "Email.hpp"

class Entrada {
    public:
        Entrada(int prioridade_, string mensagem_);

    private:
        Email email;
        Entrada* proximaEntrada;

    friend class CaixaDeEntrada;
};

#endif