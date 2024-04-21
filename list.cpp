#include "list.h"
#include "ListException.h"


template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::push_back(T newData) {
    if (!head) {
        head = new Node(newData);
        tail = head;
        size++;
        return;
    }
    Node* current = new Node(newData);
    tail->next = current;
    tail = current;
    size++;
}

template <typename T>
void LinkedList<T>::insertAt(int index, const T& newData) {
    if (index < 0) {
        throw ListException("Index out of range");
    }
    if (index == 0) {
        Node* newNode = new Node(newData);
        newNode->next = head;
        head = newNode;
        if (!tail) {
            tail = head;
        }
        size++;
        return;
    }
    Node* current = head;
    for (int i = 0; i < index - 1; ++i) {
        if (!current) {
            throw ListException("Index out of range");
        }
        current = current->next;
    }
    if (!current) {
        throw ListException("Index out of range");
    }
    Node* newNode = new Node(newData);
    newNode->next = current->next;
    current->next = newNode;
    if (!newNode->next) {
        tail = newNode;
    }
    size++;
}

template <typename T>
void LinkedList<T>::removeAt(int index) {
    if (index < 0) {
        throw ListException("Index out of range");
    }
    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head) {
            tail = nullptr;
        }
        size--;
        return;
    }
    Node* current = head;
    Node* prev = nullptr;
    for (int i = 0; i < index; ++i) {
        if (!current) {
            throw ListException("Index out of range");
        }
        prev = current;
        current = current->next;
    }
    if (!current) {
        throw ListException("Index out of range");
    }
    prev->next = current->next;
    if (!prev->next) {
        tail = prev;
    }
    size--;
    delete current;
}

template <typename T>
void LinkedList<T>::removeVal(T value) {
    Node* current = head;
    Node* prev = nullptr;
    while (current) {
        if (current->data == value) {
            if (prev) {
                prev->next = current->next;
            }
            else {
                head = current->next;
            }
            size--;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
    throw ListException("Value not found in the list");
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::findAt(int index) const {
    if (index < 0) {
        return nullptr;
    }
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        if (!current) {
            return nullptr;
        }
        current = current->next;
    }
    return current;
}

template <typename T>
T LinkedList<T>::getVal(LinkedList<T>::Node* cur) {
    if (cur == nullptr) {
        throw ListException("No such element in list");
    }
    return cur->data;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::begin() const {
    return head;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::end() const {
    return tail;
}

template <typename T>
int LinkedList<T>::length() {
    return size;
}

template <typename T>
void LinkedList<T>::print() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& other) const {
    if (size != other.size) {
        return false;
    }

    Node* current1 = head;
    Node* current2 = other.head;

    while (current1 && current2) {
        if (current1->data != current2->data) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return true;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
    if (this == &other) {
        return *this;
    }

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;

    Node* current = other.head;
    while (current) {
        push_back(current->data);
        current = current->next;
    }

    return *this;
}

