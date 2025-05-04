#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "BinaryHeapPriorityQueue.h"
namespace HeapInterface
{

    void displayMenu() {
        std::cout << "\n===== Heap Priority Queue Menu =====\n";
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
    void handleEnqueue(HeapPriorityQueue<T>& queue) {
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
    void handleDequeue(HeapPriorityQueue<T>& queue) {
        try {
            T value = queue.dequeue();
            std::cout << "Dequeued element with value: " << value << "\n";
        }
        catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    template <typename T>
    void handlePeek(const HeapPriorityQueue<T>& queue) {
        try {
            auto element = queue.peek();
            std::cout << "Top element - " << element << "\n";
        }
        catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    template <typename T>
    void handleChangePriority(HeapPriorityQueue<T>& queue) {
        int index, newPriority;

        std::cout << "Enter index of element to change: ";
        while (!(std::cin >> index)) {
            std::cout << "Invalid input. Please enter an integer for index: ";
            std::cin.clear();
        }

        std::cout << "Enter new priority: ";
        while (!(std::cin >> newPriority)) {
            std::cout << "Invalid input. Please enter an integer for priority: ";
            std::cin.clear();
        }

        try {
            queue.changePriority(index, newPriority);
            std::cout << "Priority changed successfully.\n";
        }
        catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    template <typename T>
    void runHeapPriorityQueueInterface() {
        HeapPriorityQueue<T> queue;
        int choice;

        do {
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
                std::cout << "\nElements in the queue:\n";
                queue.print();
                break;
            case 6:
                std::cout << "Queue size: " << queue.size() << "\n";
                break;
            case 7:
                std::cout << "Queue is " << (queue.empty() ? "empty" : "not empty") << "\n";
                break;
            case 8:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }
            system("pause");
            system("cls");

        } while (choice != 8);
    }
}