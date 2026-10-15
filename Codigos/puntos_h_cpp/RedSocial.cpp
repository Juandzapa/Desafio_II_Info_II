#include "RedSocial.h"
#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

//CONSTRUCTORES Y DESTRUCTOR

RedSocial::RedSocial() {
    cantidad_usuarios = 0;
    capacidad_usuarios = 10;
    usuarios = new Usuario[capacidad_usuarios];

    amistades = new bool*[capacidad_usuarios];
    for (int i = 0; i < capacidad_usuarios; i++) {
        amistades[i] = new bool[capacidad_usuarios];
        for (int j = 0; j < capacidad_usuarios; j++) {
            amistades[i][j] = false;
        }
    }

    iteraciones_actuales = 0;
    indice_sesion_actual = -1;
    mejores_amigos_inicializados = false;
    actualizacion_mejores_amigos_usada = false;

    for (int i = 0; i < 3; i++) {
        mejores_amigos_indices[i] = -1;
    }

    srand(time(0)); 
}

RedSocial::RedSocial(const RedSocial& original) {
    cantidad_usuarios = original.cantidad_usuarios;
    capacidad_usuarios = original.capacidad_usuarios;
    iteraciones_actuales = original.iteraciones_actuales;
    indice_sesion_actual = original.indice_sesion_actual;
    mejores_amigos_inicializados = original.mejores_amigos_inicializados;
    actualizacion_mejores_amigos_usada = original.actualizacion_mejores_amigos_usada;

    usuarios = new Usuario[capacidad_usuarios];
    for (int i = 0; i < cantidad_usuarios; i++) {
        usuarios[i] = original.usuarios[i];
    }
    
    amistades = new bool*[capacidad_usuarios];
    for (int i = 0; i < capacidad_usuarios; i++) {
        amistades[i] = new bool[capacidad_usuarios];
        for (int j = 0; j < capacidad_usuarios; j++) {
            amistades[i][j] = original.amistades[i][j];
        }
    }
}

RedSocial::~RedSocial() {
    liberar_datos();
}

RedSocial& RedSocial::operator=(const RedSocial& original) {
    if (this != &original) {
        liberar_datos();

        cantidad_usuarios = original.cantidad_usuarios;
        capacidad_usuarios = original.capacidad_usuarios;
        iteraciones_actuales = original.iteraciones_actuales;
        indice_sesion_actual = original.indice_sesion_actual;
        mejores_amigos_inicializados = original.mejores_amigos_inicializados;
        actualizacion_mejores_amigos_usada = original.actualizacion_mejores_amigos_usada;

        usuarios = new Usuario[capacidad_usuarios];
        for (int i = 0; i < cantidad_usuarios; i++) {
            usuarios[i] = original.usuarios[i];
        }

        amistades = new bool*[capacidad_usuarios];
        for (int i = 0; i < capacidad_usuarios; i++) {
            amistades[i] = new bool[capacidad_usuarios];
            for (int j = 0; j < capacidad_usuarios; j++) {
                amistades[i][j] = original.amistades[i][j];
            }
        }
    }
    return *this;
}

void RedSocial::liberar_datos() {
    if (amistades != nullptr) {
        for (int i = 0; i < capacidad_usuarios; i++) {
            delete[] amistades[i];
        }
        delete[] amistades;
        amistades = nullptr;
    }

    if (usuarios != nullptr) {
        delete[] usuarios;
        usuarios = nullptr;
    }
}

//MEMORIA DINÁMICA

void RedSocial::ampliar_usuarios() {
    int nueva_capacidad = capacidad_usuarios + 10;
    Usuario* usuarios_ampliados = new Usuario[nueva_capacidad];

    for (int i = 0; i < cantidad_usuarios; i++) {
        usuarios_ampliados[i] = usuarios[i];
    }

    delete[] usuarios;
    usuarios = usuarios_ampliados;
    capacidad_usuarios = nueva_capacidad;
    ampliar_matriz_amistades();
}

void RedSocial::ampliar_matriz_amistades() {
    bool** nueva_matriz = new bool*[capacidad_usuarios];
    
    for (int i = 0; i < capacidad_usuarios; i++) {
        nueva_matriz[i] = new bool[capacidad_usuarios];
        for (int j = 0; j < capacidad_usuarios; j++) {
            if (i < cantidad_usuarios && j < cantidad_usuarios) {
                nueva_matriz[i][j] = amistades[i][j];
            } else {
                nueva_matriz[i][j] = false; 
            }
        }
    }

    for (int i = 0; i < cantidad_usuarios; i++) {
        delete[] amistades[i];
    }
    delete[] amistades;

    amistades = nueva_matriz;
}

//UTILIDADES-USUARIO

