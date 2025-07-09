#ifndef ENTIDADES_HPP
#define ENTIDADES_HPP

#include <vector>
#include <string>
#include <map>

using namespace std;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Pessoa>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
class Pessoa{
protected:
    int id;
    string nome;
    string telefone;
public:
    virtual ~Pessoa() = default;
    void setNome(string nome);
    void setTelefone(string telefone);
    string getNome();
    string getTelefone();
    int getId() const;
    virtual void exibirInformacoes() = 0;
};

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Corretor>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
class Corretor : public Pessoa{
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
class Cliente : public Pessoa{
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
    int getId();
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

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Estruturas>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
struct PessoaIDComparator{bool operator()(const Corretor* a, const Corretor* b) const;};

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Funções>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Função de Haversine, para obter a distância em km entre duas coordenadas
double haversine(double lat1, double lng1, double lat2, double lng2);

// Função para imprimir agenda no final
void imprimirAgenda(map<Corretor*, vector<Imovel*>, PessoaIDComparator> &Agenda);

#endif
