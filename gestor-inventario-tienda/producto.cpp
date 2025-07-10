#include "producto.hpp"

#include <iostream>
#include <string>

using namespace std;

string Producto::getNombre() const {
    return nombreProducto;
}

int Producto::getCantidad() const {
    return cantidadProducto;
}

double Producto::getPrecio() const {
    return precioProducto;
}

void Producto::print() const{
    cout << "Nombre: " << nombreProducto << endl;
    cout << "Cantidad: " << cantidadProducto << endl;
    cout << "Precio: " << precioProducto << endl;
}

#include <sstream>

string Producto::serialize() const {
    // Formato simple: nombre,cantidad,precio
    ostringstream oss;
    oss << nombreProducto << "," << cantidadProducto << "," << precioProducto;
    return oss.str();
}

Producto Producto::deserialize(const string& line) {
    istringstream iss(line);
    string nombre;
    int cantidad;
    double precio;
    char delim;

    // Leer nombre (hasta la primera coma)
    getline(iss, nombre, ',');
    // Leer cantidad y precio
    iss >> cantidad >> delim >> precio;

    return Producto(nombre, cantidad, precio);
}
