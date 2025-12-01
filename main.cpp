#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

/* ==========================================================
   PARTE 1 – Módulo de géneros
   Hecho por: Naesha
   Esta parte solo muestra los géneros y una descripción.
========================================================== */

void menuGeneros();
void moduloGeneros();

void menuGeneros() {
    // Menu con los generos basicos
    cout << "Menu de Generos\n";
    cout << "1. Accion\n";
    cout << "2. Plataformas\n";
    cout << "3. FPS\n";
    cout << "4. Aventura\n";
    cout << "5. RPG\n";
    cout << "6. Estrategia\n";
    cout << "7. Deportes\n";
    cout << "8. Carreras\n";
    cout << "9. Simulacion\n";
    cout << "10. Terror\n";
}

void moduloGeneros() {
    int opcion;

    cout << "Seleccione un genero:\n\n";
    menuGeneros();

    cout << "\nOpcion: ";
    cin >> opcion;

    cout << "\nDescripcion:\n";

    switch(opcion) {
        case 1: cout << "Accion: juegos de peleas o combates rapidos.\n"; break;
        case 2: cout << "Plataformas: juegos de saltos y obstaculos.\n"; break;
        case 3: cout << "FPS: juegos en primera persona con armas.\n"; break;
        case 4: cout << "Aventura: exploracion y puzzles.\n"; break;
        case 5: cout << "RPG: subir de nivel y misiones.\n"; break;
        case 6: cout << "Estrategia: planificacion y decisiones.\n"; break;
        case 7: cout << "Deportes: juegos basados en deportes.\n"; break;
        case 8: cout << "Carreras: manejar vehiculos.\n"; break;
        case 9: cout << "Simulacion: copiar la vida real.\n"; break;
        case 10: cout << "Terror: juegos de miedo.\n"; break;
        default: cout << "Opcion no valida.\n"; break;
    }
}


/* ==========================================================
   PARTE 2 – Manejo de archivos
   Hecho por: Emanuel
   Yo hice la parte para guardar y cargar los juegos.
   Esto es para que no se borren al cerrar el programa.
========================================================== */

void guardarJuegos(string juegos[], int horas[], int total) 
{
    ofstream archivo("juegos_guardados.txt");

    // Si el archivo no abre
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo\n";
        return;
    }

    // Guardamos cada juego con sus horas
    for (int i = 0; i < total; i++) {
        archivo << juegos[i] << "," << horas[i] << "\n";
    }

    archivo.close();
}

void cargarJuegos(string juegos[], int horas[], int &total)
{
    ifstream archivo("juegos_guardados.txt");

    // Si no existe archivo, usamos los juegos base
    if (!archivo.is_open()) {
        return;
    }

    string linea;
    total = 0;

    // Cargar linea por linea
    while (getline(archivo, linea)) {

        int pos = linea.find(',');

        if (pos != -1) {
            string nombre = linea.substr(0, pos);
            int h = stoi(linea.substr(pos + 1));

            juegos[total] = nombre;
            horas[total] = h;
            total++;
        }
    }

    archivo.close();
}


/* ==========================================================
   PARTE 3 – Lógica general, menú principal y cálculos
   Hecho por: Angel
   Angel se encargó de que todo funcione junto.
========================================================== */

double calcularHoras(int base, int tipoJugador) {
    // Dependiendo del tipo multiplicamos
    if (tipoJugador == 1) return base * 0.8;
    if (tipoJugador == 2) return base * 1.0;
    if (tipoJugador == 3) return base * 1.3;
    if (tipoJugador == 4) return base * 1.6;
    return base;
}

void mostrarJuegos(string juegos[], int horas[], int total) {
    cout << "\nLista de juegos:\n";
    for (int i = 0; i < total; i++) {
        cout << i + 1 << ". " << juegos[i] << " (" << horas[i] << "h)\n";
    }
}

void agregarJuego(string juegos[], int horas[], int &total) {
    cin.ignore();
    string nombre;
    int h;

    cout << "Nombre del juego: ";
    getline(cin, nombre);

    cout << "Horas base: ";
    cin >> h;

    juegos[total] = nombre;
    horas[total] = h;
    total++;

    cout << "Juego agregado.\n";
}

void mostrarPromedio(int horas[], int total) {
    if (total == 0) {
        cout << "No hay juegos.\n";
        return;
    }

    int s = 0;
    for (int i = 0; i < total; i++) {
        s += horas[i];
    }

    cout << "Promedio de horas: " << s / total << "\n";
}


/* ==========================================================
   MAIN – Integración de todo el proyecto
   Aquí se conectan las 3 partes del equipo.
========================================================== */

int main() {

    const int MAX = 50;
    string juegos[MAX];
    int horas[MAX];
    int total = 0;

    // Juegos que trae el programa por defecto
    juegos[0] = "GTA V"; horas[0] = 50;
    juegos[1] = "The Witcher 3"; horas[1] = 100;
    juegos[2] = "Red Dead 2"; horas[2] = 120;
    juegos[3] = "Cyberpunk 2077"; horas[3] = 90;
    total = 4;

    // Si existe archivo, se carga
    cargarJuegos(juegos, horas, total);

    int opcion = -1;

    while (opcion != 0) {

        cout << "\n--- Game Completion Time Advisor ---\n";
        cout << "1. Modulo de generos\n";
        cout << "2. Mostrar juegos\n";
        cout << "3. Agregar juego\n";
        cout << "4. Calcular tiempo\n";
        cout << "5. Promedio horas\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1:
                moduloGeneros();
                break;

            case 2:
                mostrarJuegos(juegos, horas, total);
                break;

            case 3:
                agregarJuego(juegos, horas, total);
                break;

            case 4: {
                int n, tipo;
                mostrarJuegos(juegos, horas, total);

                cout << "Juego: ";
                cin >> n;

                cout << "Tipo (1-4): ";
                cin >> tipo;

                double h = calcularHoras(horas[n-1], tipo);
                cout << "Tiempo estimado: " << h << " horas\n";
                break;
            }

            case 5:
                mostrarPromedio(horas, total);
                break;

            case 0:
                guardarJuegos(juegos, horas, total);
                cout << "Guardado.\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }
    }

    return 0;
}
