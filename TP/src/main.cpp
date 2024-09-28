#include "ArquivoDeComandos.hpp"
#include "Email.hpp"
#include "Entrada.hpp"
#include "CaixaDeEntrada.hpp"
#include "ContaDeUsuario.hpp"
#include "ServidorDeEmails.hpp"

int main(int argc, char* argv[]) {

    /* instancia um arquivo de comandos lido do terminal*/
    ArquivoDeComandos arquivo = ArquivoDeComandos(argv[1]);
    /* le o arquivo de comandos instanciado */
    arquivo.ler();

    return 0;
}