bool RedSocial::agregar_usuario(const Usuario& nuevo_usuario) {
    if (Buscar_usuario(nuevo_usuario.getnombre_usuario()) != -1) {
        return false; 
    }
    if (cantidad_usuarios >= capacidad_usuarios) {
        ampliar_usuarios();
    }
    usuarios[cantidad_usuarios] = nuevo_usuario;
    cantidad_usuarios++;
    return true;
}

int RedSocial::Buscar_usuario(const string& nombre) const {
    for (int i = 0; i < cantidad_usuarios; i++) {
        if (usuarios[i].getnombre_usuario() == nombre) {
            return i;
        }
    }
    return -1;
}

int RedSocial::getCantidadUsuarios() const {
    return cantidad_usuarios;
}

const Usuario* RedSocial::obtener_usuario(int indice) const {
    if (indice >= 0 && indice < cantidad_usuarios) {
        return &usuarios[indice];
    }
    return nullptr;
}

Usuario* RedSocial::obtener_usuario(int indice) {
    if (indice >= 0 && indice < cantidad_usuarios) {
        return &usuarios[indice];
    }
    return nullptr;
}

// AMISTADES

bool RedSocial::son_amigos(int indiceA, int indiceB) const {
    if (indiceA >= 0 && indiceA < cantidad_usuarios && indiceB >= 0 && indiceB < cantidad_usuarios) {
        return amistades[indiceA][indiceB];
    }
    return false;
}

void RedSocial::establecer_amistad(int indiceA, int indiceB) {
    if (indiceA >= 0 && indiceA < cantidad_usuarios && indiceB >= 0 && indiceB < cantidad_usuarios) {
        amistades[indiceA][indiceB] = true;
        amistades[indiceB][indiceA] = true;
    }
}

int RedSocial::contar_amigos_comun_interno(int indiceA, int indiceB) const {
    int comunes = 0;
    for (int k = 0; k < cantidad_usuarios; k++) {
        if (amistades[indiceA][k] && amistades[indiceB][k]) {
            comunes++;
        }
    }
    return comunes;
}

int RedSocial::contar_amigos_comun(int indiceA, int indiceB) const {
    return contar_amigos_comun_interno(indiceA, indiceB);
}


int RedSocial::iniciar_sesion(const string& nombre_usuario, const string& clave) {
    int indice = Buscar_usuario(nombre_usuario);
    if (indice != -1) {
        if (usuarios[indice].iniciar_sesion(nombre_usuario, clave)) {
            indice_sesion_actual = indice;
            mejores_amigos_inicializados = false;
            actualizacion_mejores_amigos_usada = false;
            seleccionar_mejores_amigos(indice, false);
            return indice;
        }
    }
    return -1;
}

void RedSocial::seleccionar_mejores_amigos(int indice_usuario, bool excluir_anteriores) {
    int* amigos_posibles = new int[cantidad_usuarios];
    int cantidad_amigos = 0;

    for (int i = 0; i < cantidad_usuarios; i++) {
        if (amistades[indice_usuario][i]) {
            bool fue_mostrado = false;
            if (excluir_anteriores) {
                for (int m = 0; m < 3; m++) {
                    if (mejores_amigos_indices[m] == i) fue_mostrado = true;
                }
            }
            if (!fue_mostrado) {
                amigos_posibles[cantidad_amigos] = i;
                cantidad_amigos++;
            }
        }
    }

    if (cantidad_amigos <= 3) {
        for (int i = 0; i < 3; i++) {
            if (i < cantidad_amigos) mejores_amigos_indices[i] = amigos_posibles[i];
            else mejores_amigos_indices[i] = -1;
        }
    } else {
        for (int m = 0; m < 3; m++) {
            float suma_pesos = 0;
            float* pesos = new float[cantidad_amigos];
            
            for (int i = 0; i < cantidad_amigos; i++) {
                if (amigos_posibles[i] != -1) {
                    int comunes = contar_amigos_comun_interno(indice_usuario, amigos_posibles[i]);
                    if (comunes <= 10) pesos[i] = 1.0f;
                    else if (comunes <= 20) pesos[i] = 2.5f;
                    else pesos[i] = 3.5f;
                    suma_pesos += pesos[i];
                } else {
                    pesos[i] = 0;
                }
            }

            float limite = (rand() % 10000) / 10000.0f * suma_pesos;
            float acumulado = 0;
            for (int i = 0; i < cantidad_amigos; i++) {
                if (pesos[i] > 0) {
                    acumulado += pesos[i];
                    if (acumulado >= limite) {
                        mejores_amigos_indices[m] = amigos_posibles[i];
                        amigos_posibles[i] = -1; 
                        break;
                    }
                }
            }
            delete[] pesos;
        }
    }
    delete[] amigos_posibles;
    mejores_amigos_inicializados = true;
}

