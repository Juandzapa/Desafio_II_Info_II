#ifndef FOTO_H
#define FOTO_H
#include <string>
using namespace std;

class Foto {
private:
    string fecha_foto;
    float dimension;
    string ruta_archivo;
    int likes;

public:
    Foto();
    Foto(const string& fecha, float dimension, const string& ruta, int likes = 0);

    Foto(const Foto& original);
    ~Foto();

    Foto& operator=(const Foto& original);
    bool operator==(const Foto& otra) const;

    string getFechaFoto() const;
    float getDimension() const;
    string getRuta() const;
    int getLikes() const;

    void setFechaFoto(const string& fecha);
    void setDimension(float dimension);
    void setRuta(const string& ruta);

    void agregar_like();
    void quitar_like();

    size_t calcular_memoria() const;
};


#endif