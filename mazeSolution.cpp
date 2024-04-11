#include"mazeSolution.h"
#include<iostream>
#include"fileHandling.h"

using namespace std;


Solve::Solve(string txtFile) {

	ReadMaze mz(txtFile);

	xSize = mz.get_xSize();
	ySize = mz.get_ySize();

	//make a copy of vector... this is temparary
	for (int i = 0; i < (xSize * ySize); i++) {
		maze.push(mz.getMazeVal(i));
	}

}

bool Solve::isSolvable() {
	int currentIdx = findStart();
	bool solvable = 0;
	
	while (currentIdx < (xSize * ySize)) {
		//cout << currentIdx << endl;
		visitedIdx.push(currentIdx);
		addNextMoves(currentIdx);

		//if queue is not empty, pop from the top and reassign curr idx
		if (nextMoveIdx.getSize() > 0) {
			currentIdx = exicuteNextMove();

			if (currentIdx == findEnd()) {
				solvable = true;
				break;
			}
		}
		else {
			break;
		}
	}

	

	return solvable;
}

//returns index of the S character in the maze
int Solve::findStart() {
	for (int i = 0; i < (xSize * ySize); i++) {
		if (tolower(maze.getVal(i) == 's')) {
			return i;
		}
	}
	
	//if no 's' char in array
	cout << "NO START> SOLVE::FINDSTART()" << endl;
	return -100;
	
}

//returns index of the G character in the maze
int Solve::findEnd() {
	for (int i = 0; i < (xSize * ySize); i++) {
		if (tolower(maze.getVal(i)) == 'g') {
			return i;
		}
	}

	//if no 's' char in array
	cout << "NO END> SOLVE::FINDEND()" << endl;
	return -100;
}

//returns true if the index is a place we can move to
bool Solve::validMove(int index) {
	if (maze.getVal(index) == '.' || maze.getVal(index) == 'g') {
		return 1;
	}
	return 0;
}

//adds the possible moves to the queue
void Solve::addNextMoves(int index) {
	//since we cannot divide by zero, we check the 0 index first
	if (index == 0) {
		//CHECK RIGHT INDEX
		if (validMove(index + 1) && !inVisited(index + 1)) {
			nextMoveIdx.push(index + 1);
			maze.assign(index, '>');
		}

		//CHECK BOTTOM INDEX
		if (validMove(index + xSize) && !inVisited(index + xSize)) {
			nextMoveIdx.push(index + xSize);
			maze.assign(index, '|');
		}
	}
	else {
		//CHECK LEFT INDEX
		if ((index % xSize) != 0 && validMove(index - 1) && !inVisited(index - 1)) {
			nextMoveIdx.push(index - 1);
			maze.assign(index, '<');
		}

		//CHECK RIGHT INDEX
		if ((index % xSize) != (xSize - 1) && validMove(index + 1) && !inVisited(index + 1)) {
			nextMoveIdx.push(index + 1);
			maze.assign(index, '>');
		}

		//CHECK BOTTOM INDEX
		if (index < (xSize * (ySize - 1)) && validMove(index + xSize) && !inVisited(index + xSize)) {
			nextMoveIdx.push(index + xSize);
			maze.assign(index, '|');
		}

		//CHECK UPPER INDEX
		if (index > xSize && validMove(index - xSize) && !inVisited(index - xSize)) {
			nextMoveIdx.push(index - xSize);
			maze.assign(index, '|');
		}
	}
}


//pops next move out of the queue and returns the current index
int Solve::exicuteNextMove() {

	int idx = nextMoveIdx.getFront();
	nextMoveIdx.pop();
	return idx;
}

//returns true if the index is in visited
bool Solve::inVisited(int index) {
	for (int i = 0; i < visitedIdx.getSize(); i++) {
		if (visitedIdx.getVal(i) == index) {
			return 1;
		}
	}
	return 0;
}

/*
bool Solve::inNextMoveIdx(int index) {
	for (int i = 0; i < nextMoveIdx.size(); i++) {
		if (nextMoveIdx. == index) {
			return 1;
		}
	}
	return 0;
}
*/

void Solve::printVisitedIdx() {
	for (int i = 0; i < visitedIdx.getSize(); i++) {
		cout << visitedIdx.getVal(i)<< endl;
	}
}

void Solve::printSolved() {
	for (int i = 0; i < (xSize * ySize); i++) {
		cout << maze.getVal(i);
		if ((i % xSize) == (xSize - 1)) {
			cout << "\n";
		}
	}
}