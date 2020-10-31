#include "funkcje.hpp"

std::vector <sf::Vertex> okrag(double r, double xs, double ys, double t0, double tk, int n)
{
    std::vector <sf::Vertex> line;
    float dt = (tk - t0) / n, t;

    line.push_back(sf::Vertex(sf::Vector2f(cos(t0) * r + xs, sin(t0) * r + ys)));
    line.push_back(sf::Vertex(sf::Vector2f(line[0].position.x, line[0].position.y)));

    for(int i = 2; i <= n + 2; i++)
    {
        t = (t0 + dt * i);
        line.push_back(sf::Vertex(sf::Vector2f(cos(t) * r + xs, sin(t) * r + ys)));

        line[0].position.x = std::min(line[0].position.x, line[i].position.x);
        line[0].position.y = std::min(line[0].position.y, line[i].position.y);
        line[1].position.x = std::max(line[1].position.x, line[i].position.x);
        line[1].position.y = std::max(line[1].position.y, line[i].position.y);
    }
    return line;
}