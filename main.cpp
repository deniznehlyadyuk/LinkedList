#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
	node *prev;
};

struct linkedList{
	node *head = NULL;
	int length = 0;
	node *tmp = NULL;
	
	void *append(int data){
		if (head == NULL){
			head = new node;
			head->data = data;
			head->next = head;
			head->prev = head;
			length = 1;
		}
		else{
			head->prev->next = new node;
			head->prev->next->prev = head->prev;
			head->prev = head->prev->next;
			head->prev->next = head;
			head->prev->data = data;
			length++;
		}
	}
	
	void goToIndex(int index){
		tmp = head;
		if (head == NULL){
			cout << "TypeError: 'NULL' object is not subscriptable"	<< endl;
			exit(0);
		}
		if (index >= 0){
			if (index > length - 1){
				cout << "IndexError: list index out of range" << endl;
				exit(0);
			}
			
			for (int i = 0; i < index; i++)
				tmp = tmp->next;
			return;
		}
		else{
			if (index < length * -1){
				cout << "IndexError: list index out of range" << endl;
				exit(0);
			}
			for (int i = 0; i > index; i--)
				tmp = tmp->prev;
			return;
		}
	}
	
	int findValueIndex(int value){
		tmp = head;
		if (head == NULL){
			cout << "TypeError: 'NULL' object is not subscriptable"	<< endl;
			exit(0);
		}
		else{
			int count = 0;
			for(int i = 0; i < length; i++){
				if (tmp->data == value)
					return count;
				tmp = tmp->next;
				count++;
			}
			cout << "ValueError: list.remove(x): x not in list" << endl;
			exit(0);
		}
	}
	
	int operator[] (int index){
		goToIndex(index);
		return tmp->data;
	}
	
	void del(int index){
		goToIndex(index);
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		if (index == 0){
			head = tmp->next;
		}
		length--;
	}
	
	void remove(int value){
		findValueIndex(value);
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		if (tmp == head){
			head = tmp->next;
		}
		length--;
	}
	
	void clear(){
		head->next = NULL;
		head->prev = NULL;
		length = 0;
		delete head;
	}
	
	linkedList *copy(){
		linkedList &newList = *(new linkedList);
		
		tmp = head;
		
		for(int i = 0; i < length; i++){
			newList.append(tmp->data);
			tmp = tmp->next;
		}
		
		return &newList;
	}
	
	void reverse(){
		linkedList &newList = *(new linkedList);
		
		tmp = head;
		
		for(int i = -1; i >= length * -1; i--){
			newList.append(tmp->prev->data);
			tmp = tmp->prev;
		}
		
		head->next = NULL;
		head->prev = NULL;
		delete head;
		head = newList.head;
	}
	
	int index(int value){
		return findValueIndex(value);
	}
	
	int count(int value){
		tmp = head;
		if (head == NULL){
			cout << "TypeError: 'NULL' object is not subscriptable"	<< endl;
			exit(0);
		}
		else{
			int count = 0;
			for(int i = 0; i < length; i++){
				if (tmp->data == value)
					count++;
				tmp = tmp->next;
			}
			return count;
		}
	}
	
	void insert(int index, int data){
		goToIndex(index);
		tmp->prev->next = new node;
		tmp->prev->next->data = data;
		tmp->prev->next->prev = tmp->prev;
		tmp->prev->next->next = tmp;
		tmp->prev = tmp->prev->next;
		length++;
		
		if (index == 0){
			head = tmp->prev;
		}	
	}
};

int main(){
  return 0;
]
