#ifndef UTIL_HPP
#define UTIL_HPP

#include <vector>
#include <map>
#include "corretor.hpp"
#include "imovel.hpp"

struct PessoaIDComparator {
    bool operator()(const Corretor* a, const Corretor* b) const;
};

double haversine(double lat1, double lng1, double lat2, double lng2);
void imprimirAgenda(std::map<Corretor*, std::vector<Imovel*>, PessoaIDComparator>& Agenda);

#endif