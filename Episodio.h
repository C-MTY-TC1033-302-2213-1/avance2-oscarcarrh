// Oscar Carranza Hernández
// A00838649
//IRS
//02/06/2024
// ¿Qué aprendí en el desarrollo de esta clase?
// Desarrollé habilidades para definir y utilizar constructores por default y con parámetros, lo cual es fundamental para la creación e inicialización de objetos.
// Practiqué la implementación de métodos modificadores (setters) y de acceso (getters).

#ifndef Episodio_h
#define Episodio_h

#include <stdio.h>
#include <string>
using namespace std;

class Episodio{
    private:
    string titulo;
    int temporada;
    int calificacion;

    public:
    // Constructor default y parámetros
    Episodio();
    Episodio(string _titulo, int _temporada, int _calificacion);

    // Gets
    string getTitulo();
    int getTemporada();
    int getCalificacion();

    //Sets
    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(int _calificaion);

    //Concatenar info
    string str();

};

#endif /* Episodio_h */