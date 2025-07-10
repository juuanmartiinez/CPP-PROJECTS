#ifndef TIENDA_HPP
#define TIENDA_HPP

#include "producto.hpp"
#include <vector>

using namespace std;

class Tienda {
private:
    vector<Producto> productos;
public:
    void agregarProducto(const Producto& producto);
    void eliminarProducto(int index);
    void mostrarProductos() const;

    void guardarEnArchivo(const string& nombreArchivo) const;
    void cargarDesdeArchivo(const string& nombreArchivo);
    

};

#endif