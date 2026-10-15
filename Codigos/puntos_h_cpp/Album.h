#ifndef ALBUM_H
#define ALBUM_H
#include <string>
#include "Foto.h"
using namespace std;

class Album {
private:
    string nombre;
    string ruta_almacenamiento;
    short privacidad; 

    Foto* fotos;
    int cantidad_de_fotos;
    int capacidad_de_fotos;

    void ampliar_capacidad();

public:
    Album();
    Album(const string& nombre, const string& ruta, short privacidad);

    Album(const Album& original);
    ~Album();

    Album& operator=(const Album& original);

    string getNombre() const;
    string getRutaAlmacenamiento() const;
    short getPrivacidad() const;
    int getCantidadFotos() const;

    void setPrivacidad(short nueva_privacidad);

    const Foto* obtener_foto(int indice) const;
    Foto* obtener_foto(int indice);

    void agregar_foto(const Foto& nueva_foto);
    void Mostrar_album() const;

    size_t calcular_memoria() const;
};

#endif