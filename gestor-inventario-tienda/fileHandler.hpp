#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include "producto.hpp"
#include <vector>
#include <string>

using namespace std;

class FileHandler {
public:
    static void guardarProductos(const vector<Producto>& productos, const string& filename);
    static void cargarProductos(vector<Producto>& productos, const string& filename);
};

#endif
