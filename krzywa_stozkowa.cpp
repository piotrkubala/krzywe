#include "funkcje.hpp"

inline double krzywa_stoz(double t, double p, double e)
{
    return p / (1 + e * cos(t));
}

std::vector <sf::Vertex> krzywa_stozkowa(double p, double e, double q, double xs, double ys, double t0, double tk, int n)
{
    std::vector <sf::Vertex> line;
    float dt = (tk - t0) / n, t;

    line.push_back(sf::Vertex(sf::Vector2f(cos(t0) * krzywa_stoz(t0 + q, p, e) + xs, sin(t0) * krzywa_stoz(t0 + q, p, e) + ys)));
    line.push_back(sf::Vertex(sf::Vector2f(line[0].position.x, line[0].position.y)));

    for(int i = 2; i <= n + 2; i++)
    {
        t = (t0 + dt * i);
        line.push_back(sf::Vertex(sf::Vector2f(cos(t) * krzywa_stoz(t + q, p, e) + xs, sin(t) * krzywa_stoz(t + q, p, e) + ys)));

        line[0].position.x = std::min(line[0].position.x, line[i].position.x);
        line[0].position.y = std::min(line[0].position.y, line[i].position.y);
        line[1].position.x = std::max(line[1].position.x, line[i].position.x);
        line[1].position.y = std::max(line[1].position.y, line[i].position.y);
    }
    return line;
}