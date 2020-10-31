#include "funkcje.hpp"

#include <iostream>
using namespace std;

#define EPS 1.0e-64

static double pierw = sqrt(M_PI / 2), odwr = 1.0 / pierw;

double fresnel_sin(double x)
{
    x *= pierw;
    long double suma, skladnik = x * x * x / 3, czynn = 3, sil = 2;
    x *= x;
    x *= x;
    suma = skladnik;
    do
    {
        skladnik = -skladnik * x / sil * czynn / (czynn + 4) / (sil + 1);
        czynn += 4;
        sil += 2;
        suma += skladnik;
    }
    while(skladnik >= EPS || skladnik <= -EPS || sil < 60);
    return suma * odwr;
}

double fresnel_cos(double x)
{
    x *= pierw;
    long double suma, skladnik = x, czynn = 1, sil = 0;
    x *= x;
    x *= x;
    suma = skladnik;
    do
    {
        skladnik = -skladnik * x / (sil + 1) * czynn / (czynn + 4) / (sil + 2);
        czynn += 4;
        sil += 2;
        suma += skladnik;
    }
    while(skladnik >= EPS || skladnik <= -EPS || sil < 60);
    return suma * odwr;
}

std::vector <sf::Vertex> klotoida(double a, double xs, double ys, double t0, double tk, int n)
{
    std::vector <sf::Vertex> line;
    double dt = (tk - t0) / n, t;

    line.push_back(sf::Vertex(sf::Vector2f(fresnel_cos(t0) * a + xs, fresnel_sin(t0) * a + ys)));
    line.push_back(sf::Vertex(sf::Vector2f(line[0].position.x, line[0].position.y)));

    for(int i = 2; i <= n + 2; i++)
    {
        t = (t0 + dt * i);
        line.push_back(sf::Vertex(sf::Vector2f(fresnel_cos(t) * a + xs, fresnel_sin(t) * a + ys)));

        line[0].position.x = std::min(line[0].position.x, line[i].position.x);
        line[0].position.y = std::min(line[0].position.y, line[i].position.y);
        line[1].position.x = std::max(line[1].position.x, line[i].position.x);
        line[1].position.y = std::max(line[1].position.y, line[i].position.y);
    }
    return line;
}