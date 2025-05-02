#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
		int priority;
        Node* next;
        Node* prev;
    
        Node(const T& val, int prio) : data(val), priority(prio), prev(nullptr), next(nullptr) {}
    };


    Node* head;
    Node* tail;
    size_t size;


public:
    PriorityQueue() : head(nullptr), tail(nullptr), size(0) {}




    void enqueue(cont T& value, int priority)
    {
        Node* newNode = new Node(value, priority);
        if (head == nullptr) {
			head = newNode;
			tail = newNode;
			
        }
        else if (head->priority < priority)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else if (tail->priority > priority)
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else
        {
            Node* current = head;
            while (current != nullptr && current->priority >= priority)
            {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr)
            {
                current->next->prev = newNode;
            }
            else {
                tail = newNode;
            }
            current->next = newNode;
        }
        size++;
    }

    Node dequeue()
    {
        if (!head)
        {
            throw std::out_of_range("Queue is empty");
        }




        size--;


    }


};