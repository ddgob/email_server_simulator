#ifndef SERVIDORDEEMAILS_HPP
#define SERVIDORDEEMAILS_HPP

#include "ContaDeUsuario.hpp"

class ServidorDeEmails {
    public:
        ServidorDeEmails();
        ~ServidorDeEmails();

        ContaDeUsuario* isContaExistente(int IDaSerVerificado);

        void cadastrarConta(int IDaSerCadastrado);
        void removerConta(int IDaSerRemovido);
        void entregarEmail(int IDdoDestinatario, int prioridadeDoEmail, string mensagemDoEmail);
        void consultarCaixa(int IDaSerConsultado);

    private:
        ContaDeUsuario* primeiraContaDeUsuario;
        ContaDeUsuario* ultimaContaDeUsuario;

};

#endif