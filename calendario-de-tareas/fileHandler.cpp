#include <iostream>
#include <string>
#include <fstream>

#include "fileHandler.hpp"

using namespace std;

namespace FileHandler {

    void saveTasks(const TaskManager& manager, const string& filename){

        ofstream file(filename);

        if(!file.is_open()){
            cout << "Error al abrir el archivo." << endl;
            return;
        }

        for(int i = 0 ; i < manager.getTaskCount() ; i++){
            file << manager.getTask(i).serialize() << endl;
        }

        file.close();

    }

    void loadTasks(TaskManager& manager, const string& filename){

        ifstream file(filename);

        if(!file){
            return;
        }

        string line;

        while(getline(file, line)){
            Task task = Task::deserialize(line);
            manager.addTask(task);
        }
        file.close();
    }
}