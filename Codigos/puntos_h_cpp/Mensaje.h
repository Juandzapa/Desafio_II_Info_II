#ifndef MENSAJE_H
#define MENSAJE_H

#include <string>
using namespace std;

class Mensaje {
private:
    string emisor;
    string receptor;
    string texto;
    string fecha_envio;
    bool leido;

public:
    Mensaje();

    Mensaje(const string& emisor, const string& receptor, const string& texto, const string& fecha_envio, bool leido = false);

    Mensaje(const Mensaje& original);
    ~Mensaje();

    Mensaje& operator=(const Mensaje& original);
    bool operator==(const Mensaje& otro) const;

    string getEmisor() const;
    string getReceptor() const;
    string getTexto() const;
    string getFechaEnvio() const;

    bool isLeido() const;

    void marcar_leido();
    void setLeido(bool estado);

    bool texto_valido() const;
    bool esta_en_rango(const string& fecha_inicio, const string& fecha_fin) const;

    size_t calcular_memoria() const;
};

#endif