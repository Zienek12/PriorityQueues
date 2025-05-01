#pragma once
#include <iostream>

template <typename T>
class DynamicArray {
private:
    T* arr;
    int size;
    int capacity;

    void resize() {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        T* newArr = new T[newCapacity];

        int elementsToCopy = (size > newCapacity) ? newCapacity : size;
        for (int i = 0; i < elementsToCopy; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    DynamicArray(int initialCapacity = 2) : capacity(initialCapacity), size(0) {
        arr = new T[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void addBack(const T& value) {
        if (size == capacity) {
            resize();
        }
        arr[size] = value;
        size++;
    }

    void removeBack() {
        if (size == 0) {
            throw std::out_of_range("Array is empty");
        }
        size--;
    }

    T& get(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    const T& get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    void set(int index, const T& value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        arr[index] = value;
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};