#include "tienda.hpp"
#include "producto.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void Tienda::agregarProducto(const Producto& producto){
    productos.push_back(producto);
    cout << "Producto agregado: " << producto.getNombre() << endl;
}

void Tienda::eliminarProducto(int index){
    if(index < 0 || index >= productos.size()){
        cout << "Indice de producto invalido." << endl;
        return;
    }
    productos.erase(productos.begin() + index);
    cout << "Producto " << index + 1 << " eliminado." << endl;
}

void Tienda::mostrarProductos() const {
    if(productos.empty()){
        cout << "No hay productos en la tienda." << endl;
        return;
    }

    for(size_t i = 0 ; i < productos.size(); i++){
        cout << "Producto " << i + 1 << ":" << endl;
        productos[i].print();
        cout << "------------------------" << endl;
    }
}

void Tienda::guardarEnArchivo(const string& nombreArchivo) const {
    ofstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "Error al abrir el archivo para guardar." << endl;
        return;
    }

    for (const auto& producto : productos) {
        archivo << producto.serialize() << endl;
    }

    archivo.close();
    cout << "Inventario guardado correctamente en " << nombreArchivo << endl;
}

void Tienda::cargarDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo. Se comenzará con una tienda vacía." << endl;
        return;
    }

    productos.clear(); // Limpia antes de cargar
    string linea;
    while (getline(archivo, linea)) {
        Producto p = Producto::deserialize(linea);
        productos.push_back(p);
    }

    archivo.close();
    cout << "Inventario cargado desde " << nombreArchivo << endl;
}