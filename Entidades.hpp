#ifndef ENTIDADES_HPP
#define ENTIDADES_HPP

#include <string>

using namespace std;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Pessoas>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
class Pessoas{
protected:
    int id;
    string nome;
    string telefone;
public:
    virtual ~Pessoas() = default;
    void setNome(string nome);
    void setTelefone(string telefone);
    string getNome();
    string getTelefone(); 
    int getId();
    virtual void exibirInformacoes() = 0;
};

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Corretor>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
class Corretor : public Pessoas{
private:
    static int nextId;
    bool avaliador;
    double lat, lng;
public:
    Corretor();
    Corretor(string nome, string telefone, int avaliador, double lat, double lng);
    void setAvaliador(int avaliador);
    void setLatitude(double lat);
    void setLongitude(double lng);
    bool getAvaliador();
    double getLatitude(); 
    double getLongitude(); 
    void exibirInformacoes();
};

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Cliente>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
class Cliente : public Pessoas{
private:
    static int nextId;
public:
    Cliente();
    Cliente(string nome, string telefone);
    void exibirInformacoes();
};

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Imóvel>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
class Imovel{
private:
    static int nextId;
    int id;
    string tipo;
    int proprietarioId;
    string endereco;
    double lat, lng, preco;
public:
    Imovel();
    Imovel(string tipo, int proprietarioId, string endereco, double lat, double lng, double preco);
    ~Imovel() = default;
    void setTipo(string tipo);
    void setIdDoProprietario(int proprietarioId);
    void setEndereco(string endereco);
    void setLatitude(double lat);
    void setLongitude(double lng);
    void setPreco(double preco);
    string getTipo();
    int getIdDoProprietario();
    string getEndereco();
    double getLatitude(); 
    double getLongitude();
    double getPreco();
    void exibirInformacoes();
};

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Funções>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


#endif
