#ifndef FUNKCJE_HPP
#define FUNKCJE_HPP

#include <utility>
#include <vector>
#include <cmath>
#include <limits>
#include <SFML/Graphics.hpp>

// Pozycje minimalnych i maksymalnych wspolrzednych x, y znajduja sie pod dwoma pierwszymi indeksami wektora zwracanego przez funkcje.
// Dane te sa uzywane w pliku main do wyliczania powierzchni uzywanej do wyswietlania wykresow.

// krzywe dwuwymiarowe
std::vector <sf::Vertex> prosta(double , double , double , double, double, int);
std::vector <sf::Vertex> okrag(double, double, double, double, double, int);
std::vector <sf::Vertex> krzywa_stozkowa(double, double, double, double, double, double, double, int);
std::vector <sf::Vertex> parabola(double, double, double, double, double, int);
std::vector <sf::Vertex> cykloida(double, double, double, double, double, int);
std::vector <sf::Vertex> epitrochoida(double, double, double, double, double, double, double, int);
std::vector <sf::Vertex> krzywa_lancuchowa(double, double, double, double, double, int);
std::vector <sf::Vertex> klotoida(double, double, double, double, double, int);
std::vector <sf::Vertex> ewolwenta(double, double, double, double, double, int);

// powierzchnie
std::pair <std::vector <sf::Vertex>, std::vector <sf::Vector3f> > linia_srubowa(double, double, double, double, double, double, double, double, bool, double, double, int);
std::pair<double, double> parabola_eliptyczna(double , double , double );
std::pair<double, double> parabola_hiperboliczna(double , double , double );
std::pair<double, double> paraboloida_obrotowa(double , double , double );
std::pair<double, double> hiperboloida_obrotowa(double , double , double );

#endif