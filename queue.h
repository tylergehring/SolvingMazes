#pragma once
#pragma once
#include"LinkedList.h"

using namespace std;

// 
// THIS IS A SPECIAL CASE QUEUE
// NO REPEATED VALUES CAN BE IN THE QUEUE AT THE SAME TIME
//

template<typename T>
class Queue {
private:
	LinkedList<T> list;
public:
	void push(T val);
	T pop();
	T getFront();
	bool isEmpty();
	void print();
	int getSize();
};



template<typename T>
void Queue<T>::push(T val) {
	bool inQueue = false;
	for (int i = 0; i < list.getSize(); i++) {
		if (val == list.getVal(i)) {
			inQueue = true;
		}
	}

	if (!inQueue) {
		list.push(val);
	}
}

template<typename T>
T Queue<T>::pop() {
	return list.popFront();

}

template<typename T>
T Queue<T>::getFront() {
	return list.firstNode();
}


template<typename T>
bool Queue<T>::isEmpty() {
	if (list.isEmpty())
		return 1;
	return 0;
}

template<typename T>
void Queue<T>::print() {
	list.print();
}

template<typename T>
int Queue<T>::getSize() {
	return list.getSize();
}

