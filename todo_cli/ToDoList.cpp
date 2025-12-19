#include "ToDoList.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void ToDoList::addTask(const std::string& description) {
	Task newTask;
	newTask.id = tasks.size() + 1;
	newTask.description = description;
	newTask.isCompleted = false;

	tasks.push_back(newTask);
}

void ToDoList::listTasks() const {
	for (const auto& task : tasks) {
		std::string status = task.isCompleted ? "[X]" : "[ ]";
		std::cout << task.id << ". " << status << " " << task.description << std::endl;
	}
}

void ToDoList::saveToFile(const std::string& name) const {
	std::ofstream outFile(name);

	if (outFile.is_open()) {
		for (const auto& task : tasks) {
			outFile << task.id << "|"
				<< task.isCompleted << "|"
				<< task.description << "\n";
		}
		outFile.close();
	}
}

void ToDoList::loadFromFile(const std::string& name) {
	std::ifstream inFile(name);
	if (!inFile.is_open()) return;

	std::string line;
	
	while(std::getline(inFile, line)) {
		std::stringstream ss(line);
		std::string idStr, statusStr, description;

		std::getline(ss, idStr, '|');
		std::getline(ss, statusStr, '|');
		std::getline(ss, description, '|');

		if (!idStr.empty() && !statusStr.empty()) {
			Task loadedTask;
			loadedTask.id = std::stoi(idStr);
			loadedTask.isCompleted = (statusStr == "1");
			loadedTask.description = description;

			tasks.push_back(loadedTask);
		}
	}
	inFile.close();
}

void ToDoList::markAsDone(int id) {
	for (auto& task : tasks) {
		if (task.id == id) {
			task.isCompleted = true;
			std::cout << "Task" << id << " marked as completed!\n";
			return;
		}
	}
	std::cout << "Task with ID " << id << " not found.\n";
}


ToDoList::ToDoList() {}
ToDoList::~ToDoList() {
	saveToFile("tasks.txt");
	std::cout << "Data auto saved. Goodbye!" << std::endl;
}
