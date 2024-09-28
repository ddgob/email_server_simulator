#include "ServidorDeEmails.hpp"
#include "msgassert.h"

#include <iostream>

/* constroi um servidor sem contas*/
ServidorDeEmails::ServidorDeEmails() {
    primeiraContaDeUsuario = nullptr;
    ultimaContaDeUsuario = nullptr;
}

ServidorDeEmails::~ServidorDeEmails() {
    ContaDeUsuario *aux = primeiraContaDeUsuario;
    ContaDeUsuario *auxDelete;
    while (aux != nullptr) {
        primeiraContaDeUsuario = primeiraContaDeUsuario->proximaContaDeUsuario;
        if (aux == ultimaContaDeUsuario) {
            ultimaContaDeUsuario = primeiraContaDeUsuario;
        }
        auxDelete = aux;
        aux = aux->proximaContaDeUsuario;
        delete auxDelete;
    }
}

/* testa se existe uma conta com ID 
igual ao ID passado como parametro e 
retorna um ponteiro para essa conta 
se ela existir. Caso contratio retorna 
nullptr */
ContaDeUsuario* ServidorDeEmails::isContaExistente(int IDaSerVerificado) {
    ContaDeUsuario *aux = primeiraContaDeUsuario;

    /* itera sobre a lista encadeada (que 
    eh o servidor)*/
    while (aux != nullptr) {
        /* verifica se o ID da conta daquela 
        iteracao eh igual ao ID passado como 
        parametro */
        if (aux->ID == IDaSerVerificado) {
            /* retorna um ponteiro para a 
            conta com ID igual ao ID passado 
            como parametro */
            return aux;
        }
        aux = aux->proximaContaDeUsuario;
    }
    /* retorna nullptr caso, apos ter iterado 
    por todas as contas da lista encadeada, 
    nao houver conta que tenha ID igual ao ID 
    passado como parametro */
    return nullptr;
}

/* cadastra uma nova conta na lista 
encadeada de contas (que eh o servidor) 
imprimindo uma mensagem de sucesso cadastro. 
Caso a conta ja esteja cadastrada uma mensagem 
de erro caso a contaja exista*/
void ServidorDeEmails::cadastrarConta(int IDaSerCadastrado) {
    
    /* testa se a conta a ser cadastrada 
    ja existe na lista encadeada de contas 
    (que eh o servidor) */
    if (isContaExistente(IDaSerCadastrado)) {
        /* Caso exista, imprime uma 
        mensagem de erro */
        cout << "ERRO: CONTA " << IDaSerCadastrado << " JA EXISTENTE" << endl;
    } else {
        /* caso nao exista insere a conta a ser
        cadastrada no inicio da lista */

        /* aloca memoria para conta a 
        ser cadastrada dinamicamente */
        ContaDeUsuario *novaContaDeUsuario = new ContaDeUsuario(IDaSerCadastrado);

        /* testa se a insercao da conta a 
        ser cadastrada vai ser em uma lista 
        vazia ou em uma lista que ja contem 
        contas cadastradas */
        if (primeiraContaDeUsuario == nullptr) {
            primeiraContaDeUsuario = novaContaDeUsuario;
        } else {
            ultimaContaDeUsuario->proximaContaDeUsuario = novaContaDeUsuario;
        }

        ultimaContaDeUsuario = novaContaDeUsuario;

        /* imprime mensagem confirmando 
        cadastro da conta */
        cout << "OK: CONTA " << IDaSerCadastrado << " CADASTRADA" << endl;
    }
}

