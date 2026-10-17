#include "Usuario.h"

using namespace std;

Usuario::Usuario() {
    nombre_usuario = "";
    clave = "";
    fecha_nacimiento = "";
    correo = "";
    ruta_foto_perfil = "";
    ciudad = "";
    pais = "";
    fecha_inscripcion = "";

    cantidad_albumes = 0;
    capacidad_albumes = 5;
    albumes = new Album[capacidad_albumes];

    cantidad_mensajes_enviados = 0;
    capacidad_mensajes_enviados = 10;
    mensajes_enviados = new Mensaje[capacidad_mensajes_enviados];

    cantidad_mensajes_recibidos = 0;
    capacidad_mensajes_recibidos = 10;
    mensajes_recibidos = new Mensaje[capacidad_mensajes_recibidos];

    cantidad_solicitudes = 0;
    capacidad_solicitudes = 10;
    solicitudes_recibidas = new Solicitudes[capacidad_solicitudes];
}

Usuario::Usuario(const string& _nombre, const string& _clave, const string& _fecha_nacimiento, 
                 const string& _correo, const string& _ruta_foto, const string& _ciudad, 
                 const string& _pais, const string& _fecha_inscripcion) {
    nombre_usuario = _nombre;
    clave = _clave;
    fecha_nacimiento = _fecha_nacimiento;
    correo = _correo;
    ruta_foto_perfil = _ruta_foto;
    ciudad = _ciudad;
    pais = _pais;
    fecha_inscripcion = _fecha_inscripcion;

    cantidad_albumes = 0;
    capacidad_albumes = 5;
    albumes = new Album[capacidad_albumes];

    cantidad_mensajes_enviados = 0;
    capacidad_mensajes_enviados = 10;
    mensajes_enviados = new Mensaje[capacidad_mensajes_enviados];

    cantidad_mensajes_recibidos = 0;
    capacidad_mensajes_recibidos = 10;
    mensajes_recibidos = new Mensaje[capacidad_mensajes_recibidos];

    cantidad_solicitudes = 0;
    capacidad_solicitudes = 10;
    solicitudes_recibidas = new Solicitudes[capacidad_solicitudes];
}

Usuario::Usuario(const Usuario& original) {
    nombre_usuario = original.nombre_usuario;
    clave = original.clave;
    fecha_nacimiento = original.fecha_nacimiento;
    correo = original.correo;
    ruta_foto_perfil = original.ruta_foto_perfil;
    ciudad = original.ciudad;
    pais = original.pais;
    fecha_inscripcion = original.fecha_inscripcion;

    cantidad_albumes = original.cantidad_albumes;
    capacidad_albumes = original.capacidad_albumes;
    albumes = new Album[capacidad_albumes];
    for (int i = 0; i < cantidad_albumes; i++) albumes[i] = original.albumes[i];

    cantidad_mensajes_enviados = original.cantidad_mensajes_enviados;
    capacidad_mensajes_enviados = original.capacidad_mensajes_enviados;
    mensajes_enviados = new Mensaje[capacidad_mensajes_enviados];
    for (int i = 0; i < cantidad_mensajes_enviados; i++) mensajes_enviados[i] = original.mensajes_enviados[i];

    cantidad_mensajes_recibidos = original.cantidad_mensajes_recibidos;
    capacidad_mensajes_recibidos = original.capacidad_mensajes_recibidos;
    mensajes_recibidos = new Mensaje[capacidad_mensajes_recibidos];
    for (int i = 0; i < cantidad_mensajes_recibidos; i++) mensajes_recibidos[i] = original.mensajes_recibidos[i];

    cantidad_solicitudes = original.cantidad_solicitudes;
    capacidad_solicitudes = original.capacidad_solicitudes;
    solicitudes_recibidas = new Solicitudes[capacidad_solicitudes];
    for (int i = 0; i < cantidad_solicitudes; i++) solicitudes_recibidas[i] = original.solicitudes_recibidas[i];
}

Usuario::~Usuario() {
    if (albumes != nullptr) delete[] albumes;
    if (mensajes_enviados != nullptr) delete[] mensajes_enviados;
    if (mensajes_recibidos != nullptr) delete[] mensajes_recibidos;
    if (solicitudes_recibidas != nullptr) delete[] solicitudes_recibidas;
}

