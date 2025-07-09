#include <iostream>

#include "calendar.hpp"
#include "task.hpp"
#include "taskManeger.hpp"
#include "fileHandler.hpp"

using namespace std;

int main(){

    TaskManager manager;
    const string filename = "tasks.txt";

    FileHandler::loadTasks(manager, filename);

    int opcion;

    do{

        cout << "------ BIENVENIDO AL GESTOR DE TAREAS ------" << endl;
        cout << "1. Agregar tarea" << endl;
        cout << "2. Ver tareas" << endl;
        cout << "3. Ver tareas por fecha" << endl;
        cout << "4. Ver tareas pendientes" << endl;
        cout << "5. Marcar tarea como completada" << endl;
        cout << "6. Eliminar tarea"  << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        cin.ignore(); 

        if(opcion == 1){
            string title, description, date;
            int priority;

            cout << "Titulo de la tarea: ";
            getline(cin, title);

            cout << "Descripcion de la tarea: ";
            getline(cin, description);

            cout << "Fecha limite(YYYY-MM-DD): ";
            getline(cin, date);

            while (!Calendar::isValidate(date)) {
                cout << "Fecha invalida. Ingrese nuevamente (YYYY-MM-DD): ";
                getline(cin, date);
            }
            
            cout << "Prioridad (1-5): ";
            cin >> priority;

            cin.ignore();
            
            Task newTask(title, description, date, priority, false);

            manager.addTask(newTask);
            cout << "Tarea agregada exitosamente." << endl;
        }else if(opcion == 2){
            manager.printTask();
        }else if(opcion == 3){
            
            string date;

            cout << "Ingrese la fecha (YYYY-MM-DD): ";
            getline(cin, date);

            while (!Calendar::isValidate(date)) {
                cout << "Fecha invalida. Ingrese nuevamente (YYYY-MM-DD): ";
                getline(cin, date);
            }
            
            bool encontrado = false;

            for(int i = 0 ; i < manager.getTaskCount() ; i++){
                if(manager.getTask(i).getDate() == date){
                    manager.getTask(i).print();
                    cout << "-----------------\n";
                    encontrado = true;
                }
            }
            if(!encontrado){
                cout << "No hay tareas para la fecha " << date << "." << endl;
            }

        }else if(opcion == 4){
            bool hayPendientes = false;

            for(int i = 0 ; i < manager.getTaskCount() ; i++){
                if(!manager.getTask(i).isCompleted()){
                    cout << "Tarea pendiente " << i + 1 << ":" << endl;
                    manager.getTask(i).print();
                    cout << "-----------------\n";
                    hayPendientes = true;
                }
            }
            if(!hayPendientes){
                cout << "No hay tareas pendientes." << endl;
            }
        }else if(opcion == 5){
            int indice;
            
            manager.printTask();

            cout << "Ingrese el indice de la tarea a marcar como completada: ";
            cin >> indice;

            cin.ignore();

            manager.markTaskCompleted(indice - 1);
        }else if(opcion == 6){
            int indice;

            manager.printTask();

            cout << "Ingrese el indice de la tarea a eliminar: ";
            cin >> indice;

            cin.ignore();

            manager.deleteTask(indice - 1);
        }

    }while(opcion != 7);

    FileHandler::saveTasks(manager, filename);

    cout << "TAREAS GUARDADAS!" << endl;

    return 0;

}