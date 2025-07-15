#ifndef CORRETOR_HPP
#define CORRETOR_HPP

#include <string>
#include "pessoa.hpp"

class Corretor : public Pessoa {
private:
    static int nextId;
    bool avaliador;
    double lat, lng;
public:
    // Contrutores de Corretor:
    Corretor();
    Corretor(std::string nome, std::string telefone, int avaliador, double lat, double lng);
    
    // Atribuem valores aos atributos do Corretor:
    void setAvaliador(int avaliador);
    void setLatitude(double lat);
    void setLongitude(double lng);
    
    // Obtem os atributos do Corretor:
    bool getAvaliador();
    double getLatitude();
    double getLongitude();
    void exibirInformacoes();
};

#endif
