#include "funkcje.hpp"

std::vector <sf::Vertex> cykloida(double r, double xs, double ys, double t0, double tk, int n)
{
    std::vector <sf::Vertex> line;
    float dt = (tk - t0) / n, t;

    line.push_back(sf::Vertex(sf::Vector2f(r * (t0 - sin(t0)) + xs, r * (1 - cos(t0)) + ys)));
    line.push_back(sf::Vertex(sf::Vector2f(r * (t0 - sin(t0)) + xs, r * (1 - cos(t0)) + ys)));

    for(int i = 2; i <= n + 2; i++)
    {
        t = (t0 + dt * i);
        line.push_back(sf::Vertex(sf::Vector2f(r * (t - sin(t)) + xs, r * (1 - cos(t) + ys))));

        line[0].position.x = std::min(line[0].position.x, line[i].position.x);
        line[0].position.y = std::min(line[0].position.y, line[i].position.y);
        line[1].position.x = std::max(line[1].position.x, line[i].position.x);
        line[1].position.y = std::max(line[1].position.y, line[i].position.y);
    }
    return line;
}