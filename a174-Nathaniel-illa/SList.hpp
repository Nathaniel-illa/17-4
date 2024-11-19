// SList.hpp
#ifndef SLIST_HPP
#define SLIST_HPP

#include "Students.hpp"
#include <iostream>

class SList {
private:
    // Node structure for the singly linked list
    struct Node {
        Students data;
        Node* next;

        Node(const Students& student) : data(student), next(nullptr) {}
    };

    Node* head;
    int listSize;

public:
    // Constructor
    SList() : head(nullptr), listSize(0) {}

    // Destructor to clean up memory
    ~SList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Add a student in ascending order based on the sum of grades
    void addStudent(const Students& student) {
        Node* newNode = new Node(student);
        if (head == nullptr || student.getSum() < head->data.getSum()) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr && current->next->data.getSum() <= student.getSum()) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        listSize++;
    }

    // Delete a student by ID
    void deleteStudent(int ID) {
        if (head == nullptr)
            return;

        // If the head needs to be deleted
        if (head->data.getID() == ID) {
            Node* temp = head;
            head = head->next;
            delete temp;
            listSize--;
            return;
        }

        // Search for the node to delete
        Node* current = head;
        while (current->next != nullptr && current->next->data.getID() != ID) {
            current = current->next;
        }

        // If the student was found, delete it
        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            listSize--;
        }
    }

    // Get the size of the list
    int size() const {
        return listSize;
    }

    // Overload the subscript operator to access students by index
    Students& operator[](int index) {
        if (index < 0 || index >= listSize) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = head;
        int currentIndex = 0;
        while (currentIndex < index) {
            current = current->next;
            currentIndex++;
        }
        return current->data;
    }

    const Students& operator[](int index) const {
        if (index < 0 || index >= listSize) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = head;
        int currentIndex = 0;
        while (currentIndex < index) {
            current = current->next;
            currentIndex++;
        }
        return current->data;
    }

    // Print all students in the list
    void printStudents() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }
};

#endif // SLIST_HPP