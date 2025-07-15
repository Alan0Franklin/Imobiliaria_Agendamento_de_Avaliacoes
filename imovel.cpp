#include <iostream>
#include <iomanip>
#include <sstream>
#include "imovel.hpp"
using namespace std;

int Imovel::nextId = 1;

Imovel::Imovel() {this->id = nextId++;}

Imovel::Imovel(string tipo, int proprietarioId, string endereco, double lat, double lng, double preco) {
    this->id = nextId++;
    this->tipo = tipo;
    this->proprietarioId = proprietarioId;
    this->endereco = endereco;
    this->lat = lat;
    this->lng = lng;
    this->preco = preco;
}

void Imovel::setTipo(string tipo) {this->tipo = tipo;}
void Imovel::setIdDoProprietario(int proprietarioId) {this->proprietarioId = proprietarioId;}
void Imovel::setEndereco(string endereco) {this->endereco = endereco;}
void Imovel::setLatitude(double lat) {this->lat = lat;}
void Imovel::setLongitude(double lng) {this->lng = lng;}
void Imovel::setPreco(double preco) {this->preco = preco;}
int Imovel::getId() {return this->id;}
string Imovel::getTipo() {return this->tipo;}
int Imovel::getIdDoProprietario() {return this->proprietarioId;}
string Imovel::getEndereco() {return this->endereco;}
double Imovel::getLatitude() const {return this->lat;}
double Imovel::getLongitude() const {return this->lng;}
double Imovel::getPreco() {return this->preco;}

void Imovel::exibirInformacoes() {
    cout << "# Imóvel " << this->id << endl;
    cout << "+ Tipo: " << this->tipo << ";";
    cout << " Id do Proprietário: " << this->proprietarioId << endl;
    cout << "+ Latitude: " << this->lat << ";";
    cout << " Longitude " << this->lng << endl;
    ostringstream oss;
    oss << fixed << setprecision(2) << this->preco;
    cout << "+ Preço: R$ " << oss.str() << endl;
    cout << "+ Endereço: " << this->endereco << endl;
}
