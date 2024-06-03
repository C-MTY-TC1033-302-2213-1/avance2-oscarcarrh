// Oscar Carranza Hernández
// A00838649
//IRS
//20/05/2024
//
#ifndef Video_h
#define Video_h

#include <stdio.h>
#include <string>
using namespace std;


class Video{
    public: 
    // Constructor default y parámetros
    Video();
    Video(string _id, string _titulo, int _duracion, string _genero, double _calificacion);

    //Gets
    string getID();
    string getTitulo();
    int getDuracion();
    string getGenero();
    double getCalificacion();

    //Sets
    void setId(string _id);
    void setTitulo(string _titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _calificacion);

    // Concatenar toda la info. y la retorna
    virtual string str();

    protected:
    string id;
    string titulo;
    int duracion;
    string genero;
    double calificacion;

};

#endif /* Video_h */