void RedSocial::mostrar_mejores_amigos(int indice_usuario) {
    if (!mejores_amigos_inicializados) seleccionar_mejores_amigos(indice_usuario, false);
    cout << "\n-- Fotos de mejores amigos --\n";
    for (int i = 0; i < 3; i++) {
        if (mejores_amigos_indices[i] != -1) {
            cout << "Amigo " << i+1 << ": " << usuarios[mejores_amigos_indices[i]].getnombre_usuario() << endl;
        }
    }
}

bool RedSocial::actualizar_mejores_amigos(int indice_usuario) {
    if (actualizacion_mejores_amigos_usada) return false; 
    seleccionar_mejores_amigos(indice_usuario, true);
    actualizacion_mejores_amigos_usada = true;
    return true;
}

void RedSocial::mostrar_sugerencias_amistad(int k, int indice_usuario) {
    int* sugeridos = new int[cantidad_usuarios];
    int* comunes = new int[cantidad_usuarios];
    int cont_sug = 0;

    for (int i = 0; i < cantidad_usuarios; i++) {
        if (i != indice_usuario && !amistades[indice_usuario][i]) {
            sugeridos[cont_sug] = i;
            comunes[cont_sug] = contar_amigos_comun_interno(indice_usuario, i);
            cont_sug++;
        }
    }

    int limite = (k < cont_sug) ? k : cont_sug; 

    for (int i = 0; i < limite; i++) {
        int indice_maximo = i; 
        
        for (int j = i + 1; j < cont_sug; j++) {
            registrar_iteracion();
            if (comunes[j] > comunes[indice_maximo]) {
                indice_maximo = j;
            }
        }
        
        if (indice_maximo != i) {
            int temp_c = comunes[i];
            comunes[i] = comunes[indice_maximo];
            comunes[indice_maximo] = temp_c;

            int temp_s = sugeridos[i];
            sugeridos[i] = sugeridos[indice_maximo];
            sugeridos[indice_maximo] = temp_s;
        }
    }

    cout << "\n-- Top " << k << " sugerencias de amistad --\n";
    for (int i = 0; i < limite; i++) {
        cout << i+1 << ". " << usuarios[sugeridos[i]].getnombre_usuario() 
             << " (" << comunes[i] << " amigos en comun)\n";
    }

    delete[] sugeridos;
    delete[] comunes;
}

bool RedSocial::existe_solicitud(int indice_emisor, int indice_receptor) const { return false; }
bool RedSocial::album_visible(int indice_visitante, int indice_dueno, const Album& album) const { return false; }
bool RedSocial::enviar_solicitud_amistad(int indice_emisor, int indice_receptor) { return true; }
bool RedSocial::aceptar_solicitud_amistad(int indice_receptor, int indice_solicitante) { return true; }
bool RedSocial::rechazar_solicitud_amistad(int indice_receptor, int indice_solicitante) { return true; }
void RedSocial::mostrar_solicitudes_recibidas(int indice_usuario) const {}
void RedSocial::visitar_perfil_amigo(int indice_usuario, const string& nombre_amigo) {}
bool RedSocial::enviar_mensaje(int indice_emisor, const string& nombre_receptor, const string& texto, const string& fecha_envio) { return true; }
void RedSocial::leer_mensajes_nuevos(int indice_usuario) {}
void RedSocial::buscar_mensajes_rango(int indice_usuario, const string& fecha_inicio, const string& fecha_fin) {}
void RedSocial::cargar_datos(const string& archivo) {}
void RedSocial::guardar_datos() const {}

void RedSocial::reiniciar_iteraciones() {
    iteraciones_actuales = 0;
}

void RedSocial::registrar_iteracion() {
    iteraciones_actuales++;
}

long int RedSocial::getIteraciones() const {
    return iteraciones_actuales;
}

size_t RedSocial::calcular_memoria() const {
    size_t memoria_total = sizeof(*this);

    for (int i = 0; i < cantidad_usuarios; i++) {
        memoria_total += usuarios[i].calcular_memoria();
    }
    memoria_total += (capacidad_usuarios * sizeof(bool*));
    for (int i = 0; i < capacidad_usuarios; i++) {
        memoria_total += (capacidad_usuarios * sizeof(bool));
    }

    return memoria_total;
}

void RedSocial::reportar_consumo(const string& nombre_funcionalidad, size_t memoria_local_aproximada) const {
    cout << "\n-- Reporte de eficiencia: " << nombre_funcionalidad << " --" << endl;
    cout << "Iteraciones: " << iteraciones_actuales << endl;
    cout << "Memoria usada (bytes): " << calcular_memoria() + memoria_local_aproximada << endl;
}