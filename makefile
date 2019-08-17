# Example makefile compiling the thread examples

# Basic CPP flags with threads
CXX = g++ -g -std=c++14 -pthread

# Save lib path in variable
LIB=-I ./lib

# Specify additional includes
INC=-I/usr/local/include

# Set app name
FNAME=parameters

# Set dependencies needed to compile
#HEADERS = $(LIB)/Graph.h $(LIB)/GUI.h $(LIB)/Simple_window.h $(LIB)/std_lib_facilities.h $(LIB)/Window.h
#DEPS = $(LIB)/Graph.cpp $(LIB)/Window.cpp $(LIB)/GUI.cpp $(LIB)/Simple_window.cpp


app:
	$(CXX) $(INC) $(FNAME).cpp -o $(FNAME) $(LIB)
