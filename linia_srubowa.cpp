#include "funkcje.hpp"

#include <iostream>
using namespace std;

std::pair <std::vector <sf::Vertex>, std::vector <sf::Vector3f> > linia_srubowa(double a, double k, double xs, double ys, double zs, double obrx, double obry, double obrz, bool srodkowy, double t0, double tk, int n)
{
    std::vector <sf::Vertex> line;
    std::vector <sf::Vector3f> punkty;
    sf::Vector3f obrocony;

    float dt = (tk - t0) / n, t, kopia, max_z = -std::numeric_limits<float>::infinity();

    line.push_back(sf::Vertex(sf::Vector2f(std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity())));
    line.push_back(sf::Vertex(sf::Vector2f(-line[0].position.x, -line[0].position.y)));

    for(int i = 2; i <= n + 2; i++)
    {
        t = (t0 + dt * i);

        obrocony = sf::Vector3f(cos(t) * a, sin(t) * a, k * t);
        
        // obrot wokol OX
        kopia = obrocony.y * cos(obrx) + obrocony.z * sin(obrx);
        obrocony.z = obrocony.z * cos(obrx) - obrocony.y * sin(obrx);
        obrocony.y = kopia;

        // obrot wokol OY
        kopia = obrocony.x * cos(obry) + obrocony.z * sin(obry);
        obrocony.z = obrocony.z * cos(obry) - obrocony.x * sin(obry);
        obrocony.x = kopia;

        // obrot wokol OZ
        kopia = obrocony.x * cos(obrz) + obrocony.y * sin(obrz);
        obrocony.y = obrocony.y * cos(obrz) - obrocony.x * sin(obrz);
        obrocony.x = kopia;

        max_z = std::max(max_z, obrocony.z);

        punkty.push_back(obrocony);
        line.push_back(sf::Vertex(sf::Vector2f(obrocony.x, obrocony.y)));
    }

    for(int i = 2; i <= n + 2; i++)
    {
        if(srodkowy)
            line[i].position /= static_cast <float> (sqrt((punkty[i - 2].z - max_z) * (punkty[i - 2].z - max_z) + punkty[i - 2].x * punkty[i - 2].x + punkty[i - 2].y * punkty[i - 2].y + 400));

        line[0].position.x = std::min(line[0].position.x, line[i].position.x);
        line[0].position.y = std::min(line[0].position.y, line[i].position.y);
        line[1].position.x = std::max(line[1].position.x, line[i].position.x);
        line[1].position.y = std::max(line[1].position.y, line[i].position.y);
    }

    return make_pair(line, punkty);
}