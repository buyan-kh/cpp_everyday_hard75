#ifndef TODOLIST_HPP
#define TODOLIST_HPP

#include <vector>
#include <string>
#include "Task.hpp"

class ToDoList {
private:
	std::vector<Task> tasks;
public:
	ToDoList();
	~ToDoList();	
	void addTask(const std::string& description);
	void listTasks() const;
	void saveToFile(const std::string& name) const;
	void loadFromFile(const std::string& url);
	void markAsDone(int id);
};

#endif
