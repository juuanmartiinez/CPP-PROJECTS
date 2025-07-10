#include "fileHandler.hpp"
#include <fstream>
#include <iostream>

void FileHandler::guardarProductos(const vector<Producto>& productos, const string& filename) {
    ofstream archivo(filename);

    if (!archivo) {
        cerr << "Error al abrir el archivo para guardar." << endl;
        return;
    }

    for (const auto& producto : productos) {
        archivo << producto.getNombre() << ","
                << producto.getCantidad() << ","
                << producto.getPrecio() << endl;
    }

    archivo.close();
}

void FileHandler::cargarProductos(vector<Producto>& productos, const string& filename) {
    ifstream archivo(filename);

    if (!archivo) {
        cerr << "Archivo no encontrado. Se comenzará con una lista vacía." << endl;
        return;
    }

    string nombre;
    int cantidad;
    double precio;
    char coma;

    while (getline(archivo, nombre, ',')) {
        archivo >> cantidad >> coma >> precio;
        archivo.ignore();  // ignorar salto de línea
        productos.emplace_back(nombre, cantidad, precio);
    }

    archivo.close();
}
