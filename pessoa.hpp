#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>

class Pessoa {
protected:
    int id;
    std::string nome;
    std::string telefone;
public:
    virtual ~Pessoa() = default;
    void setNome(std::string nome);
    void setTelefone(std::string telefone);
    std::string getNome();
    std::string getTelefone();
    int getId() const;
    virtual void exibirInformacoes() = 0;
};

#endif