Usuario& Usuario::operator=(const Usuario& original) {
    if (this != &original) {
        nombre_usuario = original.nombre_usuario;
        clave = original.clave;
        fecha_nacimiento = original.fecha_nacimiento;
        correo = original.correo;
        ruta_foto_perfil = original.ruta_foto_perfil;
        ciudad = original.ciudad;
        pais = original.pais;
        fecha_inscripcion = original.fecha_inscripcion;

        if (albumes != nullptr) delete[] albumes;
        if (mensajes_enviados != nullptr) delete[] mensajes_enviados;
        if (mensajes_recibidos != nullptr) delete[] mensajes_recibidos;
        if (solicitudes_recibidas != nullptr) delete[] solicitudes_recibidas;

        cantidad_albumes = original.cantidad_albumes;
        capacidad_albumes = original.capacidad_albumes;
        albumes = new Album[capacidad_albumes];
        for (int i = 0; i < cantidad_albumes; i++) albumes[i] = original.albumes[i];

        cantidad_mensajes_enviados = original.cantidad_mensajes_enviados;
        capacidad_mensajes_enviados = original.capacidad_mensajes_enviados;
        mensajes_enviados = new Mensaje[capacidad_mensajes_enviados];
        for (int i = 0; i < cantidad_mensajes_enviados; i++) mensajes_enviados[i] = original.mensajes_enviados[i];

        cantidad_mensajes_recibidos = original.cantidad_mensajes_recibidos;
        capacidad_mensajes_recibidos = original.capacidad_mensajes_recibidos;
        mensajes_recibidos = new Mensaje[capacidad_mensajes_recibidos];
        for (int i = 0; i < cantidad_mensajes_recibidos; i++) mensajes_recibidos[i] = original.mensajes_recibidos[i];

        cantidad_solicitudes = original.cantidad_solicitudes;
        capacidad_solicitudes = original.capacidad_solicitudes;
        solicitudes_recibidas = new Solicitudes[capacidad_solicitudes];
        for (int i = 0; i < cantidad_solicitudes; i++) solicitudes_recibidas[i] = original.solicitudes_recibidas[i];
    }
    return *this;
}

bool Usuario::operator==(const Usuario& otro) const {
    return (nombre_usuario == otro.nombre_usuario);
}

bool Usuario::iniciar_sesion(const string& user, const string& pass) const {
    return (nombre_usuario == user && clave == pass);
}

string Usuario::getnombre_usuario() const { return nombre_usuario; }
string Usuario::getclave() const { return clave; }
string Usuario::getruta_foto() const { return ruta_foto_perfil; }
string Usuario::getcorreo() const { return correo; }
string Usuario::getciudad() const { return ciudad; }
string Usuario::getpais() const { return pais; }
string Usuario::getfecha_nacimiento() const { return fecha_nacimiento; }
string Usuario::getfecha_inscripcion() const { return fecha_inscripcion; }

int Usuario::getcantidad_albumes() const { return cantidad_albumes; }
int Usuario::getcantidad_mensajesEnviados() const { return cantidad_mensajes_enviados; }
int Usuario::getcantidad_mensajesRecibidos() const { return cantidad_mensajes_recibidos; }
int Usuario::getcantidad_solicitudes() const { return cantidad_solicitudes; }

const Album* Usuario::obtener_album(int indice) const {
    if (indice >= 0 && indice < cantidad_albumes) return &albumes[indice];
    return nullptr;
}
Album* Usuario::obtener_album(int indice) {
    if (indice >= 0 && indice < cantidad_albumes) return &albumes[indice];
    return nullptr;
}

const Mensaje* Usuario::obtener_mensaje_recibido(int indice) const {
    if (indice >= 0 && indice < cantidad_mensajes_recibidos) return &mensajes_recibidos[indice];
    return nullptr;
}
Mensaje* Usuario::obtener_mensaje_recibido(int indice) {
    if (indice >= 0 && indice < cantidad_mensajes_recibidos) return &mensajes_recibidos[indice];
    return nullptr;
}

const Mensaje* Usuario::obtener_mensaje_enviado(int indice) const {
    if (indice >= 0 && indice < cantidad_mensajes_enviados) return &mensajes_enviados[indice];
    return nullptr;
}
Mensaje* Usuario::obtener_mensaje_enviado(int indice) {
    if (indice >= 0 && indice < cantidad_mensajes_enviados) return &mensajes_enviados[indice];
    return nullptr;
}

const Solicitudes* Usuario::obtener_solicitud(int indice) const {
    if (indice >= 0 && indice < cantidad_solicitudes) return &solicitudes_recibidas[indice];
    return nullptr;
}

