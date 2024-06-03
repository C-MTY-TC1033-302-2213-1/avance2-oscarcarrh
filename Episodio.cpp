// Oscar Carranza Hernández
// A00838649
//IRS
//20/05/2024
//

#include "Episodio.h"

// Constructor default y parámetros
Episodio::Episodio(){
    titulo = "";
    temporada = 0;
    calificacion = 100;
}
Episodio::Episodio(string _titulo, int _temporada, int _calificacion){
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}

// Gets
string Episodio::getTitulo(){
    return titulo;
}
int Episodio::getTemporada(){
    return temporada;
}
int Episodio::getCalificacion(){
    return calificacion;
}   

//Sets
void Episodio::setTitulo(string _titulo){
    titulo = _titulo;
}
void Episodio::setTemporada(int _temporada){
    temporada = _temporada;
}
void Episodio::setCalificacion(int _calificaion){
    calificacion = _calificaion;
}

//Concatenar info
string Episodio::str(){
    return titulo + " " + to_string(temporada) + " " + to_string(calificacion) ;
}