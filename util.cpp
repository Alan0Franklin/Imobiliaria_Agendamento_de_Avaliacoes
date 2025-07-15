#include <cmath>
#include <iostream>
#include <iomanip>
#include "util.hpp"
using namespace std;

bool PessoaIDComparator::operator()(const shared_ptr<Corretor> a, const shared_ptr<Corretor> b) const {return a->getId() < b->getId();}

double haversine(double lat1, double lng1, double lat2, double lng2) {
    const double pi = 3.141592653589793;
    auto deg2rad = [&](double d){return d * pi / 180.0;};
    double dlat = deg2rad(lat2 - lat1);
    double dlng = deg2rad(lng2 - lng1);
    double a = pow(sin(dlat / 2), 2) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * pow(sin(dlng / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return 6371.0 * c;
}

void imprimirAgenda(map<shared_ptr<Corretor>, vector<shared_ptr<Imovel>>, PessoaIDComparator>& Agenda) {
    for (auto it = Agenda.begin(); it != Agenda.end(); it++) {
        shared_ptr<Corretor> corretor = it->first;
        vector<shared_ptr<Imovel>>& imoveis = it->second;

        cout << "Corretor " << corretor->getId() << endl;
        int qnt = imoveis.size();
        int tempo = 540;
        double lat = corretor->getLatitude(), lng = corretor->getLongitude();
        list<shared_ptr<Imovel>> lista_imoveis;
        for (int j = 0; j < qnt; j++) {lista_imoveis.push_back(imoveis[j]);}
        for (int j = 0; j < qnt; j++) {
            auto it_atual = imovelmaisproximo(lat, lng, lista_imoveis);
            shared_ptr<Imovel> Imovel = (*it_atual);
            double lat2 = Imovel->getLatitude(), lng2 = Imovel->getLongitude();
            double dist = haversine(lat, lng, lat2, lng2) * 2;
            int horario = (int) dist + tempo;
            int hora = horario / 60 % 24, minuto = horario % 60;
            cout << setfill('0') << setw(2) << hora << ":" << setw(2) << minuto << " Imóvel " << Imovel->getId() << endl;
            tempo = 60 + horario;
            lat = lat2;
            lng = lng2;
            lista_imoveis.erase(it_atual);
        }

        // Somente imprime uma quebra de linha SE não for o último corretor
        if (next(it) != Agenda.end()) {cout << "\n";}
    }
}

list<shared_ptr<Imovel>>::iterator imovelmaisproximo(double lat, double lng, list<shared_ptr<Imovel>>& lista_imoveis) {
    auto it_atual = lista_imoveis.begin(), it_comparado = lista_imoveis.begin();
    double dist_atual = haversine(lat, lng, (*it_atual)->getLatitude(), (*it_atual)->getLongitude());
    for (it_comparado++; it_comparado != lista_imoveis.end(); it_comparado++) {
        double dist_comparado = haversine(lat, lng, (*it_comparado)->getLatitude(), (*it_comparado)->getLongitude());
        if (dist_comparado < dist_atual) {
            dist_atual = dist_comparado;
            it_atual = it_comparado;
        }
    }
    return it_atual;
}
