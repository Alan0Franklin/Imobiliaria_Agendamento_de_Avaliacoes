#ifndef UTIL_HPP
#define UTIL_HPP

#include <memory>
#include <vector>
#include <list>
#include <map>
#include "corretor.hpp"
#include "imovel.hpp"

// Estrutura comparadora que permite a ordenação dos corretores em um std::map
struct PessoaIDComparator {
    bool operator()(const std::shared_ptr<Corretor> a, const std::shared_ptr<Corretor> b) const;
};

// Função haversine para calcular a distância entre duas coordenadas na superfície do globo
double haversine(double lat1, double lng1, double lat2, double lng2);

// Função responsável por gerar a agenda de visitas dos avaliadores
void imprimirAgenda(std::map<std::shared_ptr<Corretor>, std::vector<std::shared_ptr<Imovel>>, PessoaIDComparator>& Agenda);

// Função que retorna o imóvel da lista de imóveis, que aquele avaliador deve visitar, mais próximo da posição atual do avaliador
std::list<std::shared_ptr<Imovel>>::iterator imovelmaisproximo(double lat, double lng, std::list<std::shared_ptr<Imovel>>& lista_imoveis);

#endif
