// Students.hpp
#ifndef STUDENTS_HPP
#define STUDENTS_HPP

#include <string>
#include <vector>
#include <numeric>
#include <iostream>

class Students {
private:
    std::string name;
    int ID;
    std::vector<int> grades;

public:
    //Constructor to initialize the student's attributes
    Students(const std::string& name, int ID, const std::vector<int>& grades)
        : name(name), ID(ID), grades(grades) {}

    // Getter for the student's name
    std::string getName() const {
        return name;
    }
    // Getter for the student's ID
    int getID() const {
        return ID;
    }
    // Getter for the student's grades
    const std::vector<int>& getGrades() const {
        return grades;
    }

    // Calculate the sum of grades or Method to calculate the total sum of the student's grades
    int getSum() const {
        return std::accumulate(grades.begin(), grades.end(), 0);
    }

    // Overload the output operator (<<) for printing a student's details
    friend std::ostream& operator<<(std::ostream& os, const Students& student) {
        os << "Name: " << student.name << ", ID: " << student.ID << ", Grades: [";
        for (size_t i = 0; i < student.grades.size(); ++i) {
            os << student.grades[i];
            if (i != student.grades.size() - 1)
                os << ", ";
        }
        os << "], Total: " << student.getSum();
        return os;
    }

   // Overloading the less-than operator (<) for comparing students based on total grades
    bool operator<(const Students& other) const {
        return this->getSum() < other.getSum();
    }
};

#endif // STUDENTS_HPP