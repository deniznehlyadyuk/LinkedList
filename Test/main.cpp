#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LinkedList.h"

int main()
{
	srand(time(NULL));

	LinkedList arr1 = LinkedList();
	LinkedList arr2 = LinkedList();

	std::cout << "Test: Adding elements\t(arr1)\t\t";
	for (int i = 0; i < rand() % 15 + 5; i++) {
		arr1.append(rand() % 100 + 5);
	}
	std::cout << "Passed!" << std::endl;

	std::cout << "Test: Accesing elements\t(arr1)\t\t";
	for (int i = 0; i < arr1.len(); i++) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Test: Deleting elements\t(arr1)\t\t";
	for (int i = 0; i < 3; i++) {
		arr1.del(rand() % 3 + 1);
	}
	for (int i = 0; i < arr1.len(); i++) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Test: Extend list\t(arr1->arr2)\t";
	arr2.extend(&arr1);
	for (int i = 0; i < arr2.len(); i++) {
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Test: Clear list\t(arr1)\t\t";
	arr1.clear();
	std::cout << "Passed!" << std::endl;

	std::cout << "Test: Adding elements\t(arr1)\t\t";
	for (int i = 0; i < rand() % 15 + 5; i++) {
		arr1.append(rand() % 100 + 5);
	}
	std::cout << "Passed!" << std::endl;

	std::cout << "Test: Accesing elements\t(arr1)\t\t";
	for (int i = 0; i < arr1.len(); i++) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Test: Clear list\t(arr1)\t\t";
	arr1.clear();
	std::cout << "Passed!" << std::endl;

	std::cout << "Test: Clear list\t(arr2)\t\t";
	arr2.clear();
	std::cout << "Passed!" << std::endl;

	system("pause");
	return 0;
}