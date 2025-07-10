#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP

#include <string>

using namespace std;

class Producto {
private:
    string nombreProducto;
    int cantidadProducto;
    double precioProducto;
public:

    Producto(string nombre, int cantidad, double precio)
        : nombreProducto(nombre), cantidadProducto(cantidad), precioProducto(precio) {}

    string getNombre() const;
    int getCantidad() const;
    double getPrecio() const;
    
    string serialize() const;
    static Producto deserialize(const string& line);

    

    void print() const;
};

#endif