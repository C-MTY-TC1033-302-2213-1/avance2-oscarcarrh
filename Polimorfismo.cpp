#include "Polimorfismo.h"

// Constructor default - vacio
Polimorfismo::Polimorfismo() {
    for (int index = 0; index < MAX_VIDEOS; index++) {
        arrPtrVideos[index] = nullptr;
    }
    cantidad = 0;
}

//Métodos modificadores
void Polimorfismo::setPtrVideo(int index, Video *video){
    //validar index - >=0 && < cantidad
    if(index >= 0 && index <cantidad){
        //MOdificar el apuntador
        arrPtrVideos[index] = video;
    }
}

//cambia el valor de atributo cantidad al nuevo valor recibido cómo parámetro de entrada,
//validar que _cantidad este entre 0 .. MAX_VIDEOS -1 , de lo contrario NO se modifica el valor del atributo
void Polimorfismo::setCantidad(int _cantidad){
    //Validar el valor de _cantidad
    if (_cantidad >= 0 && _cantidad < MAX_VIDEOS){
        cantidad = _cantidad;
    }
}

//Métodos de acceso
//validar que _index exista en el arreglo, si no existe se retorna nullptr.
Video* Polimorfismo::getPtrVideo(int index){
//Validar que existe el index
    if(index >= 0 && index < cantidad){
        return arrPtrVideos[index];
    }

    //Si no existe
    return nullptr;
}
int Polimorfismo::getCAntidad(){
    return cantidad;
}

//Otros métodos
void Polimorfismo::reporteInventario(){
    //Declaración en el encabezado de contadores
    int cantPeliculas, cantSeries;
    
    //Inicializar
    cantPeliculas = 0;
    cantSeries = 0;

    //Reocorrer todo el arreglo de ptr usando un for
    for(int index = 0; index < cantidad; index++){
        
        cout<< arrPtrVideos[index] ->str() << endl;
        //* Indirección (ptr) genera el objeto
        if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
            cantPeliculas++;
        }
        else if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
            cantSeries++;
        }
    }

    //Fuera del for
    cout << "Peliculas = " << cantPeliculas << endl;
    cout << "Serie = " << cantSeries << endl;

}


void Polimorfismo::reporteCalificacion(double _calificacion){
    //contador total
    int total;
    //inicializar el contador
    total=0;
    
    for(int index = 0; index < cantidad; index++ ){
        //Verificar si tiene la calificacion == _calificacion
        if (arrPtrVideos[index]->getCalificacion() == _calificacion){
          cout<< arrPtrVideos[index] ->str() << endl;
          total ++;  
        }
    }
    //Desplegar el tottal fuera del for
    cout << "Total = " << total <<endl;
}

void Polimorfismo::reporteGenero(string _genero) {
    int total = 0;
    for (int index = 0; index < cantidad; index++) {
        if (arrPtrVideos[index]->getGenero() == _genero) {
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    cout << "Total = " << total << endl;
}

void Polimorfismo::reportePeliculas() {
    int totalPeliculas = 0;
    for (int index = 0; index < cantidad; index++) {
        if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)) {
            cout << arrPtrVideos[index]->str() << endl;
            totalPeliculas++;
        }
    }
    if (totalPeliculas == 0) {
        cout << "No peliculas" << endl;
    } else {
        cout << "Total Peliculas = " << totalPeliculas << endl;
    }
}

void Polimorfismo::reporteSeries() {
    int totalSeries = 0;
    for (int index = 0; index < cantidad; index++) {
        if (typeid(*arrPtrVideos[index]) == typeid(Serie)) {
            cout << arrPtrVideos[index]->str() << endl;
            totalSeries++;
        }
    }
    if (totalSeries == 0) {
        cout << "No series" << endl;
    } else {
        cout << "Total Series = " << totalSeries << endl;
    }
}


// Leer archivo
void Polimorfismo::leerArchivo(string nombre) {
    Serie *arrPtrSeries[50];
    Pelicula *arrPtrPeliculas[50];
    Episodio episodio;
    fstream entradas;
    string row[7];
    string line, word;
    int cantidadPeliculas = 0;
    int cantidadSeries = 0;
    int iR = 0, index;
    double promedio;

    entradas.open(nombre, ios::in);

    while (getline(entradas, line)) {
        stringstream s(line);
        iR = 0;

        while (getline(s, word, ',')) {
            row[iR++] = word;
        }

        if (row[0] == "P") {
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            //cout <<"Pelicula"<<arrPeliculas[cantidadPeliculas]->str()<<endl;
            cantidadPeliculas++;
        } else if (row[0] == "S") {
            arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
            //cout <<"Serie"<<arrSeries[cantidadSeries]->str()<<endl;
            cantidadSeries++;
        } else if (row[0] == "E") {
            index = stoi(row[1]) - 500;
            arrPtrSeries[index]->agregaEpisodio(*(new Episodio(row[2], stoi(row[3]), stoi(row[4]))));
            //cout <<"Episodio"<<arrSerie[index]->str()<<endl;
        }
    }

    for (int index = 0; index < cantidadSeries; index++) {
        promedio = arrPtrSeries[index]->calculaPromedio();
        arrPtrSeries[index]->calculaDuracion();
        arrPtrSeries[index]->setCalificacion(promedio);
        arrPtrVideos[cantidad++] = arrPtrSeries[index];
    }

    for (int index = 0; index < cantidadPeliculas; index++) {
        arrPtrVideos[cantidad++] = arrPtrPeliculas[index];
    }

    
    //for (int index = 0; index < cantidadVideos; index++) {
      //  cout << index << " " << arrPtrVideos[index]->str() << endl;
    //}

    entradas.close();
}
