// Ranking.h
#ifndef RANKING_H
#define RANKING_H

#include <string>
#include <vector>

struct JugadorRanking {
    std::string nombre;
    int ataques;

    JugadorRanking(const std::string& nombre, int ataques) : nombre(nombre), ataques(ataques) {}
};

class Ranking {
public:
    Ranking(const std::string& archivo);

    void agregarJugador(const std::string& nombre, int ataques);
    void guardar() const;
    void cargar();
    void mostrar() const;

private:
    std::string archivo;
    std::vector<JugadorRanking> jugadores;

    static bool comparar(const JugadorRanking& a, const JugadorRanking& b);
};

#endif // RANKING_H
