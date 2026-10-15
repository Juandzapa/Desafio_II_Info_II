#include "Solicitudes.h"

using namespace std;

Solicitudes::Solicitudes() {
    emisor = "";
    fecha_envio = "";
}

Solicitudes::Solicitudes(const string& _emisor, const string& _fecha_envio) {
    emisor = _emisor;
    fecha_envio = _fecha_envio;
}

Solicitudes::Solicitudes(const Solicitudes& original) {
    emisor = original.emisor;
    fecha_envio = original.fecha_envio;
}

Solicitudes::~Solicitudes() {}

Solicitudes& Solicitudes::operator=(const Solicitudes& original) {
    if (this != &original) {
        emisor = original.emisor;
        fecha_envio = original.fecha_envio;
    }
    return *this;
}

bool Solicitudes::operator==(const Solicitudes& otra) const {
    return (emisor == otra.emisor && fecha_envio == otra.fecha_envio);
}

string Solicitudes::getEmisor() const { return emisor; }
string Solicitudes::getFechaEnvio() const { return fecha_envio; }

size_t Solicitudes::calcular_memoria() const {
    size_t memoria_base = sizeof(*this);
    return memoria_base + emisor.capacity() + fecha_envio.capacity();
}