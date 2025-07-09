#ifndef TASK_HPP
#define TASK_HPP

#include <string>

using namespace std;

class Task{

private:
    string title;
    string description;
    string date;
    int priority;
    bool completed;
public:

    Task();
    Task(const string title, const string description, const string date, int priority, bool completed);

    string getTitle() const;
    string getDescription() const;
    string getDate() const;

    int getPriority() const;
    bool isCompleted() const;

    void markCompleted();

    void print() const;

    string serialize() const;

    static Task deserialize(const string& line);


};

#endif