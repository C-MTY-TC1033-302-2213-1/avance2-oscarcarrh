// Oscar Carranza Hernández
// A00838649
//IRS
//02/06/2024
// ¿Qué aprendí en el desarrollo de esta clase?
// Este código me ayudó a practicar el concepto de herencia. 
// La clase Pelicula hereda de la clase base Video, lo que significa que Pelicula puede utilizar todos los atributos y métodos públicos y protegidos de Video.
// La implementación de "public : Video" en la declaración de la clase Pelicula permite esta relación de herencia.
// También aprendí a sobrescribir métodos para proporcionar funcionalidades específicas en la clase derivada.

#ifndef Pelicula_h
#define Pelicula_h

#include <stdio.h>
#include <iostream>
#include <string>
#include "Video.h"
using namespace std;


// Clase Pelicula es derivada de Video
class Pelicula : public Video{
    private:
    int oscares;

    public:
    // Constructores: Vacio y con Parámetros
    Pelicula();
    Pelicula(string _id, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares);

    // Método modificadores
    void setOscares(int _oscares);

    //Método de acceso
    int getOscares();

    //Otros métodos
    string str();
};

#endif /* Pelicula_h */