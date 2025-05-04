#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
#include"LinkedListPriorityQueue.h"
namespace LinkedListInterface
{
	void displayMenu() {
		std::cout << "\n===== Doubly Linked List Priority Queue Menu =====\n";
		std::cout << "1. Enqueue element\n";
		std::cout << "2. Dequeue element\n";
		std::cout << "3. Peek at top element\n";
		std::cout << "4. Change priority of element\n";
		std::cout << "5. Print all elements\n";
		std::cout << "6. Get queue size\n";
		std::cout << "7. Check if queue is empty\n";
		std::cout << "8. Exit\n";
		std::cout << "===================================\n";
		std::cout << "Enter your choice: ";
	}

	template <typename T>
	void handleEnqueue(ListPriorityQueue<T>& queue) {
		T value;
		int priority;
		std::cout << "Enter value: ";
		std::cin >> value;
		std::cout << "Enter priority: ";
		while (!(std::cin >> priority)) {
			std::cout << "Invalid input. Please enter an integer for priority: ";
			std::cin.clear();
		}
		queue.enqueue(value, priority);
		std::cout << "Element added to the queue.\n";
	}

	template <typename T>
	void handleDequeue(ListPriorityQueue<T>& queue) {
		try {
			auto element = queue.dequeue();
			std::cout << "Dequeued element - " << element << "\n";
		}
		catch (const std::out_of_range& e) {
			std::cout << "Error: " << e.what() << "\n";
		}
	}

	template <typename T>
	void handlePeek(const ListPriorityQueue<T>& queue) {
		try {
			auto element = queue.peek();
			std::cout << "Top element - " << element << "\n";
		}
		catch (const std::out_of_range& e) {
			std::cout << "Error: " << e.what() << "\n";
		}
	}

	template <typename T>
	void handleChangePriority(ListPriorityQueue<T>& queue) {
		T value;
		int oldPriority, newPriority;
		std::cout << "Enter value of element to change: ";
		std::cin >> value;
		std::cout << "Enter old priority: ";
		while (!(std::cin >> oldPriority)) {
			std::cout << "Invalid input. Please enter an integer for old priority: ";
			std::cin.clear();
		}
		std::cout << "Enter new priority: ";
		while (!(std::cin >> newPriority)) {
			std::cout << "Invalid input. Please enter an integer for new priority: ";
			std::cin.clear();
		}
		if (queue.changePriority(value, oldPriority, newPriority)) {
			std::cout << "Priority changed successfully.\n";
		}
		else {
			std::cout << "Element not found or priority change failed.\n";
		}
	}

	template <typename T>
	void handlePrint(const ListPriorityQueue<T>& queue) {
		try {
			queue.print();
		}
		catch (const std::out_of_range& e) {
			std::cout << "Error: " << e.what() << "\n";
		}
	}

	template <typename T>
	void handleSize(const ListPriorityQueue<T>& queue) {
		std::cout << "Queue size: " << queue.getSize() << "\n";
	}

	template <typename T>
	void handleIsEmpty(const ListPriorityQueue<T>& queue) {
		if (queue.isEmpty()) {
			std::cout << "Queue is empty.\n";
		}
		else {
			std::cout << "Queue is not empty.\n";
		}
	}


	template <typename T>
	void runListPriorityQueueInterface() {
		ListPriorityQueue<T> queue;
		int choice;
		while (true) {
			displayMenu();
			std::cin >> choice;
			switch (choice) {
			case 1:
				handleEnqueue(queue);
				break;
			case 2:
				handleDequeue(queue);
				break;
			case 3:
				handlePeek(queue);
				break;
			case 4:
				handleChangePriority(queue);
				break;
			case 5:
				handlePrint(queue);
				break;
			case 6:
				handleSize(queue);
				break;
			case 7:
				handleIsEmpty(queue);
				break;
			case 8:
				std::cout << "Exiting...\n";
				return;
			default:
				std::cout << "Invalid choice. Please try again.\n";
			}
			system("pause");
			system("cls");
		}
	}
}