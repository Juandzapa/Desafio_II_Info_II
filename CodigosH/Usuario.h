#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include "Album.h"
#include "Mensaje.h"
#include "Solicitudes.h"
using namespace std;

class Usuario {
private:
    string nombre_usuario;
    string clave;
    string fecha_nacimiento;
    string correo;
    string ruta_foto_perfil;
    string ciudad;
    string pais;
    string fecha_inscripcion;

    Album* albumes;
    int cantidad_albumes;
    int capacidad_albumes;

    Mensaje* mensajes_enviados;
    int cantidad_mensajes_enviados;
    int capacidad_mensajes_enviados;

    Mensaje* mensajes_recibidos;
    int cantidad_mensajes_recibidos;
    int capacidad_mensajes_recibidos;

    Solicitudes* solicitudes_recibidas;
    int cantidad_solicitudes;
    int capacidad_solicitudes;

    void ampliar_albumes();
    void ampliar_mensajes_enviados();
    void ampliar_mensajes_recibidos();
    void ampliar_solicitudes();

public:
    Usuario();

    Usuario(const string& nombre_usuario, const string& clave, const string& fecha_nacimiento, const string& correo,
            const string& ruta_foto_perfil, const string& ciudad, const string& pais, const string& fecha_inscripcion);

    Usuario(const Usuario& original);
    ~Usuario();

    Usuario& operator=(const Usuario& original);
    bool operator==(const Usuario& otro) const;

    bool iniciar_sesion(const string& nombre_usuario, const string& clave) const;

    string getnombre_usuario() const;
    string getclave() const;
    string getruta_foto() const;
    string getcorreo() const;
    string getciudad() const;
    string getpais() const;
    string getfecha_nacimiento() const;
    string getfecha_inscripcion() const;

    int getcantidad_albumes() const;
    int getcantidad_mensajesEnviados() const;
    int getcantidad_mensajesRecibidos() const;
    int getcantidad_solicitudes() const;

    const Album* obtener_album(int indice) const;
    Album* obtener_album(int indice);

    const Mensaje* obtener_mensaje_recibido(int indice) const;
    Mensaje* obtener_mensaje_recibido(int indice);

    const Mensaje* obtener_mensaje_enviado(int indice) const;
    Mensaje* obtener_mensaje_enviado(int indice);

    const Solicitudes* obtener_solicitud(int indice) const;

    int buscar_solicitud(const string& nombre_emisor) const;

    void agregar_album(const Album& nuevo_album);
    void recibir_mensaje(const Mensaje& mensaje);
    void enviar_mensaje(const Mensaje& mensaje);

    void agregar_solicitud(const Solicitudes& nueva_solicitud);
    void eliminar_solicitud(int indice);
    bool eliminar_solicitud_por_emisor(const string& nombre_emisor);

    void marcar_mensaje_leido(int indice);

    size_t calcular_memoria() const;
};



#endif