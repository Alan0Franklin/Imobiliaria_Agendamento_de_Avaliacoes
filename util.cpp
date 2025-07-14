#include <cmath>
#include <iostream>
#include <iomanip>
#include "util.hpp"
using namespace std;

bool PessoaIDComparator::operator()(const Corretor* a, const Corretor* b) const {return a->getId() < b->getId();}

double haversine(double lat1, double lng1, double lat2, double lng2) {
    const double pi = 3.141592653589793;
    auto deg2rad = [&](double d){return d * pi / 180.0;};
    double dlat = deg2rad(lat2 - lat1);
    double dlng = deg2rad(lng2 - lng1);
    double a = pow(sin(dlat / 2), 2) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * pow(sin(dlng / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return 6371.0 * c;
}

void imprimirAgenda(map<Corretor*, vector<Imovel*>, PessoaIDComparator>& Agenda) {
    for (auto it = Agenda.begin(); it != Agenda.end(); ++it) {
        Corretor* corretor = it->first;
        vector<Imovel*>& imoveis = it->second;

        cout << "Corretor " << corretor->getId() << endl;
        int qnt = imoveis.size();
        int tempo = 9 * 60;
        double lat = corretor->getLatitude(), lng = corretor->getLongitude();

        for (int j = 0; j < qnt; j++) {
            double lat2 = imoveis[j]->getLatitude(), lng2 = imoveis[j]->getLongitude();
            double dist = haversine(lat, lng, lat2, lng2) * 2;
            int horario = (int) dist + tempo;
            int hora = horario / 60 % 24, minuto = horario % 60;
            cout << setfill('0') << setw(2) << hora << ":" << setw(2) << minuto << " Imóvel " << imoveis[j]->getId() << endl;
            tempo = 60 + horario;
            lat = lat2;
            lng = lng2;
        }

        // Somente imprime uma quebra de linha SE não for o último corretor
        if (next(it) != Agenda.end()) {cout << "\n";}
    }
}