/* remove a conta que tem o ID igual 
ao ID passado como parametro da lista 
de encadeada de contas (que eh o 
servidor) e imprime uma mensagem de sucesso. 
Caso a conta nao exista, imprime uma mensagem 
de erro */
void ServidorDeEmails::removerConta(int IDaSerRemovido) {
    ContaDeUsuario *aux = primeiraContaDeUsuario;
    ContaDeUsuario *auxAnterior;

    /* itera sobre a lista encadeada de 
    contas (que eh o servidor) e remove 
    a conta de acordo com a posicao da 
    conta na lista */
    while (aux != nullptr) {
        if (aux->ID == IDaSerRemovido) {
            bool isContaASerRemovidaPrimeiraConta = aux == primeiraContaDeUsuario;
            bool isContaASerRemovidaUltimaConta = aux == ultimaContaDeUsuario;

            /* testa se a conta a ser removida 
            eh a primeira ou ultima conta e faz a 
            remocao correspondente*/
            if (isContaASerRemovidaPrimeiraConta) {
                primeiraContaDeUsuario = primeiraContaDeUsuario->proximaContaDeUsuario;
                if (isContaASerRemovidaUltimaConta) {
                    ultimaContaDeUsuario = primeiraContaDeUsuario;
                }
            } else {
                auxAnterior->proximaContaDeUsuario = aux->proximaContaDeUsuario;
                if (isContaASerRemovidaUltimaConta) {
                    ultimaContaDeUsuario = auxAnterior;
                }
            }

            /* remove todos os emails da caixa 
            de entrada da conta a ser removida */
            aux->caixaDeEntrada.limpar();

            /* desaloca memoria da conta que 
            foi alocada dinamicamente */
            delete aux;

            /* imprime mensagem confirmando 
            remocao da conta e retorna*/
            cout << "OK: CONTA " << IDaSerRemovido << " REMOVIDA" << endl;
            return;
        }
        auxAnterior = aux;
        aux = aux->proximaContaDeUsuario;
    }
    /* imprime mensagem de erro caso, 
    apos iterar sobre todas as contas da 
    lista encadeada, nao seja encontrado 
    nenhuma conta com ID igual o ID 
    passado como parametro */
    cout << "ERRO: CONTA " << IDaSerRemovido << " NAO EXISTE" << endl;
}

/* entrega email construido com a prioridade 
e mensagem passados como parametro para o 
destinatario passado como parametro e imprime 
uma mensagem de sucesso de entrega. Caso o 
destinatario nao exista, imprime mensagem de 
erro*/
void ServidorDeEmails::entregarEmail(int IDdoDestinatario, int prioridade, string mensagem) {
    /* testa se a conta a qual se deseja entregar
     o email existe */
    if (ContaDeUsuario *contaDestinataria = isContaExistente(IDdoDestinatario)) {
        /* Caso exista, faz a entrega do email 
        e imprime mensagem de sucesso de entrega */
        contaDestinataria->caixaDeEntrada.adicionarEmail(prioridade, mensagem);
        cout << "OK: MENSAGEM PARA " << IDdoDestinatario << " ENTREGUE" << endl;
    } else {
        /* Caso nao exista, imprime 
        mensagem de erro de entrega */
        cout << "ERRO: CONTA " << IDdoDestinatario << " NAO EXISTE" << endl;
    }
}

/* imprime primeiro email da caixa de 
entrada da conta que tem ID igual ao 
ID passado como parametro. Caso a caixa 
de entrada nao tenha emails para serem 
lidos ou a conta nao exista, imprime 
mensagem de erro */
void ServidorDeEmails::consultarCaixa(int IDaSerConsultado) {
    if (ContaDeUsuario *conta = isContaExistente(IDaSerConsultado)) {
        CaixaDeEntrada *caixa = &conta->caixaDeEntrada;
        if (!caixa->isVazia()) {
            cout << "CONSULTA " << IDaSerConsultado << ": " << caixa->getPrimeiroEmail() << endl;
            caixa->removerEmail();
        } else {
            cout << "CONSULTA " << IDaSerConsultado << ": CAIXA DE ENTRADA VAZIA" << endl;
        }
        return;
    }
    cout << "ERRO: CONTA " << IDaSerConsultado << " NAO EXISTE" << endl;
}