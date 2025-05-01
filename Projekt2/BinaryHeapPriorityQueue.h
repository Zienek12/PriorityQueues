#pragma once
#include <iostream>
#include <stdexcept>
#include "DynamicArray.h"
struct Element {
	int value;
	int priority;

	friend std::ostream& operator<<(std::ostream& os, const Element& element) {
		os << "Value: " << element.value << ", Priority: " << element.priority;
		return os;
	}
};

class PriorityQueue {
private:
	DynamicArray<Element> heap;

	int parent(int index) {
		return (index - 1) / 2;
	}
	int leftChild(int index) {
		return 2 * index + 1;
	}
	int rightChild(int index) {
		return 2 * index + 2;
	}
	void swap(int index1, int index2) {
		Element temp = heap.get(index1);
		heap.get(index1) = heap.get(index2);
		heap.get(index2) = temp;
	}
	
};