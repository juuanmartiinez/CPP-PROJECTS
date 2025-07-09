#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <string>
#include "taskManeger.hpp"

using namespace std;

namespace FileHandler{

    void saveTasks(const TaskManager& TaskManager, const string& filename);
    void loadTasks(TaskManager& TaskManager, const string& filename);
    
}

#endif