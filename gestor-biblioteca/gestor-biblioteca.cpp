#include <iostream>
#include <vector>
#include <limits>
#include <fstream>

using namespace std;

const int max_char = 50;

struct biblioteca {
    char nombre[max_char];
    char tipo[max_char];
    int numeroPasillo;
    int numeroEstanteria;
};

void cargarLibrosDesdeArchivo(const string& nombreArchivo, vector<biblioteca>& libros) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }

    biblioteca libro;
    while (archivo.getline(libro.nombre, max_char)) {
        archivo.getline(libro.tipo, max_char);
        archivo >> libro.numeroPasillo;
        archivo.ignore(); 
        archivo >> libro.numeroEstanteria;
        archivo.ignore(); 

        libros.push_back(libro);
    }

    archivo.close();
    cout << libros.size() << " libros cargados desde el archivo." << endl;
}


void mostrarDatos(biblioteca &b) {
    cout << "Nombre: " << b.nombre << endl;
    cout << "Tipo: " << b.tipo << endl;
    cout << "Numero de Pasillo: " << b.numeroPasillo << endl;
    cout << "Numero de Estanteria: " << b.numeroEstanteria << endl;
    cout << "------------------------" << endl;
}

void mostrarTodosLibros(const vector<biblioteca> &libros) {
    if(libros.empty()) {
        cout << "No hay libros en la biblioteca." << endl;
        return;
    }
    for (size_t i = 0; i < libros.size(); i++) {
        cout << "Libro #" << i+1 << ":" << endl;
        mostrarDatos(const_cast<biblioteca&>(libros[i]));
    }
}

void introducirLibro (biblioteca &b){

    cout << "Introduce el nombre del libro: ";
    cin.ignore();
    cin.getline(b.nombre, max_char);

    cout << "Introduce el tipo de libro: ";
    cin.getline(b.tipo, max_char);

    cout << "Introduce el numero de pasillo: ";
    cin >> b.numeroPasillo;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Introduce el numero de estanteria: ";
    cin >> b.numeroEstanteria;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}

void eliminarLibro(vector<biblioteca> &libros) {
    if(libros.empty()) {
        cout << "No hay libros para eliminar." << endl;
        return;
    }

    int index;
    cout << "Introduce el numero del libro a eliminar (1-" << libros.size() << "): ";
    cin >> index;

    if(index < 1 || index > libros.size()) {
        cout << "Numero de libro invalido." << endl;
        return;
    }

    libros.erase(libros.begin() + index - 1);
    cout << "Libro eliminado correctamente." << endl;
}

int main (){

    int opcion;
    vector <biblioteca> libros;

    cargarLibrosDesdeArchivo("libros.txt", libros);

    while(true){

        cout << "1.INTRODUCIR NUEVO LIBRO: " << endl;
        cout << "2.MOSTRAR LIBROS: " << endl;
        cout << "3.ELIMINAR LIBRO: " << endl;
        cout << "4.SALIR: " << endl;

        cout << "Selecciona una opcion: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(opcion == 1){
            biblioteca nuevoLibro;
            introducirLibro(nuevoLibro);
            libros.push_back(nuevoLibro);
        }else if(opcion == 2){
            mostrarTodosLibros(libros);
        }else if(opcion == 3){
            eliminarLibro(libros);
        }else if(opcion == 4){
            cout << "Saliendo del programa." << endl;
            break;
        }else{
            cout << "La opcion introducida no es válida." << endl;
        }
        cout << "------------------------" << endl;
    }

    return 0;
}