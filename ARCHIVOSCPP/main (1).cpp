#include <iostream>
#include <string>
#include "RedSocial.h"
using namespace std;

int main() {
    RedSocial red;
    
    cout << "Iniciando sistema UdeABook\n";
    red.cargar_datos("udebook.txt");

    bool sistema_activo = true;
    int usuario_logueado = -1;

    while (sistema_activo) {
        
        if (usuario_logueado == -1) {
            cout << "BIENVENIDO A UdeABook\n";
            cout << "1. Iniciar Sesion\n";
            cout << "2. Apagar Sistema\n";
            cout << "Seleccione una opcion: ";
            
            string op_inicio;
            cin >> op_inicio;

            if (op_inicio == "1") {
                string usuario, clave;
                cout << "Usuario: ";
                cin >> usuario;
                cout << "Clave: ";
                cin >> clave;

                red.reiniciar_iteraciones();
                usuario_logueado = red.iniciar_sesion(usuario, clave);
                red.reportar_consumo("Iniciar sesion");

                if (usuario_logueado != -1) {
                    cout << "\nSesion iniciada correctamente, bienvenido " << usuario << "\n";
                    red.mostrar_mejores_amigos(usuario_logueado);
                } else {
                    cout << "Error: Credenciales incorrectas o el usuario no existe.\n";
                }
            } 
            else if (op_inicio == "2") {
                cout << "Guardando datos antes de apagar...\n";
                red.guardar_datos();
                sistema_activo = false;
                cout << "Sistema apagado con exito.\n";
            } 
            else {
                cout << "Opcion no valida.\n";
            }
        } 
        else {
            cout << "           MENU PRINCIPAL               \n";
            cout << "1. Administrar amistades\n";
            cout << "2. Visitar perfil de un amigo\n";
            cout << "3. Ver sugerencias de amistad\n";
            cout << "4. Administrar mensajes\n";
            cout << "N. Alternar grupo de fotos de mejores amigos\n";
            cout << "S. Cerrar sesion\n";
            cout << "Seleccione una opcion: ";
            
            string opcion;
            cin >> opcion;

            if (opcion == "1") {
                cout << "\n Administrar Amistades \n";
                cout << "1. Enviar solicitud de amistad\n";
                cout << "2. Ver y responder solicitudes recibidas\n";
                cout << "Seleccione: ";
                string op_amigos;
                cin >> op_amigos;
                
                if (op_amigos == "1") {
                    string nombre_destino;
                    cout << "Ingrese el nombre del usuario a enviar solicitud: ";
                    cin >> nombre_destino;
                    
                    red.reiniciar_iteraciones();
                    int indice_destino = red.Buscar_usuario(nombre_destino);
                    
                    if (indice_destino != -1) {
                        if (red.enviar_solicitud_amistad(usuario_logueado, indice_destino)) {
                            cout << "Solicitud enviada con exito a " << nombre_destino << ".\n";
                        } else {
                            cout << "No se pudo enviar (ya son amigos, ya hay solicitud, o eres tu mismo).\n";
                        }
                    } else {
                        cout << "El usuario no existe.\n";
                    }
                    red.reportar_consumo("Enviar solicitud de amistad");
                } 
                else if (op_amigos == "2") {
                    red.reiniciar_iteraciones();
                    red.mostrar_solicitudes_recibidas(usuario_logueado);
                    red.reportar_consumo("Mostrar solicitudes recibidas");
                    
                    cout << "\nDesea responder alguna solicitud? (1 para Si, 0 para No): ";
                    string responder;
                    cin >> responder;
                    if (responder == "1") {
                        string emisor;
                        cout << "Ingrese el nombre del emisor de la solicitud: ";
                        cin >> emisor;
                        
                        int indice_emisor = red.Buscar_usuario(emisor);
                        if (indice_emisor != -1) {
                            cout << "1. Aceptar | 2. Rechazar: ";
                            string accion;
                            cin >> accion;
                            
                            red.reiniciar_iteraciones();
                            if (accion == "1") {
                                if (red.aceptar_solicitud_amistad(usuario_logueado, indice_emisor)) {
                                    cout << "Solicitud aceptada, ahora son amigos.\n";
                                } else {
                                    cout << "No se pudo aceptar, verifique el nombre.\n";
                                }
                            } 
                            else if (accion == "2") {
                                if (red.rechazar_solicitud_amistad(usuario_logueado, indice_emisor)) {
                                    cout << "Solicitud rechazada \n";
                                } else {
                                    cout << "No se pudo rechazar \n";
                                }
                            }
                            red.reportar_consumo("Responder solicitud de amistad");
                        } else {
                            cout << "El usuario no existe.\n";
                        }
                    }
                }
            } 
            else if (opcion == "2") {
                string amigo;
                cout << "Ingrese el nombre del amigo que desea visitar: ";
                cin >> amigo;
                
                red.reiniciar_iteraciones();
                red.visitar_perfil_amigo(usuario_logueado, amigo);
                red.reportar_consumo("Visitar perfil y carrusel de fotos");
                
            } 
            else if (opcion == "3") {
                int k;
                cout << "Cuantas sugerencias de amistad desea ver? (1-20): ";
                cin >> k;
                if (k >= 1 && k <= 20) {
                    red.reiniciar_iteraciones();
                    red.mostrar_sugerencias_amistad(k, usuario_logueado);
                    red.reportar_consumo("Ver sugerencias de amistad");
                } else {
                    cout << "Numero fuera de rango.\n";
                }
            } 
            else if (opcion == "4") {
                cout << "\n-- Administrar Mensajes --\n";
                cout << "1. Enviar mensaje\n";
                cout << "2. Leer nuevos mensajes\n";
                cout << "3. Buscar mensajes por rango de fecha\n";
                cout << "Seleccione: ";
                string op_msg;
                cin >> op_msg;
                
                if (op_msg == "1") {
                    string receptor, texto, fecha;
                    cout << "Para (nombre de amigo): ";
                    cin >> receptor;
                    
                    cout << "Mensaje: ";
                    cin.ignore();
                    getline(cin, texto);
                    
                    cout << "Fecha de envio (YYYY-MM-DD): ";
                    cin >> fecha;
                    
                    red.reiniciar_iteraciones();
                    if (red.enviar_mensaje(usuario_logueado, receptor, texto, fecha)) {
                        cout << "Mensaje enviado exitosamente.\n";
                    } else {
                        cout << "No se pudo enviar, verifique que el usuario exista y sea su amigo.\n";
                    }
                    red.reportar_consumo("Enviar mensaje");
                    
                } 
                else if (op_msg == "2") {
                    red.reiniciar_iteraciones();
                    red.leer_mensajes_nuevos(usuario_logueado);
                    red.reportar_consumo("Leer mensajes nuevos");
                } 
                else if (op_msg == "3") {
                    string inicio, fin;
                    cout << "Fecha inicio (YYYY-MM-DD): ";
                    cin >> inicio;
                    cout << "Fecha fin (YYYY-MM-DD): ";
                    cin >> fin;
                    
                    red.reiniciar_iteraciones();
                    red.buscar_mensajes_rango(usuario_logueado, inicio, fin);
                    red.reportar_consumo("Buscar mensajes por rango");
                }
            } 
            else if (opcion == "N" || opcion == "n") {
                red.reiniciar_iteraciones();
                if (red.actualizar_mejores_amigos(usuario_logueado)) {
                    cout << "\nMejores amigos actualizados (Solo se permite 1 vez por sesion):\n";
                    red.mostrar_mejores_amigos(usuario_logueado);
                } else {
                    cout << "Ya alternaste tus mejores amigos en esta sesion.\n";
                }
                red.reportar_consumo("Actualizar mejores amigos");
            } 
            else if (opcion == "S" || opcion == "s") {
                cout << "Cerrando sesion...\n";
                red.guardar_datos();
                usuario_logueado = -1;
            } 
            else {
                cout << "Opcion no valida, intente de nuevo.\n";
            }
        }
    }
    return 0;
}