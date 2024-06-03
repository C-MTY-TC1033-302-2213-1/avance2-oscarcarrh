// Oscar Carranza Hernández
// A00838649
//IRS
//20/05/2024
//


#include "Serie.h"

 //Constructores
    Serie::Serie():Video(){
        //Solo vamos a inicializar cantidad
        cantidad = 0;
    }

    Serie::Serie(string _id, string _titulo, int _duracion, string _genero, double _calificacion):Video(_id, _titulo, _duracion, _genero, _calificacion){
       cantidad = 0;
}
    void Serie::calculaDuracion() {
    int duracionTotal = 0;
    for (int i = 0; i < cantidad; i++) {
        duracionTotal += episodios[i].getTemporada(); // Suma el atributo 'temporada' como duración
    }
    setDuracion(duracionTotal);
}

    //Métodos modificadores
    void Serie::setEpisodio(int posicion, Episodio episodio){
        //Primero validar que exista episodio
        if(posicion >= 0 && posicion < cantidad){
            episodios[posicion] = episodio;
        }
    }
    
    // cambiar el valor del atributo cantidad con el nuevo valor recibido _cantidad
    void Serie::setCantidad(int _cantidad){
        cantidad = _cantidad;
    }

    //Métodos de acceso
    Episodio Serie::getEpisodio(int posicion){
        //Crea un objeto de tipo episodio y lo inicializa con el constructor default
        Episodio epi;

        //Validar que exista el  epidosdio solicitado (posición)
        if(posicion >= 0 && posicion < cantidad){
            return episodios[posicion];
        }

        // Si no existe se retorna un Episodio default
        return epi;
    }

    //Retorna el valor del atributo cantidad
    int Serie::getCantidad(){
        return cantidad;
    }

    //Otros métodos
    double Serie::calculaPromedio(){
        double acum = 0;

        for (int index = 0; index < cantidad; index++){
            acum = acum + episodios[index].getCalificacion();
        }

    // Validar que tenga episodios
    if(cantidad > 0){
        return acum / cantidad;
    }
    else{
        return 0;
    }
    }

    //overriding del método str() de la clase
    string Serie::str() {
    string result = id + " " + titulo + " " + to_string(duracion) + " " + genero + " " + to_string(calificacion) + " " + to_string(cantidad) + "\n";

    for (int index = 0; index < cantidad; index++) {
        result += episodios[index].str() + "\n";
    }
    return result;
}

    // Agrega un episodio solo si existe espacio
    void Serie::agregaEpisodio(Episodio episodio){
        if(cantidad < 5){
            episodios[cantidad++] = episodio;
        }

    }
