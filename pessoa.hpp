#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>

class Pessoa {
protected:
    int id;
    std::string nome;
    std::string telefone;
public:
    // Destrutor de Pessoa:
    virtual ~Pessoa() = default;
    
    // Atribuem valores aos atributos da Pessoa:
    void setNome(std::string nome);
    void setTelefone(std::string telefone);

    // Obtem os atributos da Pessoa:
    std::string getNome();
    std::string getTelefone();
    int getId() const;
    virtual void exibirInformacoes() = 0;
};

#endif
