#include "Email.hpp"

/* constroi um email */
Email::Email() {}

/* constroi um email com a prioridade e 
a mensagem passadas por parametro */
Email::Email(int prioridade_, string mensagem_) {
    prioridade = prioridade_;
    mensagem = mensagem_;
}

/* retorna a prioridade do email */
int Email::getPrioridade() {
    return prioridade;
}

/* retorna a mensagem do email */
string Email::getMensagem() {
    return mensagem;
}