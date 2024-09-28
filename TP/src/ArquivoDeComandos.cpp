#include "ArquivoDeComandos.hpp"
#include "msgassert.h"
#include "ServidorDeEmails.hpp"

#include <iostream>

using namespace std;

/* contstroi um arquivo de ArquivoDeComandos */
ArquivoDeComandos::ArquivoDeComandos(string nomeDoArquivo) {
    arquivoDeComandos.open(nomeDoArquivo);

    /* verifica se arquivo de comandos
    foi aberto corretamente e retorna erro
    caso nao tenha sido */
    erroAssert(arquivoDeComandos.is_open() == true,
    "Erro ao tentar abrir arquivo de comandos");
}

/* le um arquivo de arquivo de comandos
executando os comandos simultaneamente. 
Retorna mensagens de erro de input do
usuario ou erros de comandos impossiveis
de serem executados
*/
void ArquivoDeComandos::ler() {
    string comando, testID, testPrioridade, mensagem;
    int id, prioridade;
    ServidorDeEmails servidor = ServidorDeEmails();

    while (arquivoDeComandos >> comando) {
        if (comando == "CADASTRA") {
            arquivoDeComandos >> testID;

            /* testa se id lido esta no intervalo
            correto e se eh do tipo int */
            erroAssert(isStringUmNumero(testID),
            "Nao foi possivel fazer o cadastro todos os IDs precisam ser do tipo inteiro");
            id = stoi(testID);
            erroAssert(0 <= id && id <= 1000000,
            "Nao foi possivel fazer o cadastro pois todos os IDs precisam estar no intervalo [0, 10^6]");

            servidor.cadastrarConta(id);

        } else if (comando == "REMOVE") {
            arquivoDeComandos >> testID;

            /* testa se id lido esta no intervalo
            correto e se eh do tipo int */
            erroAssert(isStringUmNumero(testID),
            "Nao foi possivel fazer o cadastro todos os IDs precisam ser do tipo inteiro");
            id = stoi(testID);
            erroAssert(0 <= id && id <= 1000000,
            "Nao foi possivel fazer o cadastro pois todos os IDs precisam estar no intervalo [0, 10^6]");

            servidor.removerConta(id);

        } else if (comando == "ENTREGA") {
            arquivoDeComandos >> testID >> testPrioridade;

            /* testa se id lido esta no intervalo
            correto e se eh do tipo int */
            erroAssert(isStringUmNumero(testID),
            "Nao foi possivel fazer o cadastro todos os IDs precisam ser do tipo inteiro");
            id = stoi(testID);
            erroAssert(0 <= id && id <= 1000000,
            "Nao foi possivel fazer o cadastro pois todos os IDs precisam estar no intervalo [0, 10^6]");

            /* testa se prioridade lida esta no
            intervalo correto e se eh do tipo int */
            erroAssert(isStringUmNumero(testPrioridade),
            "Nao foi possivel fazer o cadastro todos os IDs precisam ser do tipo inteiro");
            prioridade = stoi(testPrioridade);
            erroAssert(0 <= prioridade && prioridade <= 9,
            "Nao foi possivel fazer a entrega pois todas as prioridades precisam estar no intervalo [0, 9]");

            /* le mensagem do arquivo retirando 
            a palavra reservada "FIM" da string*/
            mensagem = lerMensagem(arquivoDeComandos);

            servidor.entregarEmail(id, prioridade, mensagem);

        }else if (comando == "CONSULTA") {
            arquivoDeComandos >> testID;

            /* testa se id lido esta no intervalo
            correto e se eh do tipo int */
            erroAssert(isStringUmNumero(testID),
            "Nao foi possivel fazer o cadastro todos os IDs precisam ser do tipo inteiro");
            id = stoi(testID);
            erroAssert(0 <= id && id <= 1000000,
            "Nao foi possivel fazer o cadastro pois todos os IDs precisam estar no intervalo [0, 10^6]");

            servidor.consultarCaixa(id);

        } else {
            /* retorna erro de comando lido nao for 
            dos tipos CADASTRA, REMOVE, ENTREGA ou 
            CONSULTA */
            erroAssert(false,
            "Nao foi possivel ler o arquivo pois todos os comandos precisam ser do tipo: CADASTRA, REMOVE, ENTREGA ou CONSULTA");
        }
    }
    arquivoDeComandos.close();
}

/* le uma mensagem do arquivo de
comandos e retorna ela retirando 
a palavra reservada "FIM" do final*/
string ArquivoDeComandos::lerMensagem(ifstream &arquivoDeComandos) {
    string temp, mensagem;
    arquivoDeComandos >> temp;

    /* testa se a mensagem do Email 
    eh vaizio e retorna erro caso
    seja */
    erroAssert(temp != "FIM",
    "Mensagem do email vazio, por favor preencha o email com uma mensagem");

    /* le palavras do arquivo de comandos ate 
    chegar na palavra reservada "FIM" */
    while (temp != "FIM") {
        /* adiciona palavra lida do arquivo de 
        comandos a mensagem a ser retornada */
        mensagem += temp + " ";
        arquivoDeComandos >> temp;
    }

    /* remove o ultimo espaco em 
    branco da string */
    mensagem.pop_back();
    return mensagem;
}

/* itera sobre uma string verificando 
se todos os characters sao inteiros 
retornando falso caso um nao seja*/
bool ArquivoDeComandos::isStringUmNumero(string stringAnalisada) {
    for (long unsigned int i = 0; i < stringAnalisada.length(); i++) {
        /* testa se o character daquela 
        iteracao eh um digito retornando 
        falso caso nao seja  */
        if (isdigit(stringAnalisada[i]) == 0) {
            return false;
        }
    }
    return true;
}
