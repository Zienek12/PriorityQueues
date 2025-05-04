#include<iostream>
#include<Windows.h>
#include"LinkedListPriorityQueue.h"
#include"BinaryHeapPriorityQueue.h"

#include"HeapInterface.h"
#include"LinkedListInterface.h"

#include"ComplexityTests.h"
void mainInterface() {
	int choice = 0;
	while(true)
	{
		std::cout << "Choose the data structure to use:\n";
		std::cout << "1. Linked List\n";
		std::cout << "2. Heap\n";
		std::cout << "3. Run time complexity tests\n";
		std::cout << "4. Exit\n";
		std::cout << "Enter your choice: ";
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			LinkedListInterface::runListPriorityQueueInterface<int>();
			break;
		case 2:
			HeapInterface::runHeapPriorityQueueInterface<int>();
			break;
		case 3:
			runComplexityTests();
			break;
		case 4:
			std::cout << "Exiting...\n";
			return;
		default:
			std::cout << "Invalid choice. Please try again.\n";
			break;
		}
	} 
}
int main()
{


	mainInterface();
	return 0;




}