#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node;

class LinkedList {
private:
	Node* head;
	int length;
	Node* go2Index(int index);

public:
	LinkedList();

	void append(int data);
	void clear();
	void del(int index);
	void extend(LinkedList* arr);
	// void insert(int index, int value);
	// void remove(int value);
	// void reverse();
	// void sort();

	// int count(int value);
	// int index(int value);
	int len();
	int operator [] (int index);
	
	// LinkedList* copy();
	
};

#endif // LINKEDLIST_H