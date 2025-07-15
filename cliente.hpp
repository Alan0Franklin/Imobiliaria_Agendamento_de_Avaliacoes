#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include "pessoa.hpp"

class Cliente : public Pessoa {
private:
    static int nextId;
public:
    // Contrutores de Cliente:
    Cliente();
    Cliente(std::string nome, std::string telefone);
    
    // Obtem os atributos do Cliente:
    void exibirInformacoes();
};

#endif
