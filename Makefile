CPP = g++ -O3
SFML = E:/BibliotekiC++/DoMinGW_64BIT_nowe/SFML2_5_1

OWSKI.exe: klotoida.a cykloida.a epitrochoida.a ewolwenta.a hiperboloida_obrotowa.a krzywa_lancuchowa.a krzywa_stozkowa.a linia_srubowa.a okrag.a parabola_eliptyczna.a parabola_hiperboliczna.a parabola.a paraboloida_obrotowa.a prosta.a main.a
	$(CPP) -L $(SFML)/lib/* -o OWSKI.exe klotoida.a cykloida.a epitrochoida.a ewolwenta.a hiperboloida_obrotowa.a krzywa_lancuchowa.a krzywa_stozkowa.a linia_srubowa.a okrag.a parabola_eliptyczna.a parabola_hiperboliczna.a parabola.a paraboloida_obrotowa.a prosta.a main.a

cykloida.a: cykloida.cpp funkcje.hpp
	$(CPP) -I $(SFML)/include -c -o cykloida.a cykloida.cpp

epitrochoida.a: epitrochoida.cpp funkcje.hpp
	$(CPP) -I $(SFML)/include -c -o epitrochoida.a epitrochoida.cpp

ewolwenta.a: ewolwenta.cpp funkcje.hpp
	$(CPP) -I $(SFML)/include -c -o ewolwenta.a ewolwenta.cpp

klotoida.a: klotoida.cpp funkcje.hpp
	$(CPP) -I $(SFML)/include -c -o klotoida.a klotoida.cpp

hiperboloida_obrotowa.a: hiperboloida_obrotowa.cpp funkcje.hpp
	$(CPP) -I $(SFML)/include -c -o hiperboloida_obrotowa.a hiperboloida_obrotowa.cpp

krzywa_lancuchowa.a: krzywa_lancuchowa.cpp funkcje.hpp
	$(CPP) -I $(SFML)/include -c -o krzywa_lancuchowa.a krzywa_lancuchowa.cpp
	
krzywa_stozkowa.a: krzywa_stozkowa.cpp funkcje.hpp
	$(CPP) -I $(SFML)/include -c -o krzywa_stozkowa.a krzywa_stozkowa.cpp

linia_srubowa.a: linia_srubowa.cpp funkcje.hpp
	$(CPP) -I $(SFML)/include -c -o linia_srubowa.a linia_srubowa.cpp
	
okrag.a: okrag.cpp funkcje.hpp
	$(CPP) -I $(SFML)/include -c -o okrag.a okrag.cpp

parabola_eliptyczna.a: parabola_eliptyczna.cpp funkcje.hpp
	$(CPP) -I $(SFML)/include -c -o parabola_eliptyczna.a parabola_eliptyczna.cpp

parabola_hiperboliczna.a: parabola_hiperboliczna.cpp funkcje.hpp
	$(CPP) -I $(SFML)/include -c -o parabola_hiperboliczna.a parabola_hiperboliczna.cpp

parabola.a: parabola.cpp funkcje.hpp
	$(CPP) -I $(SFML)/include -c -o parabola.a parabola.cpp

paraboloida_obrotowa.a: parabola.cpp funkcje.hpp
	$(CPP) -I $(SFML)/include -c -o paraboloida_obrotowa.a paraboloida_obrotowa.cpp

prosta.a: prosta.cpp funkcje.hpp
	$(CPP) -I $(SFML)/include -c -o prosta.a prosta.cpp

main.a: main.cpp funkcje.hpp
	$(CPP) -I $(SFML)/include -c -o main.a main.cpp

clean:
	DEL *.a