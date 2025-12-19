#ifndef TODOLIST_HPP
#define TODOLIST_HPP

#include <vector>
#include <string>
#include "Task.hpp"

class ToDoList {
private:
	std::vector<Task> tasks;
public:	
	void addTask(const std::string& description);
	void listTask() const;
};

#endif
