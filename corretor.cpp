#include <iostream>
#include "corretor.hpp"
using namespace std;

int Corretor::nextId = 1;

Corretor::Corretor() {this->id = nextId++;}

Corretor::Corretor(string nome, string telefone, int avaliador, double lat, double lng) {
    this->id = nextId++;
    this->nome = nome;
    this->telefone = telefone;
    this->avaliador = avaliador;
    this->lat = lat;
    this->lng = lng;
}

void Corretor::setAvaliador(int avaliador) {this->avaliador = avaliador;}
void Corretor::setLatitude(double lat) {this->lat = lat;}
void Corretor::setLongitude(double lng) {this->lng = lng;}
bool Corretor::getAvaliador() {return this->avaliador;}
double Corretor::getLatitude() {return this->lat;}
double Corretor::getLongitude() {return this->lng;}

void Corretor::exibirInformacoes() {
    cout << "# Corretor " << this->id << endl;
    cout << "+ Nome: " << this->nome << ";";
    cout << " Telefone: " << this->telefone << endl;
    cout << "+ Latitude: " << this->lat << ";";
    cout << " Longitude " << this->lng << endl;
    cout << "+ ";
    cout << (this->avaliador ? "A" : "Não a") << "valiador" << endl;
}