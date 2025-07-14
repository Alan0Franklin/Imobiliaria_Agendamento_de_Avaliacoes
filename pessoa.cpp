#include "pessoa.hpp"

void Pessoa::setNome(std::string nome) {this->nome = nome;}
void Pessoa::setTelefone(std::string telefone) {this->telefone = telefone;}
std::string Pessoa::getNome() {return this->nome;}
std::string Pessoa::getTelefone() {return this->telefone;}
int Pessoa::getId() const {return this->id;}