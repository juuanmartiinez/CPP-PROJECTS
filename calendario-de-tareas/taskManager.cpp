#include <iostream>

#include "taskManeger.hpp"
#include "task.hpp"

using namespace std;

void TaskManager::addTask(const Task& task){
    tasks.push_back(task);

}

const Task& TaskManager::getTask(int index) const {
    return tasks[index];
}

void TaskManager::printTask() const {
    if(tasks.empty()){
        cout << "No hay tareas." << endl;
        return;
    }
    for(size_t i = 0; i < tasks.size(); i++){
        cout << "Tarea " << i+1 << ":" << endl;
        tasks[i].print();
        cout << "------------------------" << endl;
    }
}

void TaskManager::markTaskCompleted(int index){
    if(index < 0 || index >= tasks.size()){
        cout << "Indice de tarea invalido." << endl;
        return;
    }
    tasks[index].markCompleted();
    cout << "Tarea " << index + 1 << " marcada como completada." << endl;
}

void TaskManager::deleteTask(int index){
    if(index < 0 || index >= tasks.size()){
        cout << "Indice de tarea invalido." << endl;
        return;
    }
    tasks.erase(tasks.begin() + index);
    cout << "Tarea " << index + 1 << " eliminada." << endl;
}

int TaskManager::getTaskCount() const{
    return tasks.size();
}