#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Entidades.hpp"

using namespace std;

int main(){
    int qnt_corretor;
    cin >> qnt_corretor;
    vector<Corretor*> vetor_corretor;
    vetor_corretor.reserve(qnt_corretor);
    
    for (int i = 0; i < qnt_corretor; i++){
        // ler telefone, avaliador, lat, lng
        string telefone; int avaliador; double lat, lng;
        cin >> telefone >> avaliador >> lat >> lng;
        string nome;
        getline(cin >> ws, nome); // lê o restante da linha como nome completo
        Corretor* Co = new Corretor(nome, telefone, avaliador, lat, lng);
        if (Co != nullptr){vetor_corretor.push_back(Co);}
        else{
            cout << "> Erro ao inicializar corretor n°"<< i + 1 << endl;
            for (int j = 0; j < qnt_corretor; j++){delete vetor_corretor[j];}
            return 0;
        }
    }

    int qnt_cliente;
    cin >> qnt_cliente;
    vector<Cliente*> vetor_cliente;
    vetor_cliente.reserve(qnt_cliente);
    
    for (int i = 0; i < qnt_cliente; i++){
        // ler telefone
        string telefone;
        cin >> telefone;
        string nome;
        getline(cin >> ws, nome); // lê o restante da linha como nome completo
        Cliente* Cl = new Cliente(nome, telefone);
        if (Cl != nullptr){vetor_cliente.push_back(Cl);}
        else{
            cout << "> Erro ao inicializar cliente n°"<< i + 1 << endl;
            for (int j = 0; j < qnt_corretor; j++){delete vetor_corretor[j];}
            for (int j = 0; j < qnt_cliente; j++){delete vetor_cliente[j];}
            return 0;
        }
    }
    
    int qnt_imovel;
    cin >> qnt_imovel;
    vector<Imovel*> vetor_imovel;
    vetor_imovel.reserve(qnt_imovel);

    for (int i = 0; i < qnt_imovel; i++){
        // ler tipo, proprietarioId, lat, lng, preco
        string tipo; int proprietarioId; double lat, lng, preco;
        cin >> tipo >> proprietarioId >> lat >> lng >> preco;
        string endereco;
        getline(cin >> ws, endereco); // lê o restante da linha como endereço completo
        Imovel* I = new Imovel(tipo, proprietarioId, endereco, lat, lng, preco);
        if (I != nullptr){vetor_imovel.push_back(I);}
        else{
            cout << "> Erro ao inicializar imovel n°"<< i + 1 << endl;
            for (int j = 0; j < qnt_corretor; j++){delete vetor_corretor[j];}
            for (int j = 0; j < qnt_cliente; j++){delete vetor_cliente[j];}
            for (int j = 0; j < qnt_imovel; j++){delete vetor_imovel[j];}
            return 0;
        }
    }
    
    /*
    cout << "========= LISTA DE ENTIDADES =========\n";
    for (int j = 0; j < qnt_corretor; j++){vetor_corretor[j]->exibirInformacoes();}

    for (int j = 0; j < qnt_cliente; j++){vetor_cliente[j]->exibirInformacoes();}

    for (int j = 0; j < qnt_imovel; j++) {vetor_imovel[j]->exibirInformacoes();}
    */
   
    map<Corretor*, vector<Imovel*>, PessoaIDComparator> Agenda;
    for (int j = 0; j < qnt_corretor; j++){
        if (vetor_corretor[j]->getAvaliador()){
            Agenda[vetor_corretor[j]];
        }
    }
    if (Agenda.empty()){cout << "Nenhum avaliador disponível." << endl;}
    else{
        for (int j = 0; j < qnt_imovel; ){
            for (auto it = Agenda.begin(); it != Agenda.end(); ++it){
                vector<Imovel*>& Imoveis = it->second;
                Imoveis.push_back(vetor_imovel[j]);
                j++;
            }
        }
        imprimirAgenda(Agenda);
    }

    // Liberação de memória
    for (int j = 0; j < qnt_corretor; j++){delete vetor_corretor[j];}
    for (int j = 0; j < qnt_cliente; j++){delete vetor_cliente[j];}
    for (int j = 0; j < qnt_imovel; j++){delete vetor_imovel[j];}

    return 0;
}
