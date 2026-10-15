#ifndef REDSOCIAL_H
#define REDSOCIAL_H
#include <string>
#include "Usuario.h"
using namespace std;

class RedSocial {
private:
    Usuario* usuarios;
    int cantidad_usuarios;
    int capacidad_usuarios;
    bool** amistades;
    long int iteraciones_actuales;
    int indice_sesion_actual;
    int mejores_amigos_indices[3];
    bool mejores_amigos_inicializados;
    bool actualizacion_mejores_amigos_usada;

    void ampliar_usuarios();
    void ampliar_matriz_amistades();
    bool son_amigos(int indiceA, int indiceB) const;
    void establecer_amistad(int indiceA, int indiceB);
    bool existe_solicitud(int indice_emisor, int indice_receptor) const;
    int contar_amigos_comun_interno(int indiceA, int indiceB) const;
    void seleccionar_mejores_amigos(int indice_usuario, bool excluir_anteriores);
    bool album_visible(int indice_visitante, int indice_dueno, const Album& album) const;
    void liberar_datos();

public:
    RedSocial();
    RedSocial(const RedSocial& original);
    ~RedSocial();

    RedSocial& operator=(const RedSocial& original);
    void cargar_datos(const string& archivo = "udebook.dat");
    void guardar_datos() const;
    int iniciar_sesion(const string& nombre_usuario, const string& clave);
    int Buscar_usuario(const string& nombre) const;
    int getCantidadUsuarios() const;
    const Usuario* obtener_usuario(int indice) const;
   
    Usuario* obtener_usuario(int indice);
    bool agregar_usuario(const Usuario& nuevo_usuario);
    bool enviar_solicitud_amistad(int indice_emisor, int indice_receptor);
    bool aceptar_solicitud_amistad(int indice_receptor, int indice_solicitante);
    bool rechazar_solicitud_amistad(int indice_receptor, int indice_solicitante);
    void mostrar_solicitudes_recibidas(int indice_usuario) const;
    int contar_amigos_comun(int indiceA, int indiceB) const;
    void mostrar_sugerencias_amistad(int k, int indice_usuario);
    void mostrar_mejores_amigos(int indice_usuario);
    bool actualizar_mejores_amigos(int indice_usuario);
    void visitar_perfil_amigo(int indice_usuario, const string& nombre_amigo);
    bool enviar_mensaje(int indice_emisor, const string& nombre_receptor, const string& texto, const string& fecha_envio);
    void leer_mensajes_nuevos(int indice_usuario);
    void buscar_mensajes_rango(int indice_usuario, const string& fecha_inicio, const string& fecha_fin);
    void reiniciar_iteraciones();
    void registrar_iteracion();
    long int getIteraciones() const;
    size_t calcular_memoria() const;

    void reportar_consumo( const string& nombre_funcionalidad, size_t memoria_local_aproximada = 0) const;
};
#endif