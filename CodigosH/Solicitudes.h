#ifndef SOLICITUDES_H
#define SOLICITUDES_H
#include <string>
using namespace std;

class Solicitudes {
private:
    string emisor;
    string fecha_envio;

public:
    Solicitudes();

    Solicitudes(const string& emisor, const string& fecha_envio);

    Solicitudes(const Solicitudes& original);
    ~Solicitudes();

    Solicitudes& operator=(const Solicitudes& original);
    bool operator==(const Solicitudes& otra) const;

    string getEmisor() const;
    string getFechaEnvio() const;

    size_t calcular_memoria() const;
};
#endif