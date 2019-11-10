#include <iostream>
#include "linkedList.h"

class Node {
public:
	int m_data;
	Node* m_next;
	Node* m_prev;
};

LinkedList::LinkedList() {
	head = nullptr;
	length = 0;
}

Node* LinkedList::go2Index(int index) {
	if (length == 0 || (index >= 0 && index >= length) || (index < 0 && index < -1*length)) {
		return NULL;
	} else {
		Node* tmp = new Node();
		tmp = head;
		if (index > 0) {
			for (int i = 0; i < index; i++) {
				tmp = tmp->m_next;
			}
		} else {
			for (int i = 0; i < -1*index; i++) {
				tmp = tmp->m_prev;
			}
		}
		return tmp;
	}
}

void LinkedList::append(int data) {
	if (head == nullptr) {
		head = new Node();
		head->m_data = data;
		head->m_next = head;
		head->m_prev = head;
	} else {
		Node* tmp = new Node;
		tmp->m_data = data;
		tmp->m_next = head;
		tmp->m_prev = head->m_prev;
		head->m_prev->m_next = tmp;
		head->m_prev = tmp;
	}
	length++;
}

int LinkedList::operator [] (int index) {
	Node* tmp = go2Index(index);
	if (tmp == NULL) {
		std::cerr << std::endl << "Index Error" << std::endl;
		return 0;
	}
	return tmp->m_data;
}

void LinkedList::del(int index) {
	Node* tmp = go2Index(index);

	if (tmp == NULL) {
		std::cerr << std::endl << "Index Error" << std::endl;
	} else {
		if (--length == 0) {
			head = nullptr;
		} else {
			tmp->m_prev->m_next = tmp->m_next;
			tmp->m_next->m_prev = tmp->m_prev;
			index || (head = tmp->m_next);
		}
		delete tmp;
	}
}

void LinkedList::extend(LinkedList* arr) {
	Node* tmp = arr->head;

	if (arr->length != 0) {
		for (int i = 0; i < arr->length; i++) {
			this->append(tmp->m_data);
			tmp = tmp->m_next;
		}
	}
}

int LinkedList::len() {
	return length;
}

void LinkedList::clear() {
	Node* tmp;
	for (int i = 0; i < length; i++) {
		tmp = head->m_next;
		delete head;
		head = tmp;
	}
	length && (length = 0);
	head = nullptr;
}