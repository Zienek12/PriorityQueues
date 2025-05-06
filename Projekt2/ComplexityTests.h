#pragma once
#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include "LinkedListPriorityQueue.h"
#include "BinaryHeapPriorityQueue.h"

#include <climits>
#include <ctime>
#include <random>

int generateRandomNumber() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);
    return dist(gen);
}

void runComplexityTests() {
    std::string start = "C:/Users/andos/source/repos/Zienek12/PriorityQueues/Projekt2/Measurments/";
    size_t sizes[] = { 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000};
    std::vector<std::string> dataStructures = { "LinkedList", "BinaryHeap" };
    std::vector<std::string> operations = { "Enqueue", "Dequeue", "Peek", "ChangePriority", "GetSize" };
    std::string txt = ".txt";

    for (int i = 0; i < dataStructures.size(); i++) {
        for (int j = 0; j < dataStructures.size(); j++) {
            std::string fileName = start + dataStructures[i] + operations[j] + txt;
            std::ofstream file(fileName);

            if (!file.is_open()) {
                std::cerr << "Error opening file: " << fileName << std::endl;
                return;
            }

            file << "Size,Average Time\n";

            switch (j) {
            case 0: // Enqueue
                for (size_t size : sizes) {
                    if (i == 0) {
                        ListPriorityQueue<int> queue;
                        auto start = std::chrono::high_resolution_clock::now();
                        for (size_t k = 0; k < size; k++) {
                            queue.enqueue(generateRandomNumber(), generateRandomNumber());
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) / size;
                        file << size << "," << avgtime << "\n";
                    }
                    else {
                        HeapPriorityQueue<int> queue;
                        auto start = std::chrono::high_resolution_clock::now();
                        for (size_t k = 0; k < size; k++) {
                            queue.enqueue(generateRandomNumber(), generateRandomNumber());
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) / size;
                        file << size << "," << avgtime << "\n";

                    }
                    std::cout << "Enqueue " << size << " elements in " << dataStructures[i] << std::endl;
                }
                break;

            case 1: // Dequeue
                for (size_t size : sizes) {
                    if (i == 0) {
                        ListPriorityQueue<int> queue;
                        for (size_t k = 0; k < size; k++) {
                            queue.enqueue(generateRandomNumber(), generateRandomNumber());
                        }
                        auto start = std::chrono::high_resolution_clock::now();
                        for (size_t k = 0; k < size; k++) {
                            queue.dequeue();
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / size;
                        file << size << "," << avgtime << "\n";

                    }
                    else {
                        HeapPriorityQueue<int> queue;
                        for (size_t k = 0; k < size; k++) {
                            queue.enqueue(generateRandomNumber(), generateRandomNumber());
                        }
                        auto start = std::chrono::high_resolution_clock::now();
                        for (size_t k = 0; k < size; k++) {
                            queue.dequeue();
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / size;
                        file << size << "," << avgtime << "\n";

                    }
                    std::cout << "Dequeue " << size << " elements in " << dataStructures[i] << std::endl;
                }
                break;

            case 2: // Peek
                for (size_t size : sizes) {
                    if (i == 0) {
                        ListPriorityQueue<int> queue;
                        for (size_t k = 0; k < size; k++) {
                            queue.enqueue(generateRandomNumber(), generateRandomNumber());
                        }
                        auto start = std::chrono::high_resolution_clock::now();
                        for (size_t k = 0; k < size; k++) {
                            queue.peek();
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / size;
                        file << size << "," << avgtime << "\n";

                    }
                    else {
                        HeapPriorityQueue<int> queue;
                        for (size_t k = 0; k < size; k++) {
                            queue.enqueue(generateRandomNumber(), generateRandomNumber());
                        }
                        auto start = std::chrono::high_resolution_clock::now();
                        for (size_t k = 0; k < size; k++) {
                            queue.peek();
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / size;
                        file << size << "," << avgtime << "\n";

                    }
                    std::cout << "Peek " << size << " elements in " << dataStructures[i] << std::endl;
                }
                break;

            case 3: // ChangePriority
                for (size_t size : sizes) {
                    if (i == 0) {
                        ListPriorityQueue<int> queue;
						int randomPriority = generateRandomNumber();
						int randomValue = generateRandomNumber();
						queue.enqueue(randomValue, randomPriority);
                        for (size_t k = 1; k < size; k++) {
                            queue.enqueue(generateRandomNumber(), generateRandomNumber());
                        }
                        auto start = std::chrono::high_resolution_clock::now();
                        
                        queue.changePriority(randomValue, randomPriority, generateRandomNumber());
                        
                        auto end = std::chrono::high_resolution_clock::now();
                        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
                        file << size << "," << duration << "\n";
                    }
                    else {
                        HeapPriorityQueue<int> queue;
                        for (size_t k = 0; k < size; k++) {
                            queue.enqueue(generateRandomNumber(), generateRandomNumber());
                        }
                        auto start = std::chrono::high_resolution_clock::now();
                        for (size_t k = 0; k < size; k++) {
                            queue.changePriority(static_cast<int>(k), generateRandomNumber());
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) / size;
                        file << size << "," << avgtime << "\n";

                    }
                    std::cout << "ChangePriority " << size << " elements in " << dataStructures[i] << std::endl;
                }
                break;

            case 4: // GetSize
                for (size_t size : sizes) {
                    if (i == 0) {
                        ListPriorityQueue<int> queue;
                        for (size_t k = 0; k < size; k++) {
                            queue.enqueue(generateRandomNumber(), generateRandomNumber());
                        }
                        auto start = std::chrono::high_resolution_clock::now();
                        for (size_t k = 0; k < size; k++) {
                            queue.getSize();
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / size;
                        file << size << "," << avgtime << "\n";

                    }
                    else {
                        HeapPriorityQueue<int> queue;
                        for (size_t k = 0; k < size; k++) {
                            queue.enqueue(generateRandomNumber(), generateRandomNumber());
                        }
                        auto start = std::chrono::high_resolution_clock::now();
                        for (size_t k = 0; k < size; k++) {
                            queue.size();
                        }
                        auto end = std::chrono::high_resolution_clock::now();
                        double avgtime = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()) / size;
                        file << size << "," << avgtime << "\n";

                    }
                    std::cout << "GetSize " << size << " elements in " << dataStructures[i] << std::endl;
                }
                break;
            }

            file.close();
        }
    }
}
