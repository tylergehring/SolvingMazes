/* SolvingMazes
 *
 * CS 121.Bolden.........Compiler version...........Tyler Gehring
 * 4/12/2024 .................Computer & CPU.............gehr6306@vandals.uidaho.edu
 *
 * Purpose of this program is to be able to determine if a maze is solvable based on a 
 * predetermined set of rules.
 * My GitHub code https://github.com/tylergehring/SolvingMazes
 *---------------------------------------------------------------------
 */

#include"fileHandling.h"
#include"additionalFuncts.h"
#include"mazeSolution.h"
using namespace std;
#include<queue>






int main() {
	cout << "ASSIGNMENT2.CPP: READS, CREATES, AND HANDLES SETS FROM A TXT DOC..." << endl;
	cout << "PROGRAMED BY TYLER GEHRING, 4/12/24\n" << endl;
	
	bool x;

	cout << "\n" << "-------- MAZE 1 --------" << endl;

	Solve maze1("maze1.txt");
	x = maze1.isSolvable();
	cout << "The Maze is: " << x << endl;
	maze1.printSolved();
	
	cout << "\n" << "-------- MAZE 2 --------" << endl;

	Solve maze2("maze2.txt");
	x = maze2.isSolvable();
	cout << "The Maze is: " << x << endl;
	maze2.printSolved();
	
	cout << "\n" << "-------- MAZE 3 --------" << endl;
	
	Solve maze3("maze3.txt");
	x = maze3.isSolvable();
	cout << "The Maze is: " << x << endl;
	maze3.printSolved();
	
	cout << "\n" << "-------- MAZE 4 --------" << endl;
	
	Solve maze4("maze4.txt");
	x = maze4.isSolvable();
	cout << "The Maze is: " << x << endl;
	maze4.printSolved();

	return 0;
	
}


