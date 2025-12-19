CXX = g++
CXXFLAGS = -Wall -std=c++17

all: todo

todo: todo.o ToDoList.o
	$(CXX) $(CXXFLAGS) todo.o ToDoList.o -o todo

todo.o: todo.cpp ToDoList.hpp Task.hpp
	$(CXX) $(CXXFLAGS) -c todo.cpp

ToDoList.o: ToDoList.cpp ToDoList.hpp Task.hpp
	$(CXX) $(CXXFLAGS) -c ToDoList.cpp

clean:
	rm -f *.o todo
