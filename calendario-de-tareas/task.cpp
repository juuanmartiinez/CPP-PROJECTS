#include <iostream>
#include <sstream>

#include "task.hpp"

using namespace std;

Task::Task() : title(""), description(""), date(""), priority(3), completed(false){}

Task::Task(const string t, const string d, const string dt, int p, bool c)
    : title(t), description(d), date(dt), priority(p), completed(c) {}

string Task::getTitle() const{
    return title;
}

string Task::getDescription() const{
    return description;
}

string Task::getDate() const{
    return date;
}

int Task::getPriority() const{
    return priority;
}

bool Task::isCompleted() const{
    return completed;
}

void Task::markCompleted(){
    completed=true;
}

void Task::print() const{
    cout << "Title: " << title << endl;
    cout << "Description: " << description << endl;
    cout << "Date: " << date << endl;
    cout << "Priority: " << priority << endl;
    cout << "Completed: " << (completed ? "Yes" : "No") << endl;
}


string Task::serialize() const {
    return title + "|" + description + "|" + date + "|" + to_string(priority) + "|" + (completed ? "1" : "0");
}


Task Task::deserialize(const string& line) {
    stringstream ss(line);
    string t, d, date, prioStr, compStr;

    getline(ss, t, '|');
    getline(ss, d, '|');
    getline(ss, date, '|');
    getline(ss, prioStr, '|');
    getline(ss, compStr, '|');

    bool completed = (compStr == "1");

    Task task(t, d, date, stoi(prioStr), completed);
    if (compStr == "1") task.markCompleted();

    return task;
}