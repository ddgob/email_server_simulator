#include "ContaDeUsuario.hpp"

/* constroi uma conta de usuario */
ContaDeUsuario::ContaDeUsuario(int ID_) {
    ID = ID_;
    proximaContaDeUsuario = nullptr;
}