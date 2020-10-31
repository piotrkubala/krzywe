#include "funkcje.hpp"

std::vector <sf::Vertex> parabola(double a, double b, double c, double t0, double tk, int n)
{
    std::vector <sf::Vertex> line;
    float dt = (tk - t0) / n, t;

    line.push_back(sf::Vertex(sf::Vector2f(t0, (a * t0 + b) * t0 + c)));
    line.push_back(sf::Vertex(sf::Vector2f(t0, (a * t0 + b) * t0 + c)));

    for(int i = 2; i <= n + 2; i++)
    {
        t = (t0 + dt * i);
        line.push_back(sf::Vertex(sf::Vector2f(t, (a * t + b) * t + c)));

        line[0].position.x = std::min(line[0].position.x, line[i].position.x);
        line[0].position.y = std::min(line[0].position.y, line[i].position.y);
        line[1].position.x = std::max(line[1].position.x, line[i].position.x);
        line[1].position.y = std::max(line[1].position.y, line[i].position.y);
    }
    return line;
}