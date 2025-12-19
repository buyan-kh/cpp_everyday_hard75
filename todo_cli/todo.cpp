#include "Task.hpp"
#include "ToDoList.hpp"
#include <iostream>

int main() {
	ToDoList myTodo;
	int choice;
	myTodo.loadFromFile("tasks.txt");

	while(true) {
		std::cout << "\n--- TODO LIST ---\n";
		std::cout << "1. Add Task\n2. List Task\n3. Mark Task as Done\n4. Exit\nSelection: ";
		std::cin >> choice;

		if (choice == 4) {
			break;
		}
		switch (choice) {
			case 1: {
					std::cout << "Enter task: ";
					std::cin.ignore();
					std::string desc;
					std::getline(std::cin, desc);
					myTodo.addTask(desc);
					break;
				}
			case 2: {
					myTodo.listTasks();
					break;
				}
			case 3: {
					int id;
					std::cout << "Enter task ID to mark as done: ";
					std::cin >> id;
					myTodo.markAsDone(id);
					break;
				}

			default:
				std::cout << "Invalid choice!\n";
		}
	}
}

