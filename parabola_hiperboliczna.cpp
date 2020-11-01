#include "funkcje.hpp"

#define RZUTD 20.0

std::pair <std::vector <sf::Vertex>, std::vector <sf::Vector3f> > parabola_hiperboliczna(double a, double b, double xs, double ys, double zs, double obrx, double obry, double obrz, bool srodkowy, double x0, double y0, double xk, double yk, int n)
{
    std::vector <sf::Vertex> line;
    std::vector <sf::Vector3f> punkty;
    sf::Vector3f obrocony;

    float sqn = sqrt(n);
    float dx = (xk - x0) / sqrt(n), dy = (yk - y0) / sqrt(n), tx, ty, kopia, max_z = -std::numeric_limits<float>::infinity();

    int sqrtn = sqn;

    line.push_back(sf::Vertex(sf::Vector2f(std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity())));
    line.push_back(sf::Vertex(sf::Vector2f(-line[0].position.x, -line[0].position.y)));

    for(int i = 2; i <= n + 2; i++)
    {
        if((i / sqrtn) % 2 == 0)
            tx = x0 + dx * ((i - 2) % sqrtn);
        else
            tx = x0 + sqn - dx * ((i - 2) % sqrtn);
        ty = y0 + dy * ((i - 2) / sqrtn);

        obrocony = sf::Vector3f(tx, ty, (tx / a) * (tx / a) - (ty / b) * (ty / b));
        
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

    max_z = abs(max_z);

    for(int i = 2; i <= n + 2; i++)
    {
        if(srodkowy)
        {
            double dz = max_z + RZUTD * 2.0 + punkty[i - 2].z;
            dz *= dz;
            line[i].position = sf::Vector2f(line[i].position.x * RZUTD / sqrt(line[i].position.y * line[i].position.y + dz), line[i].position.y * RZUTD / sqrt(line[i].position.x * line[i].position.x + dz));
        }

        line[0].position.x = std::min(line[0].position.x, line[i].position.x);
        line[0].position.y = std::min(line[0].position.y, line[i].position.y);
        line[1].position.x = std::max(line[1].position.x, line[i].position.x);
        line[1].position.y = std::max(line[1].position.y, line[i].position.y);
    }

    return make_pair(line, punkty);
}