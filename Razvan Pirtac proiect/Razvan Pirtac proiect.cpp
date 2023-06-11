#include "pch.h"
#include <iostream>
#include <vector>

using namespace System;

class Task {
private:
    std::string description;
    bool completed;

public:
    Task(const std::string& desc) : description(desc), completed(false) {
        std::cout << "Task created: " << description << std::endl;
    }

    ~Task() {
        std::cout << "Task destroyed: " << description << std::endl;
    }

    void complete() {
        completed = true;
        std::cout << "Task completed: " << description << std::endl;
    }

    void display() const {
        std::cout << "- [" << (completed ? "x" : " ") << "] " << description << std::endl;
    }
};

class ToDoList {
private:
    std::vector<Task*> tasks;

public:
    ToDoList() {}

    ~ToDoList() {
        for (Task* task : tasks) {
            delete task;
        }
    }

    void addTask(const std::string& desc) {
        Task* newTask = new Task(desc);
        tasks.push_back(newTask);
    }

    void completeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            Task* task = tasks[index];
            task->complete();
        }
        else {
            std::cout << "Invalid task index!" << std::endl;
        }
    }

    void displayTasks() const {
        std::cout << "To-Do List:" << std::endl;
        for (const Task* task : tasks) {
            task->display();
        }
    }
};

int main() {
    ToDoList toDoList;

    toDoList.addTask("Buy groceries");
    toDoList.addTask("Clean the house");
    toDoList.addTask("Pay bills");

    toDoList.displayTasks();

    toDoList.completeTask(1);

    toDoList.displayTasks();

    return 0;
}