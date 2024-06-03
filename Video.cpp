// Oscar Carranza Hernández
// A00838649
//IRS
//20/05/2024
//

#include "Video.h"

Video::Video(){
    id = "0000";
    titulo = "";
    duracion = 0;
    genero = "";
    calificacion = 100.0;
}

Video::Video(string _id, string _titulo, int _duracion, string _genero, double _calificacion){
    id = _id;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
}

//Gets
string Video::getID(){
    return id;
}
string Video::getTitulo(){
    return titulo;
}
int Video::getDuracion(){
    return duracion;
}
string Video::getGenero(){
    return genero;
}
double Video::getCalificacion(){
    return calificacion;
}

//Sets
void Video::setId(string _id){
    id = _id;
}
void Video::setTitulo(string _titulo){
    titulo = _titulo;
}
void Video::setDuracion(int _duracion){
    duracion = _duracion;
}
void Video::setGenero(string _genero){
    genero = _genero;
}
void Video::setCalificacion(double _calificacion){
    calificacion = _calificacion;
}

// Concatenar toda la info. y la retorna
string Video::str(){
    return id + " " + titulo + " " + to_string(duracion) + 
         " " + genero + " " + to_string(calificacion);
}
