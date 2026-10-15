#include "Mensaje.h"
using namespace std;

Mensaje::Mensaje() {
    emisor = "";
    receptor = "";
    texto = "";
    fecha_envio = "";
    leido = false;
}

Mensaje::Mensaje(const string& _emisor, const string& _receptor, const string& _texto, const string& _fecha_envio, bool _leido) {
    emisor = _emisor;
    receptor = _receptor;
    texto = _texto;
    fecha_envio = _fecha_envio;
    leido = _leido;
}

Mensaje::Mensaje(const Mensaje& original) {
    emisor = original.emisor;
    receptor = original.receptor;
    texto = original.texto;
    fecha_envio = original.fecha_envio;
    leido = original.leido;
}

Mensaje::~Mensaje() {
}

Mensaje& Mensaje::operator=(const Mensaje& original) {
    if (this != &original) {
        emisor = original.emisor;
        receptor = original.receptor;
        texto = original.texto;
        fecha_envio = original.fecha_envio;
        leido = original.leido;
    }
    return *this;
}

bool Mensaje::operator==(const Mensaje& otro) const {
    return (emisor == otro.emisor && receptor == otro.receptor && fecha_envio == otro.fecha_envio && texto == otro.texto);
}

string Mensaje::getEmisor() const { return emisor; }
string Mensaje::getReceptor() const { return receptor; }
string Mensaje::getTexto() const { return texto; }
string Mensaje::getFechaEnvio() const { return fecha_envio; }
bool Mensaje::isLeido() const { return leido; }

void Mensaje::marcar_leido() {
    leido = true;
}
void Mensaje::setLeido(bool estado) {
    leido = estado;
}

bool Mensaje::texto_valido() const {
    return (texto.length() <= 512);
}

bool Mensaje::esta_en_rango(const string& fecha_inicio, const string& fecha_fin) const {
    return (fecha_envio >= fecha_inicio && fecha_envio <= fecha_fin);
}

size_t Mensaje::calcular_memoria() const {
    size_t memoria_base = sizeof(*this);
    size_t memoria_strings = emisor.capacity() + receptor.capacity() + texto.capacity() + fecha_envio.capacity();
    return memoria_base + memoria_strings;
}