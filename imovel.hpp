#ifndef IMOVEL_HPP
#define IMOVEL_HPP

#include <string>

class Imovel {
private:
    static int nextId;
    int id;
    std::string tipo;
    int proprietarioId;
    std::string endereco;
    double lat, lng, preco;
public:
    Imovel();
    Imovel(std::string tipo, int proprietarioId, std::string endereco, double lat, double lng, double preco);
    int getId();
    void setTipo(std::string tipo);
    void setIdDoProprietario(int proprietarioId);
    void setEndereco(std::string endereco);
    void setLatitude(double lat);
    void setLongitude(double lng);
    void setPreco(double preco);
    std::string getTipo();
    int getIdDoProprietario();
    std::string getEndereco();
    double getLatitude();
    double getLongitude();
    double getPreco();
    void exibirInformacoes();
};

#endif