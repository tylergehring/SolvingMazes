#include"fileHandling.h"
#include"additionalFuncts.h"
#include"mazeSolution.h"
using namespace std;
#include<queue>


// using comand line arguments, give a txt file maze that can be solved using queses 





int main() {
	bool x;
	/*
	Solve maze1("maze1.txt");
	x = maze1.isSolvable();
	cout << "The Maze is: " << x << endl;

	maze1.printVisitedIdx();
	
	
	Solve maze2("maze2.txt");
	x = maze2.isSolvable();
	cout << "The Maze is: " << x << endl;

	Solve maze3("maze3.txt");
	x = maze3.isSolvable();
	cout << "The Maze is: " << x << endl;
	*/
	Solve maze4("maze4.txt");
	x = maze4.isSolvable();
	cout << "The Maze is: " << x << endl;
	
	return 0;
	
}


