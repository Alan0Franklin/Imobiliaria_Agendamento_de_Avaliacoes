#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <string>
#include <bits/stdc++.h>
#include "Entidades.hpp"

using namespace std;

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Pessoa>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Pessoa::setNome(string nome){this->nome = nome;}
void Pessoa::setTelefone(string telefone){this->telefone = telefone;}
string Pessoa::getNome(){return this->nome;}
string Pessoa::getTelefone(){return this->telefone;}
int Pessoa::getId() const {return this->id;}

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
int Imovel::getId(){return this->id;}
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
    ostringstream oss;
    oss << fixed << setprecision(2) << this->preco;
    cout << "+ Preco: R$ " << oss.str() << endl;
    cout << "+ Endereco: " << this->endereco << endl;
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Funções>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Função de Haversine, para obter a distância em km entre duas coordenadas
double haversine(double lat1, double lng1, double lat2, double lng2) {
    auto deg2rad = [](double d){return d * M_PI/180.0; };
    double dlat = deg2rad(lat2 - lat1);
    double dlng = deg2rad(lng2 - lng1);
    double a = pow(sin(dlat/2), 2) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * pow(sin(dlng/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return 6371.0 * c;
}

// Função para imprimir agenda no final
void imprimirAgenda(map<Corretor*, vector<Imovel*>, PessoaIDComparator> &Agenda){
    for (auto it = Agenda.begin(); it != Agenda.end(); it++){
        Corretor* Corretor = it->first;
        vector<Imovel*>& Imoveis = it->second;
        cout << "Corretor " << Corretor->getId() << endl;
        int qnt_imoveis = Imoveis.size();
        for (int j = 0; j < qnt_imoveis; j++){
            double sog = (haversine(Corretor->getLatitude(), Corretor->getLongitude(), Imoveis[j]->getLatitude(), Imoveis[j]->getLongitude()) * 2);
            int tempo = (int) sog;
            string horus = to_string(((tempo/60)+9)%24);
            if(horus.size() < 2){horus = "0" + horus;}
            string minutus = to_string(tempo%60);
            if(minutus.size() < 2){minutus = "0" + minutus;};
            //cout << setfill('0') << setw(2) << hora << ":"  << setw(2) << minuto;
            cout << horus<<":"<<minutus << " Imóvel " << Imoveis[j]->getId() << endl;
        }
        cout << "\n";
    }
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Estruturas>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool PessoaIDComparator::operator()(const Corretor* a, const Corretor* b) const {return a->getId() < b->getId();}
