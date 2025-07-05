#include <iostream>
#include <limits>
#include "Entidades.hpp"

using namespace std;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Pessoas>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Pessoas::setNome(string nome){this->nome = nome;}
void Pessoas::setTelefone(string telefone){this->telefone = telefone;}
string Pessoas::getNome(){return this->nome;}
string Pessoas::getTelefone(){return this->telefone;}
int Pessoas::getId(){return this->id;}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Corretor>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int Corretor::nextId = 1;
Corretor::Corretor(){
    this->id = nextId;
    nextId++;
}
Corretor::Corretor(string nome, string telefone, int avaliador, double lat, double lng){
    this->id = nextId;
    nextId++;
    this->nome = nome;
    this->telefone = telefone;
    this->avaliador = avaliador;
    this->lat = lat;
    this->lng = lng;
}
void Corretor::setAvaliador(int avaliador){this->avaliador = avaliador;}
void Corretor::setLatitude(double lat){this->lat = lat;}
void Corretor::setLongitude(double lng){this->lng = lng;}
bool Corretor::getAvaliador(){return this->avaliador;}
double Corretor::getLatitude(){return this->lat;}
double Corretor::getLongitude(){return this->lng;}
void Corretor::exibirInformacoes(){
    cout << "# Corretor " << this->id << endl;
    cout << "+ Nome: " << this->nome << ";";
    cout << " Telefone: " << this->telefone << endl;
    cout << "+ Latitude: " << this->lat << ";";
    cout << " Longitude " << this->lng << endl;
    cout << "+ ";
    if (this->avaliador){cout << "A";}
    else{cout << "Não a";}
    cout << "valiador" << endl;
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Cliente>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int Cliente::nextId = 1;
Cliente::Cliente(){
    this->id = nextId;
    nextId++;
}
Cliente::Cliente(string nome, string telefone){
    this->id = nextId;
    nextId++;
    this->nome = nome;
    this->telefone = telefone;
}
void Cliente::exibirInformacoes(){
    cout << "# Cliente " << this->id << endl;
    cout << "+ Nome: " << this->nome << ";";
    cout << " Telefone: " << this->telefone << endl;
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Imóvel>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int Imovel::nextId = 1;
Imovel::Imovel(){
    this->id = nextId;
    nextId++;
}
Imovel::Imovel(string tipo, int proprietarioId, string endereco, double lat, double lng, double preco){
    this->id = nextId;
    nextId++;
    this->tipo = tipo;
    this->proprietarioId = proprietarioId;
    this->endereco = endereco;
    this->lat = lat;
    this->lng = lng;
    this->preco = preco;
}
void Imovel::setTipo(string tipo){this->tipo = tipo;}
void Imovel::setIdDoProprietario(int proprietarioId){this->proprietarioId = proprietarioId;}
void Imovel::setEndereco(string endereco){this->endereco = endereco;}
void Imovel::setLatitude(double lat){this->lat = lat;}
void Imovel::setLongitude(double lng){this->lng = lng;}
void Imovel::setPreco(double preco){this->preco = preco;}
string Imovel::getTipo(){return this->tipo;}
int Imovel::getIdDoProprietario(){return this->proprietarioId;}
string Imovel::getEndereco(){return this->endereco;}
double Imovel::getLatitude(){return this->lat;} 
double Imovel::getLongitude(){return this->lng;}
double Imovel::getPreco(){return this->preco;}
void Imovel::exibirInformacoes(){
    cout << "# Imovel " << this->id << endl;
    cout << "+ Tipo: " << this->tipo << ";";
    cout << " Id do Proprietario: " << this->proprietarioId << endl;
    cout << "+ Latitude: " << this->lat << ";";
    cout << " Longitude " << this->lng << endl;
    cout << "+ Preco: R$ " << this->preco << endl;
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Funções>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>