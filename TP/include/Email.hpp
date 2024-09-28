#ifndef EMAIL_HPP
#define EMAIL_HPP

#include <string>

using namespace std;

class Email {
    public:
        Email();
        Email(int prioridade_, string mensagem_);
        
        int getPrioridade();
        string getMensagem();

    private:
        int prioridade;
        string mensagem;
        
};

#endif