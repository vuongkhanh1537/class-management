#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "main.h"
using namespace std;

class Student {
public:
    Student() {}
    Student(string name, string id, string email) : name(name), id(id), email(email) {}

    string getName() {
        return name;
    }

    string getId() {
        return id;
    }

    string getEmail() {
        return email;
    }

    void enrollCourse(string course_name, string course_ID) {
        enrolledCourses_name.push_back(course_name);
        enrolledCourses_ID.push_back(course_ID);
    }

    void printCourse() {
        for (int i = 0; i < enrolledCourses_ID.size(); i++) {
            cout << enrolledCourses_name[i] << " - " << enrolledCourses_ID[i] << "\n";
        }
    }

private:
    string name;
    string id;
    string email;
    vector<string> enrolledCourses_ID;
    vector<string> enrolledCourses_name;
};

class StudentList {
public:
    StudentList() {}
    void addStudent(Student* student) {
        students.push_back(student);
    }

    void removeStudent(string id) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i]->getId() == id) {
                students.erase(students.begin() + i);
                break;
            }
        }
    }

    Student* getStudent(string student_info) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i]->getName() == student_info || students[i]->getId() == student_info ) {
                return students[i];
            }
        }
        return NULL;
    }

    void printStudents() {
        if (students.empty()) {
            cout << "None of student.\n";
            return;
        }
        for (int i = 0; i < students.size(); i++) {
            cout << "Name: " << students[i]->getName() << endl;
            cout << "ID: " << students[i]->getId() << endl;
        }
    }

private:
    vector<Student*> students;
};

#endif // STUDENT_H