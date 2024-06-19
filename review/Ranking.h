#ifndef RANKING_H
#define RANKING_H

#include <vector>
#include <string>

struct JugadorRanking
{
    std::string nombre;
    int ataques;
    
    JugadorRanking() : nombre(""), ataques(0) {}
    JugadorRanking(const std::string &nombre, int ataques) : nombre(nombre), ataques(ataques) {}
};

class Ranking
{
public:
    Ranking(const std::string &archivo);

    void agregarJugador(const std::string &nombre, int ataques);
    void guardar() const;
    void cargar();
    void mostrar() const;

private:
    static bool comparar(const JugadorRanking &a, const JugadorRanking &b);

    std::vector<JugadorRanking> jugadores;
    std::string archivo;
};

#endif