#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <SFML/Graphics.hpp>

#include "funkcje.hpp"

#define WSPOLCZYNNIK_SKALOWANIA 0.9f //okresla jaka czesc krotszej osi renderowania ma zajmowac wykres krzywej

void render(std::vector <sf::Vertex>, std::string);
void transform(std::vector <sf::Vertex> &, float, float);

int main()
{
    std::string krzywa;
    std::cout << "Podaj krzywa: ";
    std::cin >> krzywa;

    if(krzywa == "prosta")
    {
        double a, b, c, t0, tk;
        int n;

        std::cout << "(a * t0 + c, b * t0 + c)\nPodaj a: ";
        std::cin >> a;
        std::cout << "Podaj b: ";
        std::cin >> b;
        std::cout << "Podaj c: ";
        std::cin >> c;
        std::cout << "Podaj poczatkowe t: ";
        std::cin >> t0;
        std::cout << "Podaj koncowe t: ";
        std::cin >> tk;
        std::cout << "Podaj ilosc punktow: ";
        std::cin >> n;

        render(prosta(a, b, c, t0, tk, n), "Prosta");
    }
    else if(krzywa == "okrag")
    {
        double r, xs, ys, t0, tk;
        int n;

        std::cout << "(cos(t) * r + xs, sin(t) * r + ys)\nPodaj r: ";
        std::cin >> r;
        std::cout << "Podaj xs: ";
        std::cin >> xs;
        std::cout << "Podaj ys: ";
        std::cin >> ys;
        std::cout << "Podaj poczatkowe t: ";
        std::cin >> t0;
        std::cout << "Podaj koncowe t: ";
        std::cin >> tk;
        std::cout << "Podaj ilosc punktow: ";
        std::cin >> n;
        render(okrag(r, xs, ys, t0, tk, n), "Okrag");
    }
    else if(krzywa == "stozkowa")
    {
        double p, e, q, xs, ys, t0, tk;
        int n;

        std::cout << "(cos(t) * p / (1 + e * cos(t + q)) + xs, sin(t) * p / (1 + e * cos(t + q)) + ys)\nPodaj p: ";
        std::cin >> p;
        std::cout << "Podaj e: ";
        std::cin >> e;
        std::cout << "Podaj q: ";
        std::cin >> q;
        std::cout << "Podaj xs: ";
        std::cin >> xs;
        std::cout << "Podaj ys: ";
        std::cin >> ys;
        std::cout << "Podaj poczatkowe t: ";
        std::cin >> t0;
        std::cout << "Podaj koncowe t: ";
        std::cin >> tk;
        std::cout << "Podaj ilosc punktow: ";
        std::cin >> n;
        render(krzywa_stozkowa(p, e, q, xs, ys, t0, tk, n), "Krzywa stozkowa");
    }
    else if(krzywa == "cykloida")
    {
        double r, xs, ys, t0, tk;
        int n;

        std::cout << "(r * (t - sin(t)) + xs, r * (1 - cos(t) + ys))\nPodaj r: ";
        std::cin >> r;
        std::cout << "Podaj xs: ";
        std::cin >> xs;
        std::cout << "Podaj ys: ";
        std::cin >> ys;
        std::cout << "Podaj poczatkowe t: ";
        std::cin >> t0;
        std::cout << "Podaj koncowe t: ";
        std::cin >> tk;
        std::cout << "Podaj ilosc punktow: ";
        std::cin >> n;
        render(cykloida(r, xs, ys, t0 * M_PI, tk * M_PI, n), "Cykloida");
    }
    else if(krzywa == "ewolwenta")
    {
        double r, xs, ys, t0, tk;
        int n;

        std::cout << "(r * (cos(t) + t * sin(t)) + xs, r * (sin(t) - t * cos(t)) + ys)\nPodaj r: ";
        std::cin >> r;
        std::cout << "Podaj xs: ";
        std::cin >> xs;
        std::cout << "Podaj ys: ";
        std::cin >> ys;
        std::cout << "Podaj poczatkowe t: ";
        std::cin >> t0;
        std::cout << "Podaj koncowe t: ";
        std::cin >> tk;
        std::cout << "Podaj ilosc punktow: ";
        std::cin >> n;
        render(ewolwenta(r, xs, ys, t0, tk, n), "Ewolwenta");
    }
    else if(krzywa == "lancuchowa")
    {
        double a, xs, ys, t0, tk;
        int n;

        std::cout << "(t, a * cosh(t / a))\nPodaj a: ";
        std::cin >> a;
        std::cout << "Podaj xs: ";
        std::cin >> xs;
        std::cout << "Podaj ys: ";
        std::cin >> ys;
        std::cout << "Podaj poczatkowe t: ";
        std::cin >> t0;
        std::cout << "Podaj koncowe t: ";
        std::cin >> tk;
        std::cout << "Podaj ilosc punktow: ";
        std::cin >> n;
        render(krzywa_lancuchowa(a, xs, ys, t0, tk, n), "Krzywa lancuchowa");
    }
    else if(krzywa == "epitrochoida")
    {
        double R, r, h, xs, ys, t0, tk;
        int n;

        std::cout << "((R + r) * cos(t) - h * cos((R + r) / r * t) + xs, (R + r) * sin(t) - h * sin((R + r) / r * t) + ys)\nPodaj R: ";
        std::cin >> R;
        std::cout << "Podaj r: ";
        std::cin >> r;
        std::cout << "Podaj h: ";
        std::cin >> h;
        std::cout << "Podaj xs: ";
        std::cin >> xs;
        std::cout << "Podaj ys: ";
        std::cin >> ys;
        std::cout << "Podaj poczatkowe t: ";
        std::cin >> t0;
        std::cout << "Podaj koncowe t: ";
        std::cin >> tk;
        std::cout << "Podaj ilosc punktow: ";
        std::cin >> n;
        render(epitrochoida(R, r, h, xs, ys, t0, tk * M_PI, n), "Epitrochoida");
    }
    else if(krzywa == "parabola")
    {
        double a, b, c, t0, tk;
        int n;

        std::cout << "(t, (a * t + b) * t + c)\nPodaj a: ";
        std::cin >> a;
        std::cout << "Podaj b: ";
        std::cin >> b;
        std::cout << "Podaj c: ";
        std::cin >> c;
        std::cout << "Podaj poczatkowe t: ";
        std::cin >> t0;
        std::cout << "Podaj koncowe t: ";
        std::cin >> tk;
        std::cout << "Podaj ilosc punktow: ";
        std::cin >> n;
        render(parabola(a, b, c, t0, tk, n), "Parabola");
    }
    else if(krzywa == "klotoida")
    {
        double a, xs, ys, t0, tk;
        int n;

        std::cout << "(fresnel_cos(t) * a + xs, fresnel_sin(t) * a + ys)\nPodaj a: ";
        std::cin >> a;
        std::cout << "Podaj xs: ";
        std::cin >> xs;
        std::cout << "Podaj ys: ";
        std::cin >> ys;
        std::cout << "Podaj poczatkowe t: ";
        std::cin >> t0;
        std::cout << "Podaj koncowe t: ";
        std::cin >> tk;
        std::cout << "Podaj ilosc punktow: ";
        std::cin >> n;
        render(klotoida(a, xs, ys, t0, tk, n), "Klotoida");
    }
    return 0;
}

