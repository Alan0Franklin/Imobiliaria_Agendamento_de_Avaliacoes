#include <iostream>
#include "cliente.hpp"
using namespace std;

int Cliente::nextId = 1;

Cliente::Cliente() {this->id = nextId++;}

Cliente::Cliente(string nome, string telefone) {
    this->id = nextId++;
    this->nome = nome;
    this->telefone = telefone;
}

void Cliente::exibirInformacoes() {
    cout << "# Cliente " << this->id << endl;
    cout << "+ Nome: " << this->nome << ";";
    cout << " Telefone: " << this->telefone << endl;
}