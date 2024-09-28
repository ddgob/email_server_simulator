#ifndef CONTADEUSUARIO_HPP
#define CONTADEUSUARIO_HPP

#include "CaixaDeEntrada.hpp"

class ContaDeUsuario {
    public:
        ContaDeUsuario(int ID_);

    private:
        int ID;
        CaixaDeEntrada caixaDeEntrada;
        ContaDeUsuario* proximaContaDeUsuario;

    friend class ServidorDeEmails;
};

#endif