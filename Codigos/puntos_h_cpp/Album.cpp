#include "Album.h"
#include <iostream>

using namespace std;

Album::Album() {
    nombre = "";
    ruta_almacenamiento = "";
    privacidad = 0;
    cantidad_de_fotos = 0;
    capacidad_de_fotos = 5;
    fotos = new Foto[capacidad_de_fotos]; 
}

Album::Album(const string& _nombre, const string& _ruta, short _privacidad) {
    nombre = _nombre;
    ruta_almacenamiento = _ruta;
    privacidad = _privacidad;
    cantidad_de_fotos = 0;
    capacidad_de_fotos = 5;
    
    fotos = new Foto[capacidad_de_fotos];
}

Album::Album(const Album& original) {
    nombre = original.nombre;
    ruta_almacenamiento = original.ruta_almacenamiento;
    privacidad = original.privacidad;
    cantidad_de_fotos = original.cantidad_de_fotos;
    capacidad_de_fotos = original.capacidad_de_fotos;

    fotos = new Foto[capacidad_de_fotos];
    for (int i = 0; i < cantidad_de_fotos; i++) {
        fotos[i] = original.fotos[i];
    }
}

Album::~Album() {
    if (fotos != nullptr) {
        delete[] fotos;
        fotos = nullptr;
    }
}

Album& Album::operator=(const Album& original) {
    if (this != &original) {
        nombre = original.nombre;
        ruta_almacenamiento = original.ruta_almacenamiento;
        privacidad = original.privacidad;
        cantidad_de_fotos = original.cantidad_de_fotos;
        capacidad_de_fotos = original.capacidad_de_fotos;

        if (fotos != nullptr) {
            delete[] fotos;
        }

        fotos = new Foto[capacidad_de_fotos];
        for (int i = 0; i < cantidad_de_fotos; i++) {
            fotos[i] = original.fotos[i];
        }
    }
    return *this;
}

string Album::getNombre() const { return nombre; }
string Album::getRutaAlmacenamiento() const { return ruta_almacenamiento; }
short Album::getPrivacidad() const { return privacidad; }
int Album::getCantidadFotos() const { return cantidad_de_fotos; }

void Album::setPrivacidad(short nueva_privacidad) {
    privacidad = nueva_privacidad;
}

const Foto* Album::obtener_foto(int indice) const {
    if (indice >= 0 && indice < cantidad_de_fotos) {
        return &fotos[indice];
    }
    return nullptr;
}

Foto* Album::obtener_foto(int indice) {
    if (indice >= 0 && indice < cantidad_de_fotos) {
        return &fotos[indice];
    }
    return nullptr;
}

void Album::ampliar_capacidad() {
    int nueva_capacidad = capacidad_de_fotos + 10;
    Foto* arreglo_ampliado = new Foto[nueva_capacidad];

    for (int i = 0; i < cantidad_de_fotos; i++) {
        arreglo_ampliado[i] = fotos[i];
    }

    delete[] fotos;
    fotos = arreglo_ampliado;
    capacidad_de_fotos = nueva_capacidad;
}

void Album::agregar_foto(const Foto& nueva_foto) {
    if (cantidad_de_fotos >= capacidad_de_fotos) {
        ampliar_capacidad();
    }
    fotos[cantidad_de_fotos] = nueva_foto;
    cantidad_de_fotos++;
}

void Album::Mostrar_album() const {
    cout << "Album: " << nombre << endl;
    for (int i = 0; i < cantidad_de_fotos; i++) {
        cout << i + 1 << ". " << fotos[i].getRuta() << endl;
    }
}

size_t Album::calcular_memoria() const {
    size_t memoria_base = sizeof(*this);
    size_t memoria_strings = nombre.capacity() + ruta_almacenamiento.capacity();
    
    size_t memoria_fotos_dinamicas = 0;
    for (int i = 0; i < cantidad_de_fotos; i++) {
        memoria_fotos_dinamicas += fotos[i].calcular_memoria();
    }
    return memoria_base + memoria_strings + memoria_fotos_dinamicas;
}