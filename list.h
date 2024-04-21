#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& newData) : data(newData), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    LinkedList();
    ~LinkedList();

    void push_back(T newData);
    void insertAt(int index, const T& newData);
    void removeAt(int index);
    void removeVal(T value);
    LinkedList<T>::Node* findAt(int index) const;
    T getVal(LinkedList<T>::Node* cur);
    LinkedList<T>::Node* begin() const;
    LinkedList<T>::Node* end() const;
    int length();
    void print() const;
    bool operator==(const LinkedList<T>& other) const;
    LinkedList<T>& operator=(const LinkedList<T>& other);
};