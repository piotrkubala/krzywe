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
    double t0, tk;
    int n, rodzaj;
    char zakonczyc, zapisac;
    std::string krzywa, nazwa;
    std::fstream plik;
    std::vector <sf::Vertex> punkty;
    std::vector <sf::Vector3f> punkty3D;

    do
    {
        std::cout << "--------------------------------\n\tDostepne krzywe:\n\t1. prosta\n\t2. okrag\n\t3. stozkowa\n\t4. cykloida\
                    \n\t5. ewolwenta\n\t6. lancuchowa\n\t7. epitrochoida\n\t8. parabola\n\t9. klotoida\n\t10. srubowa\n--------------------------------\n";
        std::cout << "Podaj krzywa: ";
        std::cin >> krzywa;

        std::cout << "Podaj poczatkowe t: ";
        std::cin >> t0;
        std::cout << "Podaj koncowe t: ";
        std::cin >> tk;
        std::cout << "Podaj ilosc punktow: ";
        std::cin >> n;

        if(krzywa == "prosta")
        {
            double a, b, c;
            
            rodzaj = 1;

            std::cout << "(a * t0 + c, b * t0 + c)\nPodaj a: ";
            std::cin >> a;
            std::cout << "Podaj b: ";
            std::cin >> b;
            std::cout << "Podaj c: ";
            std::cin >> c;

            punkty = prosta(a, b, c, t0, tk, n);
            render(punkty, "Prosta");
        }
        else if(krzywa == "okrag")
        {
            double r, xs, ys;
            
            rodzaj = 1;

            std::cout << "(cos(t) * r + xs, sin(t) * r + ys)\nPodaj r: ";
            std::cin >> r;
            std::cout << "Podaj xs: ";
            std::cin >> xs;
            std::cout << "Podaj ys: ";
            std::cin >> ys;

            punkty = okrag(r, xs, ys, t0, tk, n);
            render(punkty, "Okrag");
        }
        else if(krzywa == "stozkowa")
        {
            double p, e, q, xs, ys;

            rodzaj = 1;

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

            punkty = krzywa_stozkowa(p, e, q, xs, ys, t0, tk, n);
            render(punkty, "Krzywa stozkowa");
        }
        else if(krzywa == "cykloida")
        {
            double r, xs, ys;
            
            rodzaj = 1;

            std::cout << "(r * (t - sin(t)) + xs, r * (1 - cos(t) + ys))\nPodaj r: ";
            std::cin >> r;
            std::cout << "Podaj xs: ";
            std::cin >> xs;
            std::cout << "Podaj ys: ";
            std::cin >> ys;

            punkty = cykloida(r, xs, ys, t0 * M_PI, tk * M_PI, n);
            render(punkty, "Cykloida");
        }
        else if(krzywa == "ewolwenta")
        {
            double r, xs, ys;

            rodzaj = 1;

            std::cout << "(r * (cos(t) + t * sin(t)) + xs, r * (sin(t) - t * cos(t)) + ys)\nPodaj r: ";
            std::cin >> r;
            std::cout << "Podaj xs: ";
            std::cin >> xs;
            std::cout << "Podaj ys: ";
            std::cin >> ys;

            render(ewolwenta(r, xs, ys, t0, tk, n), "Ewolwenta");
        }
        else if(krzywa == "lancuchowa")
        {
            double a, xs, ys;
            
            rodzaj = 1;

            std::cout << "(t, a * cosh(t / a))\nPodaj a: ";
            std::cin >> a;
            std::cout << "Podaj xs: ";
            std::cin >> xs;
            std::cout << "Podaj ys: ";
            std::cin >> ys;
            
            punkty = krzywa_lancuchowa(a, xs, ys, t0, tk, n);
            render(punkty, "Lancuchowa");
        }
        else if(krzywa == "epitrochoida")
        {
            double R, r, h, xs, ys;

            rodzaj = 1;

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
            
            punkty = epitrochoida(R, r, h, xs, ys, t0, tk, n);
            render(punkty, "Epitrochoida");
        }
        else if(krzywa == "parabola")
        {
            double a, b, c;
            
            rodzaj = 1;

            std::cout << "(t, (a * t + b) * t + c)\nPodaj a: ";
            std::cin >> a;
            std::cout << "Podaj b: ";
            std::cin >> b;
            std::cout << "Podaj c: ";
            std::cin >> c;
            
            punkty = parabola(a, b, c, t0, tk, n);
            render(punkty, "Parabola");
        }
        else if(krzywa == "klotoida")
        {
            double a, xs, ys;

            rodzaj = 1;

            std::cout << "(fresnel_cos(t) * a + xs, fresnel_sin(t) * a + ys)\nPodaj a: ";
            std::cin >> a;
            std::cout << "Podaj xs: ";
            std::cin >> xs;
            std::cout << "Podaj ys: ";
            std::cin >> ys;
            punkty = klotoida(a, xs, ys, t0, tk, n);
            render(punkty, "Klotoida");
        }
        else if(krzywa == "srubowa")
        {
            double a, k, xs, ys, zs, obrx, obry, obrz;
            char sr;

            rodzaj = 2;

            std::cout << "(cos(t) * a, sin(t) * a, k * t)\nPodaj a: ";
            std::cin >> a;
            std::cout << "Podaj k: ";
            std::cin >> k;
            std::cout << "Podaj xs: ";
            std::cin >> xs;
            std::cout << "Podaj ys: ";
            std::cin >> ys;
            std::cout << "Podaj zs: ";
            std::cin >> zs;
            std::cout << "Podaj kat obrotu wokol osi OX: ";
            std::cin >> obrx;
            std::cout << "Podaj kat obrotu wokol osi OY: ";
            std::cin >> obry;
            std::cout << "Podaj kat obrotu wokol osi OZ: ";
            std::cin >> obrz;
            std::cout << "Czy chcesz uzyc rzutu srodkowego? (t/n): ";
            std::cin >> sr;

            std::pair <std::vector <sf::Vertex>, std::vector <sf::Vector3f> > sruba = linia_srubowa(a, k, xs, ys, zs, obrx, obry, obrz, sr == 't', t0, tk, n);

            punkty3D = sruba.second;
            render(sruba.first, "Linia srubowa");
        }
        else if (krzywa == "hiperboliczna")
        {
            double a, b, xs, ys, zs, obrx, obry, obrz, x0, y0, xk, yk;
            char sr;

            rodzaj = 2;

            std::cout << "(tx, ty, (tx / a) * (tx / a) - (ty / b) * (ty / b))\nPodaj a: ";
            std::cin >> a;
            std::cout << "Podaj b: ";
            std::cin >> b;
            std::cout << "Podaj xs: ";
            std::cin >> xs;
            std::cout << "Podaj ys: ";
            std::cin >> ys;
            std::cout << "Podaj zs: ";
            std::cin >> zs;
            std::cout << "Podaj kat obrotu wokol osi OX: ";
            std::cin >> obrx;
            std::cout << "Podaj kat obrotu wokol osi OY: ";
            std::cin >> obry;
            std::cout << "Podaj kat obrotu wokol osi OZ: ";
            std::cin >> obrz;
            std::cout << "Czy chcesz uzyc rzutu srodkowego? (t/n): ";
            std::cin >> sr;
            std::cout << "Podaj x0: ";
            std::cin >> x0;
            std::cout << "Podaj y0: ";
            std::cin >> y0;
            std::cout << "Podaj xk: ";
            std::cin >> xk;
            std::cout << "Podaj yk: ";
            std::cin >> yk;

            std::pair <std::vector <sf::Vertex>, std::vector <sf::Vector3f> > parabole = parabola_hiperboliczna(a, b, xs, ys, zs, obrx, obry, obrz, sr == 't', x0, y0, xk, yk, n);
            
            punkty3D = parabole.second;
            render(parabole.first, "Parabola hiperboliczna");
        } 
        else
        {
            rodzaj = 0;
            std::cout << "Ta krzywa jest niedostepna\n";
        }
        
        if(rodzaj != 0)
        {
            std::cout << "Zapisac do pliku? (t/n): ";
            std::cin >> zapisac;
            if (zapisac == 't')
            {
                std::cout << "Podaj nazwe pliku: ";
                std::cin >> nazwa;
                nazwa += ".scr";
                
                plik.open(nazwa, std::ios::out);

                if(rodzaj == 1)
                {   
                    plik << "LINE\n";
                    for (int i = 2; i < punkty.size(); i++)
                    {
                        plik << punkty[i].position.x << ',' << punkty[i].position.y << '\n';
                    }
                }
                else
                {
                    plik << "LINE\n";
                    for (int i = 0; i < punkty3D.size(); i++)
                    {
                        plik << punkty3D[i].x << ',' << punkty3D[i].y << ',' << punkty3D[i].z << '\n';
                    }
                }

                plik.close();
            }
        }

        std::cout << "Zakonczyc? (t/n): ";
        std::cin >> zakonczyc;
    }
    while(zakonczyc == 'n');

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
        fig[i].position *= -WSPOLCZYNNIK_SKALOWANIA * min_wsp;
    }
}