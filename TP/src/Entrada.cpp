#include "Entrada.hpp"

/* constroi uma entrada */
Entrada::Entrada(int prioridade_, string mensagem_) {
    email = Email(prioridade_, mensagem_);
    proximaEntrada = nullptr;
}