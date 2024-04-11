#pragma once


#include<string>
using namespace std;
#include"LinkedList.h"
#include"queue.h"

//solves maze by utilizeing a visted array and a possible moves queue

class Solve {
private:
	LinkedList<int> visitedIdx;
	Queue<int> nextMoveIdx;
	LinkedList<char> maze;
	int xSize;
	int ySize;



public:
	Solve(string txtFile);
	bool isSolvable();  
	int findStart(); //returns index of the S character in the maze
	int findEnd(); //returns index of the G character in the maze
	bool validMove(int index); //returns true if the index is a place we can move to
	void addNextMoves(int currentIdx); //adds the possible moves to the queue
	int exicuteNextMove(); //pops next move out of queue and returns the current index
	bool inVisited(int index); // true if the char is in visited
	//bool inNextMoveIdx(int index); //true if the index value is in the queue
	void printVisitedIdx();
	void printSolved();
	
	

};


