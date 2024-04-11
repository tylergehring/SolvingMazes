#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Linkedlist.h"
using namespace std;

//reads from the target txt file and can return an LinkedList of the maze along
// with its dimentions.

class ReadMaze {
private:
	string tFile; //target file
	int xSize;
	int ySize;
	LinkedList<char> maze;
public:
	ReadMaze(string txtFile);
	string get_tFile();
	int get_xSize();
	int get_ySize();
	LinkedList<char>* get_mazePtr();
	void printMaze();
	char getMazeVal(int index);


};



