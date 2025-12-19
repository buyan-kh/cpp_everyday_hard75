#include "ToDoList.hpp"
#include <iostream>

void ToDoList::addTask(const std::string& description) {
	Task newTask;
	newTask.id = tasks.size() + 1;
	newTask.description = description;
	newTask.isCompleted = false;

	tasks.push_back(newTask);
}

void ToDoList::listTasks() const {
	for (const auto& task : tasks) {
		std::string status = task.isCompleted ? "X" : "[]
