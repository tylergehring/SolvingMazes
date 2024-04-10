#pragma once
#pragma once
#include"LinkedList.h"

using namespace std;

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
};



template<typename T>
void Queue<T>::push(T val) {
	list.push(val);
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