void render(std::vector <sf::Vertex> line, std::string krzywa)
{
    sf::ContextSettings ustawienia;
    ustawienia.antialiasingLevel = 16;

    sf::RenderWindow window(sf::VideoMode(800, 600), krzywa, sf::Style::Default, ustawienia);

    sf::View view = window.getDefaultView();
    view.setCenter(0, 0);
    view.setSize(800, 600);
    window.setView(view);

    std::vector <sf::Vertex> kopie_linii(line.size());
    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        for(int i = 0; i < line.size(); i++)
        {
            kopie_linii[i].position = line[i].position;
        }

        transform(kopie_linii, window.getSize().x, window.getSize().y);
        window.draw(&kopie_linii[0] + 2, kopie_linii.size() - 2, sf::LineStrip);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized)
            {
                view.setSize({static_cast <float> (event.size.width), static_cast <float> (event.size.height)});
                window.setView(view);
            }
        }
        sf::sleep(sf::milliseconds(10));
        window.display();
    }
}

void transform(std::vector <sf::Vertex> &fig, float x, float y)
{
    sf::Vector2f skale(x / 2, y / 2);
    sf::Vector2f srodek((fig[0].position.x + fig[1].position.x) / 2, (fig[0].position.y + fig[1].position.y) / 2);
    float min_wsp = std::min(skale.x / (fig[1].position.x - srodek.x), skale.y / (fig[1].position.y - srodek.y));

    for(int i = 2; i < fig.size(); i++)
    {
        fig[i].position -= srodek;
        fig[i].position *= WSPOLCZYNNIK_SKALOWANIA * min_wsp;
    }
}