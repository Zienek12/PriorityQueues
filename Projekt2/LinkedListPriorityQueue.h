#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class ListPriorityQueue {
private:
    struct Element {
        T content;
        int priority;

        friend std::ostream& operator<<(std::ostream& os, const Element& element) {
            os << "Content: " << element.content << ", Priority: " << element.priority;
            return os;
        }
    };

    struct Node {
        Element data;
        Node* next;
        Node* prev;

        Node(Element ele) : data(ele), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    ListPriorityQueue() : head(nullptr), tail(nullptr), size(0) {}

    ~ListPriorityQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void enqueue(const T& content, int priority) {
        enqueue(Element{ content, priority });
    }

    void enqueue(Element ele) {
        Node* newNode = new Node(ele);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else if (head->data.priority < ele.priority) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else if (tail->data.priority >= ele.priority) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr && current->next->data.priority >= ele.priority) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            else {
                tail = newNode;
            }
            current->next = newNode;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }

        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }

        T content = temp->data.content;
        delete temp;
        size--;
        return content;
    }

    size_t getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    Element peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return head->data;
    }

    void print() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }

        Node* current = head;
        while (current) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }

    bool changePriority(const T& content, int oldPriority, int newPriority) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data.content == content && current->data.priority == oldPriority) {
                T val = current->data.content;

                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                }
                else {
                    head = current->next;
                }

                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                else {
                    tail = current->prev;
                }

                delete current;
                size--;

                enqueue(val, newPriority);
                return true;
            }
            current = current->next;
        }
        return false;
    }
};
