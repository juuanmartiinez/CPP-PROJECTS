#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

#include <vector>

#include "task.hpp"

class TaskManager{
private:
    vector<Task> tasks;
public:

    const Task& getTask(int index) const;
    void addTask(const Task& task);
    void printTask() const;
    void markTaskCompleted(int index);
    void deleteTask(int index);
    int getTaskCount() const;
};

#endif