#include "utilities.h"
#include <iostream>
#include <limits>
#include <chrono>
#include <ctime>

int pedirEntero(const string& mensaje) {
    int valor;
    cout << mensaje;
    while (!(cin >> valor)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Intente de nuevo: ";
    }
    return valor;
}

double pedirDouble(const string& mensaje) {
    double valor;
    cout << mensaje;
    while (!(cin >> valor)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Intente de nuevo: ";
    }
    return valor;
}

void pausar() {
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

string obtenerFechaHoraActual() {
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    return string(ctime(&now_c));
}