void Usuario::ampliar_albumes() {
    capacidad_albumes += 5;
    Album* temp = new Album[capacidad_albumes];
    for (int i = 0; i < cantidad_albumes; i++) temp[i] = albumes[i];
    delete[] albumes;
    albumes = temp;
}
void Usuario::ampliar_mensajes_enviados() {
    capacidad_mensajes_enviados += 10;
    Mensaje* temp = new Mensaje[capacidad_mensajes_enviados];
    for (int i = 0; i < cantidad_mensajes_enviados; i++) temp[i] = mensajes_enviados[i];
    delete[] mensajes_enviados;
    mensajes_enviados = temp;
}
void Usuario::ampliar_mensajes_recibidos() {
    capacidad_mensajes_recibidos += 10;
    Mensaje* temp = new Mensaje[capacidad_mensajes_recibidos];
    for (int i = 0; i < cantidad_mensajes_recibidos; i++) temp[i] = mensajes_recibidos[i];
    delete[] mensajes_recibidos;
    mensajes_recibidos = temp;
}
void Usuario::ampliar_solicitudes() {
    capacidad_solicitudes += 5;
    Solicitudes* temp = new Solicitudes[capacidad_solicitudes];
    for (int i = 0; i < cantidad_solicitudes; i++) temp[i] = solicitudes_recibidas[i];
    delete[] solicitudes_recibidas;
    solicitudes_recibidas = temp;
}

void Usuario::agregar_album(const Album& nuevo_album) {
    if (cantidad_albumes >= capacidad_albumes) ampliar_albumes();
    albumes[cantidad_albumes] = nuevo_album;
    cantidad_albumes++;
}
void Usuario::recibir_mensaje(const Mensaje& mensaje) {
    if (cantidad_mensajes_recibidos >= capacidad_mensajes_recibidos) ampliar_mensajes_recibidos();
    mensajes_recibidos[cantidad_mensajes_recibidos] = mensaje;
    cantidad_mensajes_recibidos++;
}
void Usuario::enviar_mensaje(const Mensaje& mensaje) {
    if (cantidad_mensajes_enviados >= capacidad_mensajes_enviados) ampliar_mensajes_enviados();
    mensajes_enviados[cantidad_mensajes_enviados] = mensaje;
    cantidad_mensajes_enviados++;
}
void Usuario::agregar_solicitud(const Solicitudes& nueva_solicitud) {
    if (buscar_solicitud(nueva_solicitud.getEmisor()) != -1) return;
    if (cantidad_solicitudes >= capacidad_solicitudes) ampliar_solicitudes();
    solicitudes_recibidas[cantidad_solicitudes] = nueva_solicitud;
    cantidad_solicitudes++;
}

int Usuario::buscar_solicitud(const string& nombre_emisor) const {
    for (int i = 0; i < cantidad_solicitudes; i++) {
        if (solicitudes_recibidas[i].getEmisor() == nombre_emisor) return i;
    }
    return -1;
}

void Usuario::eliminar_solicitud(int indice) {
    if (indice >= 0 && indice < cantidad_solicitudes) {
        for (int i = indice; i < cantidad_solicitudes - 1; i++) {
            solicitudes_recibidas[i] = solicitudes_recibidas[i + 1];
        }
        cantidad_solicitudes--;
    }
}

bool Usuario::eliminar_solicitud_por_emisor(const string& nombre_emisor) {
    int indice = buscar_solicitud(nombre_emisor);
    if (indice != -1) {
        eliminar_solicitud(indice);
        return true;
    }
    return false;
}

void Usuario::marcar_mensaje_leido(int indice) {
    if (indice >= 0 && indice < cantidad_mensajes_recibidos) {
        mensajes_recibidos[indice].marcar_leido();
    }
}

size_t Usuario::calcular_memoria() const {
    size_t memoria_total = sizeof(*this);
    memoria_total += nombre_usuario.capacity() + clave.capacity() + fecha_nacimiento.capacity() +
                     correo.capacity() + ruta_foto_perfil.capacity() + ciudad.capacity() + 
                     pais.capacity() + fecha_inscripcion.capacity();

    for (int i = 0; i < cantidad_albumes; i++) memoria_total += albumes[i].calcular_memoria();
    for (int i = 0; i < cantidad_mensajes_enviados; i++) memoria_total += mensajes_enviados[i].calcular_memoria();
    for (int i = 0; i < cantidad_mensajes_recibidos; i++) memoria_total += mensajes_recibidos[i].calcular_memoria();
    for (int i = 0; i < cantidad_solicitudes; i++) memoria_total += solicitudes_recibidas[i].calcular_memoria();

    return memoria_total;
}