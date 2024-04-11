#include"fileHandling.h"
#include"additionalFuncts.h"


ReadMaze::ReadMaze(string txtFile) {
	tFile = txtFile;
	fstream mFile; //mazefile

	mFile.open(tFile);
	string temp;

	//Getting the x and y sizes of the map
	getline(mFile, temp, ' '); //read till the first space
	xSize = strToInt(temp); //covert string to num

	getline(mFile, temp, '\n');
	ySize = strToInt(temp);


// reading the maze into a vector object.
	char c;
	int i = 0;

	while (mFile >> std::noskipws >> c) {
		if (c != ' ' && c != '\n') {
			c = tolower(c);
			maze.push(c);
			i++;
		}

	}

	mFile.close();
}

string ReadMaze::get_tFile() {
	return tFile;
}

int ReadMaze::get_xSize() {
	return xSize;
}

int ReadMaze::get_ySize() {
	return ySize;
}

LinkedList<char>* ReadMaze::get_mazePtr() {
	return &maze;
}

void ReadMaze::printMaze() {
	maze.print();
}

char ReadMaze::getMazeVal(int index) {
	return maze.getVal(index);
}