#ifndef POLIMORFISMO_H
#define POLIMORFISMO_H

#include <iostream>
#include <typeinfo>
#include <fstream>
#include <sstream>
#include <string>
#include "Video.h"
#include "Serie.h"
#include "Pelicula.h"
#include "Episodio.h"

/*
Nombre:Oscar Carranza Hernández
Matricula: A00838649
Carrera: IRS
Fecha:02/06/2024
- ¿Qué aprendí en el desarrollo de la clase Polimorfismo?
Lo que aprendí como la pregunta misma dice fue la incorporación e implementación del concepto de polimorfismo por manera y uso de las funciones virtuales para utilizar el overriding del método str en este caso para que 
la salida (el output) de las funciones sea con las características o versión de las clases derivadas y no de la clase base. Esto se logra al poner la palabra "Virtual" al inició de esa función que queremos hacerla virtual.
En este main se puso a prueba un switch para saber los casos que se quieren realizar y la implmentación del método de leer archivos.
*/

using namespace std;

const int MAX_VIDEOS = 100;

class Polimorfismo {
    private:
        Video* arrPtrVideos[MAX_VIDEOS];
        int cantidad;
    public:
        Polimorfismo();
        void leerArchivo(string nombre);

        //Métodos modificadores
        void setPtrVideo(int index, Video *video);
        void setCantidad(int _cantidad);

        //Métodos de acceso
        Video* getPtrVideo(int index);
        int getCAntidad();

        //Otros métodos
        void reporteInventario();
        void reporteCalificacion(double _calificacion);
        void reporteGenero(string _genero);
        void reportePeliculas();
        void reporteSeries();
};

#endif // POLIMORFISMO_H

