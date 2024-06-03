// Oscar Carranza Hernández
// A00838649
//IRS
//02/06/2024
// ¿Qué aprendí en el desarrollo de esta clase?
// Aprendí a implementar tanto composición como herencia en una clase.
// La clase Serie hereda de la clase base Video.
// Además, utilicé la composición para incluir una colección de objetos de tipo Episodio dentro de Serie.
// Practiqué la implementación de constructores tanto vacíos como con parámetros, así como la definición de métodos modificadores y de acceso.

#ifndef Serie_h
#define Serie_h

#include <stdio.h>
#include <iostream>
#include <string>
#include "Video.h" //para herencia
#include "Episodio.h" //para composición
using namespace std;

class Serie : public Video{
    private:
    Episodio episodios[5];
    int cantidad;

    public:
    //Constructores
    Serie();
    Serie(string _id, string _titulo, int _duracion, string _genero, double _calificacion);
    void calculaDuracion();

    //Métodos modificadores
    void setEpisodio(int posicion, Episodio episodio);
    void setCantidad(int _cantidad);

    //Métodos de acceso
    Episodio getEpisodio(int posicion);
    int getCantidad();

    //Otros métodos
    double calculaPromedio();

    string str();

    void agregaEpisodio(Episodio episodio);
};

#endif /* Serie_h */