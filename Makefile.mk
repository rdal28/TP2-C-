exe : application.cpp, Catalogue.cpp, TrajetSimple.cpp, Trajet.cpp
	g++ -c application.cpp
	g++ -c Catalogue.cpp
	g++ -c TrajetSimple.cpp
	g++ -c Trajet.cpp
	g++ -o exe application.o Catalogue.o TrajetSimple.o Trajet.o
