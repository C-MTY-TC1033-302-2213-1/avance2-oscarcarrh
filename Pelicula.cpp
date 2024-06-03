// Oscar Carranza Hernández
// A00838649
//IRS
//20/05/2024
//

#include "Pelicula.h"

// Constructores: Vacio y con Parámetros
    Pelicula::Pelicula():Video(){
        oscares = 0;
    }

    Pelicula::Pelicula(string _id, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares):Video(_id, _titulo, _duracion, _genero, _calificacion){
        oscares = _oscares;
    }

    // Método modificadores
    void Pelicula::setOscares(int _oscares){
        oscares = _oscares;
    }

    //Método de acceso
    int Pelicula::getOscares(){
        return oscares;
    }

    //Otros métodos
    string Pelicula::str(){
        //Tenemos acceso directo a los atributos de la clase Padre porque son protected
        return id + " " + titulo + " " + to_string(duracion) + 
         " " + genero + " " + to_string(calificacion) + " " + to_string(oscares);
    }