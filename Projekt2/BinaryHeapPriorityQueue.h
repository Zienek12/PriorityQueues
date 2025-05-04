#pragma once
#include <iostream>
#include <stdexcept>
#include "DynamicArray.h"

template <typename T>
class HeapPriorityQueue {
private:
    struct Element {
        T value;
        int priority;

        Element() : value(T()), priority(0) {}

        Element(const T& val, int prio) : value(val), priority(prio) {}

        friend std::ostream& operator<<(std::ostream& os, const Element& element) {
            os << "Data: " << element.value << ", Priority: " << element.priority;
            return os;
        }
    };

    DynamicArray<Element> heap;

    int parent(int index) const { return (index - 1) / 2; }
    int leftChild(int index) const { return 2 * index + 1; }
    int rightChild(int index) const { return 2 * index + 2; }

    void swap(int index1, int index2) {
        Element temp = heap.get(index1);
        heap.get(index1) = heap.get(index2);
        heap.get(index2) = temp;
    }

    void heapifyUp(int index) {
        while (index > 0 && heap.get(index).priority > heap.get(parent(index)).priority) {
            swap(index, parent(index));
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int size = heap.getSize();
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < size && heap.get(left).priority > heap.get(largest).priority) {
            largest = left;
        }
        if (right < size && heap.get(right).priority > heap.get(largest).priority) {
            largest = right;
        }
        if (largest != index) {
            swap(index, largest);
            heapifyDown(largest);
        }
    }

public:
    void enqueue(const T& value, int priority) {
        Element newElement = { value, priority };
        heap.addBack(newElement);
        heapifyUp(heap.getSize() - 1);
    }

    void print() const {
        for (int i = 0; i < heap.getSize(); i++) {
            std::cout << heap.get(i) << std::endl;
        }
    }

    T dequeue() {
        if (empty()) {
            throw std::out_of_range("Heap is empty");
        }
        Element root = heap.get(0);
        heap.get(0) = heap.get(heap.getSize() - 1);
        heap.removeBack();
        if (heap.getSize() > 0) {
            heapifyDown(0);
        }
        return root.value;
    }

    void changePriority(int index, int newPriority) {
        if (index < 0 || index >= heap.getSize()) {
            throw std::out_of_range("Index out of range");
        }
        int oldPriority = heap.get(index).priority;
        heap.get(index).priority = newPriority;

        if (newPriority > oldPriority) {
            heapifyUp(index);
        }
        else {
            heapifyDown(index);
        }
    }

    const Element& peek() const {
        if (empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return heap.get(0);
    }

    size_t size() const {
        return heap.getSize();
    }

    bool empty() const {
        return heap.getSize() == 0;
    }
};
