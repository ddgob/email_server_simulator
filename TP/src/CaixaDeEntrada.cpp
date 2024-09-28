#include "CaixaDeEntrada.hpp"
#include "msgassert.h"

#include <iostream>

using namespace std;

/* constroi uma caixa de entrada */
CaixaDeEntrada::CaixaDeEntrada() {
    primeiraEntrada = nullptr;
    ultimaEntrada = nullptr;
}

CaixaDeEntrada::~CaixaDeEntrada() {
    limpar();
}

/* adiciona um entrada (alocado dinamicamente 
e construido com os parametros passados 
para a funcao) segundo a ordem de 
prioridade na caixa de entrada sobre a 
qual o metodo eh chamado */
void CaixaDeEntrada::adicionarEmail(int prioridade_, string mensagem_) {
    Entrada* entradaASerInserida = new Entrada(prioridade_, mensagem_);

    /* testa os 4 casos de inserção em uma fila 
    de prioridade encadeada (que eh a caixa de 
    entrada) e faz a inserção correspondente */
    if (isVazia()) {
        inserirEmailEmCaixaVazia(entradaASerInserida);
    } else if (entradaASerInserida->email.getPrioridade() > primeiraEntrada->email.getPrioridade()) {
        inserirEmailNoInicio(entradaASerInserida);
    } else if (entradaASerInserida->email.getPrioridade() <= ultimaEntrada->email.getPrioridade()) {
        inserirEmailNoFinal(entradaASerInserida);
    } else {
        inserirEmailNoMeio(entradaASerInserida);
    }
}

/* remove a primeira entrada da caixa de 
entrada sobre a qual o metodo eh chamado
(consequentemente removendo tambem o email)
e retorna true. Caso a caixa esteja vazia
e nao seja possivel remover nenhuma 
entrada, retorna falso*/
bool CaixaDeEntrada::removerEmail() {
    /* testa se a caixa esta vazia */
    if(!isVazia()) {
        Entrada *aux = primeiraEntrada;
        /* remove a primeira entrada 
        da caixa de entrada */
        primeiraEntrada = primeiraEntrada->proximaEntrada;
        if (primeiraEntrada == nullptr) {
            ultimaEntrada = primeiraEntrada;
        }
        /* desaloca memoria da entrada que 
        foi alocada dinamicamente */ 
        delete aux;
        return true;
    }
    return false; 
}

/* remove todas as entradas da caixa de 
entrada (e consequentemente os emails tambem) 
sobre a qual o metodo eh chamado */
void CaixaDeEntrada::limpar() {
    while (removerEmail()) {}
}

/* retorna a mensagem do email
da primeira entrada da caixa de 
entrada */
string CaixaDeEntrada::getPrimeiroEmail() {
    return primeiraEntrada->email.getMensagem();
}

/* verifica se a caixa de entrada está
vazia, retornando true caso esteja ou
false caso contrario*/
bool CaixaDeEntrada::isVazia() {
    if (primeiraEntrada != nullptr) {
        return false;
    }
    return true;
}

/* insere uma entrada (e consequentemente 
um email) no inicio da caixa de entrada */
void CaixaDeEntrada::inserirEmailNoInicio(Entrada* entradaASerInserida) {
    entradaASerInserida->proximaEntrada = primeiraEntrada;
    primeiraEntrada = entradaASerInserida;
}

/* insere uma entrada (e consequentemente 
um email) no final da caixa de entrada */
void CaixaDeEntrada::inserirEmailNoFinal(Entrada* entradaASerInserida) {
    ultimaEntrada->proximaEntrada = entradaASerInserida;
    ultimaEntrada = entradaASerInserida;
}

/* insere uma entrada (e consequentemente 
um email) no meio da caixa de entrada */
void CaixaDeEntrada::inserirEmailNoMeio(Entrada* entradaASerInserida) {
    Entrada* aux = primeiraEntrada->proximaEntrada;
    Entrada* auxAnterior = primeiraEntrada;

    /* itera sobre a fila de prioridade 
    encadeada (que eh a caixa de entrada) 
    inserindo a nova entrada uma posicao 
    antes primeira da posicao que possuir 
    uma prioridade menor do que a prioridade 
    da entrada que se deseja inserir */
    while (aux != nullptr) {
        if (entradaASerInserida->email.getPrioridade() > aux->email.getPrioridade()) {
            entradaASerInserida->proximaEntrada = aux;
            auxAnterior->proximaEntrada = entradaASerInserida;
            return;
        }
        auxAnterior = aux;
        aux = aux->proximaEntrada;
    }
}

/* insere uma entrada (e consequentemente 
um email) em uma caixa de entrada vazia */
void CaixaDeEntrada::inserirEmailEmCaixaVazia(Entrada* entradaASerInserida) {
    primeiraEntrada = entradaASerInserida;
    ultimaEntrada = entradaASerInserida;
}