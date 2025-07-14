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
    Corretor();
    Corretor(std::string nome, std::string telefone, int avaliador, double lat, double lng);
    void setAvaliador(int avaliador);
    void setLatitude(double lat);
    void setLongitude(double lng);
    bool getAvaliador();
    double getLatitude();
    double getLongitude();
    void exibirInformacoes();
};

#endif