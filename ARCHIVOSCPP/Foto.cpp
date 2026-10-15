#include "Foto.h"

using namespace std;

Foto::Foto() {
    fecha_foto = "";
    dimension = 0.0f;
    ruta_archivo = "";
    likes = 0;
}

Foto::Foto(const string& fecha, float dim, const string& ruta, int _likes) {
    fecha_foto = fecha;
    dimension = dim;
    ruta_archivo = ruta;
    likes = _likes;
}

Foto::Foto(const Foto& original) {
    fecha_foto = original.fecha_foto;
    dimension = original.dimension;
    ruta_archivo = original.ruta_archivo;
    likes = original.likes;
}

Foto::~Foto() {
}

Foto& Foto::operator=(const Foto& original) {
    if (this != &original) {
        fecha_foto = original.fecha_foto;
        dimension = original.dimension;
        ruta_archivo = original.ruta_archivo;
        likes = original.likes;
    }
    return *this;
}

bool Foto::operator==(const Foto& otra) const {
    return (ruta_archivo == otra.ruta_archivo && fecha_foto == otra.fecha_foto);
}

string Foto::getFechaFoto() const { return fecha_foto; }
float Foto::getDimension() const { return dimension; }
string Foto::getRuta() const { return ruta_archivo; }
int Foto::getLikes() const { return likes; }

void Foto::setFechaFoto(const string& fecha) { fecha_foto = fecha; }
void Foto::setDimension(float dim) { dimension = dim; }
void Foto::setRuta(const string& ruta) { ruta_archivo = ruta; }

void Foto::agregar_like() { likes++; }
void Foto::quitar_like() { 
    if (likes > 0) likes--; 
}

size_t Foto::calcular_memoria() const {
    size_t memoria_base = sizeof(*this);
    size_t memoria_strings = fecha_foto.capacity() + ruta_archivo.capacity();
    return memoria_base + memoria_strings;
}