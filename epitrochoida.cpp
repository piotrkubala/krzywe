#include "funkcje.hpp"

std::vector <sf::Vertex> epitrochoida(double R, double r, double h, double xs, double ys, double t0, double tk, int n)
{
    std::vector <sf::Vertex> line;
    float dt = (tk - t0) / n, t;
    double sumaR = R + r, sumaRpr = (R + r) / r;

    line.push_back(sf::Vertex(sf::Vector2f(sumaR * cos(t0) - h * cos(sumaRpr * t0) + xs, sumaR * sin(t0) - h * sin(sumaRpr * t0) + ys)));
    line.push_back(sf::Vertex(sf::Vector2f(line[0].position.x, line[0].position.y)));

    for(int i = 2; i <= n + 2; i++)
    {
        t = (t0 + dt * i);
        line.push_back(sf::Vertex(sf::Vector2f(sumaR * cos(t) - h * cos(sumaRpr * t) + xs, sumaR * sin(t) - h * sin(sumaRpr * t) + ys)));

        line[0].position.x = std::min(line[0].position.x, line[i].position.x);
        line[0].position.y = std::min(line[0].position.y, line[i].position.y);
        line[1].position.x = std::max(line[1].position.x, line[i].position.x);
        line[1].position.y = std::max(line[1].position.y, line[i].position.y);
    }
    return line;
}