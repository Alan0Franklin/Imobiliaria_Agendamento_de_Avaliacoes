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
    // Contrutores de Imóvel:
    Imovel();
    Imovel(std::string tipo, int proprietarioId, std::string endereco, double lat, double lng, double preco);
    
    // Atribuem valores aos atributos do Imóvel:
    void setTipo(std::string tipo);
    void setIdDoProprietario(int proprietarioId);
    void setEndereco(std::string endereco);
    void setLatitude(double lat);
    void setLongitude(double lng);
    void setPreco(double preco);

    // Obtem os atributos do Imóvel:
    int getId();
    std::string getTipo();
    int getIdDoProprietario();
    std::string getEndereco();
    double getLatitude() const;
    double getLongitude() const;
    double getPreco();
    void exibirInformacoes();
};

#endif
