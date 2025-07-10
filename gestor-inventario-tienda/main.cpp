#include "tienda.hpp"
#include "fileHandler.hpp"
#include "producto.hpp"
#include <iostream>

using namespace std;

int main(){

    Tienda tienda;

    tienda.cargarDesdeArchivo("inventario.txt");

    int opcion;

    do{ 

        cout << "1. Agregar producto" << endl;
        cout << "2. Eliminar producto" << endl;
        cout << "3. Guardar inventario" << endl;
        cout << "4. Mostrar productos" << endl;
        cout << "5. Salir" << endl;

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        cin.ignore(); // Limpiar el buffer de entrada

        if(opcion == 1){
            string nombre;
            int cantidad;
            double precio;

            cout << "Ingrese el nombre del producto: ";
            getline(cin,nombre);
            cout << "Ingrese la cantidad del producto: ";
            cin >> cantidad;
            cout << "Ingrese el precio del producto: ";
            cin >> precio;
            cin.ignore(); // Limpiar el buffer de entrada

            Producto nuevo(nombre, cantidad, precio);

            tienda.agregarProducto(nuevo);

        }else if(opcion == 2){
            int index;

            cout << "Ingrese el indice del producto a eliminar (1 para el primero): ";
            cin >> index;

            tienda.eliminarProducto(index - 1); // Restar 1 para ajustar al índice de vector
        }else if(opcion == 3){
            tienda.guardarEnArchivo("inventario.txt");
        }else if(opcion == 4){
            tienda.mostrarProductos();
        }

    }while(opcion != 5);

    return 0;

}