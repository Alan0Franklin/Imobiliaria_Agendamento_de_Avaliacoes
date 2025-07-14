#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include "pessoa.hpp"

class Cliente : public Pessoa {
private:
    static int nextId;
public:
    Cliente();
    Cliente(std::string nome, std::string telefone);
    void exibirInformacoes();
};

#endif